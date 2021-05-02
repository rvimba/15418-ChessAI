#include "chess_pieces.h"

class Chessboard
{
	private:
        // Allocated pieces for the chessboard.
		Piece* WhitePieces_[16];
		Piece* BlackPieces_[16];

        // The board will be made up of Piece pointers.
		Piece* board_[8][8];
        Color aiColor_;

		void initializeBoard();
		void clearBoard();
		void setPiece(int row, int col, Piece *piece);
		Piece* movePiece(int oldrow, int oldcol, int newrow, int newcol);

	public:
	    void setBoardUp();
		void init();
		bool isWhite();

        Piece* pieceAt(int row, int col);
		Piece* makeMove(int oldrow, int oldcol, int newrow, int newcol);

		ChessBoard* copy();
		void freeBoard();
	    ChessBoard(Color aiColor);
};