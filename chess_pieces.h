#pragma once
#include <iostream>
using namespace std;

enum class Color {None, White, Black};
enum class PieceType {None, Pawn, Rook, Bishop, Knight, Queen, King};


class Piece {
private:
	int scoreValue_ = 0;
    string charPieceType_ = " ";
	PieceType pieceType_ = PieceType::None;
public:
	Color color;
	Piece(Color color, PieceType type);
	~Piece();

	int getValue();
	string getSymbol();
	Color getPieceColor();
	PieceType getPieceType();
    void setPieceType(PieceType type, Color color);

	Piece* copy();
};

