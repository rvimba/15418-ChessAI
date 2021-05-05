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
	Piece(Color color);
	virtual char getSymbol();
	virtual Color getPieceColor();
	virtual PieceType getPieceType();
    virtual void setPieceType(PieceType type);
};

