#include "chess_pieces.h"

class Chessboard
{
	private:
		Piece* White[8];
		Piece* Black[8];

        // The board will be made up of Piece pointers.
		Piece* board[8][8];

		void initializeBoard(); // TODO(fleyva): implement
		void clearBoard();
		Piece* set(int row, int col, int name, int color);
		Piece* move_piece(int oldrow, int oldcol, int newrow, int newcol);

	public:
		int is_white();
	    void resetBoard();
		void init();
		Piece* set_piece(int row, int col, int name, int color);
		Piece* move(int oldrow, int oldcol, int newrow, int newcol);
		ChessBoard* copy();
		void free_board();
	    ChessBoard();
};