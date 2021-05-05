#pragma once 
#include "chess_pieces.h"

struct move_header {
    int8_t rank_source;
    int8_t file_source;
    int8_t rank_dest;
    int8_t file_dest;
    float score;
};
typedef struct move_header move_t;

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
	    Chessboard(Color aiColor);

	    void setBoardUp();
		void init();
		bool isWhite();

        Piece* pieceAt(int row, int col);
		// Piece* makeMove(int oldrow, int oldcol, int newrow, int newcol);
		Piece* makeMove(move_t move); // TODO: Implement this

		Chessboard* copy();
		void freeBoard();
};