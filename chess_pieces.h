

enum class Color {None, White, Black};
enum class PieceType {None, Pawn, Rook, Bishop, Knight, Queen, King};

class Piece {
private:
    static const char charPieceType = ' ';
	static const PieceType pieceType = PieceType::None;
public:
	Color color;
	Piece(Color color);
	virtual char getSymbol();
	virtual PieceType getPieceType();
};
