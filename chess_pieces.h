#pragma once
#include <iostream>

enum class Color {None, White, Black};
enum class PieceType {None, Pawn, Rook, Bishop, Knight, Queen, King};


class Piece {
private:
    char charPieceType_ = ' ';
	PieceType pieceType_ = PieceType::None;
public:
	Color color;
	Piece(Color color, PieceType type);
	~Piece();
	char getSymbol();
	Color getPieceColor();
	PieceType getPieceType();
    void setPieceType(PieceType type);

	Piece* copy();
};

