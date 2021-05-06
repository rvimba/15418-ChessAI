#include "chess_pieces.h"

Piece::Piece(Color set_color, PieceType set_type) {
	// Piece::color = color;
    color = set_color;
    pieceType_ = set_type;
    setPieceType(set_type);
}

Piece::~Piece() {
    return;
}

char Piece::getSymbol() {
	return charPieceType_;
}

Color Piece::getPieceColor() {
	return color;
}

PieceType Piece::getPieceType() {
	return pieceType_;
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

Piece* Piece::copy() {
    return new Piece(getPieceColor(), getPieceType());
}
