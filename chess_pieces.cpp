#include "chess_pieces.h"

Piece::Piece(Color color) {
	Piece::color = color;
}

char Piece::getSymbol() {
	return Piece::charPieceType;
}

PieceType Piece::getPieceType() {
	return Piece::pieceType;
}
