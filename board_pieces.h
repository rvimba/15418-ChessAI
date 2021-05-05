// enum Color {None = 0, White, Black};
// enum PieceType {Pawn = 0, Rook, Bishop, Knight, Queen, King};
// class Piece {
// private:
//     static const char charPieceType_ = ' ';
// 	static const PieceType pieceType_ = PieceType::Pawn;
// public:
// 	Color color;
// 	Piece(Color color);
// 	virtual char getSymbol();
//     virtual Color getPieceColor();
// 	virtual PieceType getPieceType();
//     virtual void setPieceType(PieceType type);
// };

// class Chessboard
// {
// 	private:
//         // Allocated pieces for the chessboard.
// 		Piece* WhitePieces_[16];
// 		Piece* BlackPieces_[16];

//         // The board will be made up of Piece pointers.
// 		Piece* board_[8][8];
//         Color aiColor_;

// 		void initializeBoard();
// 		void clearBoard();
// 		void setPiece(int row, int col, Piece *piece);
// 		Piece* movePiece(int oldrow, int oldcol, int newrow, int newcol);

// 	public:
// 	    void setBoardUp();
// 		void init();
// 		bool isWhite();

//         Piece* pieceAt(int row, int col);
// 		Piece* makeMove(move_t move);

// 		Chessboard* copy();
// 		void freeBoard();
// 	    Chessboard(Color aiColor);
// };