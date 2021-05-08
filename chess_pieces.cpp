#include "chess_pieces.h"

Piece::Piece(Color set_color, PieceType set_type) {
	// Piece::color = color;
    color = set_color;
    pieceType_ = set_type;
    setPieceType(set_type, set_color);
}

Piece::~Piece() {
    return;
}

int Piece::getValue() {
	return scoreValue_;
}

string Piece::getSymbol() {
	return charPieceType_;
}

Color Piece::getPieceColor() {
	return color;
}

PieceType Piece::getPieceType() {
	return pieceType_;
}

void Piece::setPieceType(PieceType type, Color color) {
	pieceType_ = type;
    switch (type) {
        case PieceType::Pawn:
            charPieceType_ = (color == Color::White) ? 'P' : 'p';
            scoreValue_ = 100;
            break;
        case PieceType::Bishop:
            charPieceType_ = (color == Color::White) ? 'B' : 'b';
            scoreValue_ = 350;
            break;
        case PieceType::Knight:
            charPieceType_ = (color == Color::White) ? 'N' : 'n';
            scoreValue_ = 350;
            break;
        case PieceType::Rook:
            charPieceType_ = (color == Color::White) ? 'R' : 'r';
            scoreValue_ = 525;
            break;
        case PieceType::King:
            charPieceType_ = (color == Color::White) ? 'K' : 'k';
            scoreValue_ = 10000;
            break;
        case PieceType::Queen:
            charPieceType_ = (color == Color::White) ? 'Q' : 'q';
            scoreValue_ = 1000;
            break;
        default:
            std::cout << "Error: invalid piece type." << "\n";
    }
}

Piece* Piece::copy() {
    return new Piece(getPieceColor(), getPieceType());
}
