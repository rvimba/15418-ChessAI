#include "chess_pieces.h"

Piece::Piece(Color color) {
	Piece::color = color;
}

char Piece::getSymbol() {
	return Piece::charPieceType_;
}

Color Piece::getPieceColor() {
	return Piece::color;
}

PieceType Piece::getPieceType() {
	return Piece::pieceType_;
}

void Piece::setPieceType(PieceType type) {
	pieceType_ = type;
    switch (type) {
        case PieceType::Pawn:
            charPieceType_ = 'P';
            break;
        case PieceType::Bishop:
            charPieceType_ = 'B';
            break;
        case PieceType::Knight:
            charPieceType_ = 'N';
            break;
        case PieceType::Rook:
            charPieceType_ = 'R';
            break;
        case PieceType::King:
            charPieceType_ = 'K';
            break;
        case PieceType::Queen:
            charPieceType_ = 'Q';
            break;
        default:
            std::cout << "Error: invalid piece type." << "\n";
    }
}
