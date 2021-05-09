#include "chessboard.h"

void Chessboard::setupBoard() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            board_[rank][file] = nullptr;
            // Setup white and black pawns on 0th and 6th rows.
            if (rank == 1) { 
                board_[rank][file] = new Piece(Color::White, PieceType::Pawn);
            } else if (rank == 6) {
                board_[rank][file] = new Piece(Color::Black, PieceType::Pawn);
            } 
        }
    }
    // Rooks
    board_[0][0] = new Piece(Color::White, PieceType::Rook);
    board_[0][7] = new Piece(Color::White, PieceType::Rook);
    board_[7][0] = new Piece(Color::Black, PieceType::Rook);
    board_[7][7] = new Piece(Color::Black, PieceType::Rook);

    // Knights
    board_[0][1] = new Piece(Color::White, PieceType::Knight);
    board_[0][6] = new Piece(Color::White, PieceType::Knight);
    board_[7][1] = new Piece(Color::Black, PieceType::Knight);
    board_[7][6] = new Piece(Color::Black, PieceType::Knight);

    // Bishops
    board_[0][2] = new Piece(Color::White, PieceType::Bishop);
    board_[0][5] = new Piece(Color::White, PieceType::Bishop);
    board_[7][2] = new Piece(Color::Black, PieceType::Bishop);
    board_[7][5] = new Piece(Color::Black, PieceType::Bishop);

    // King & Queen
    board_[0][3] = new Piece(Color::White, PieceType::Queen); // Queen
    board_[0][4] = new Piece(Color::White, PieceType::King); // King
    board_[7][3] = new Piece(Color::Black, PieceType::Queen); // Q
    board_[7][4] = new Piece(Color::Black, PieceType::King); // K

}

bool Chessboard::isWhite()
{
	return (aiColor_ == Color::White);
}

void Chessboard::setPiece(int row, int col, PieceType newType, Color color)
{
    board_[row][col]->setPieceType(newType, color);
};

Piece* Chessboard::movePiece(int oldRow, int oldCol, int newRow, int newCol)
{
    // Check if there is a piece in the old indexes.
    if (pieceAt(oldRow, oldCol) == nullptr) return nullptr;

    // Check range of moves.
    if (oldRow < 0 || 8 <= oldRow) return nullptr;
    if (oldCol < 0 || 8 <= oldCol) return nullptr;
    if (newRow < 0 || 8 <= newRow) return nullptr;
    if (newCol < 0 || 8 <= newCol) return nullptr;

    board_[newRow][newCol] = board_[oldRow][oldCol];
    board_[oldRow][oldCol] = nullptr;
    return board_[newRow][newCol];
}

Piece* Chessboard::makeMove(move_t move)
{
    Piece* p = movePiece(move.rank_source, move.file_source, move.rank_dest, move.file_dest);
    if ((move.rank_dest == 7) && (p->getPieceType() == PieceType::Pawn) && 
        (p->getPieceColor() == Color::White)) {

        setPiece(move.rank_dest, move.file_dest, PieceType::Queen, Color::White);

    } else if ((move.rank_dest == 0) && (p->getPieceType() == PieceType::Pawn) && 
        (p->getPieceColor() == Color::Black)) {

        setPiece(move.rank_dest, move.file_dest, PieceType::Queen, Color::Black);
    }
    return pieceAt(move.rank_dest, move.file_dest);
}

Piece* Chessboard::pieceAt(int row, int col) {
    return board_[row][col];
}

// void Chessboard::init()
// {
// 	initializeBoard();
// }

Chessboard* Chessboard::copy()
{
    Chessboard *b = new Chessboard(aiColor_);
    for (int i  = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* p = board_[i][j];
            if (p != nullptr) {
                b->board_[i][j] = p->copy();
            } else {
                b->board_[i][j] = nullptr;
            }
        }
    }
    return b;
}

void Chessboard::freeBoard()
{
    for (int i  = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board_[i][j] != nullptr) {
                delete board_[i][j];
            }
        }
    }
}

void Chessboard::printBoard() {
    string board_rep = "";
    board_rep += "    A B C D E F G H \n";
    board_rep += "    _______________ \n";

    for (int i = 7; i >= 0; --i) {
        board_rep += to_string(i + 1) + " | "; 
        for (int j = 0; j < 8; ++j) {
            Piece* p = pieceAt(i, j);
            if (p == nullptr) {
                board_rep += "- ";
            } else {
                board_rep += p->getSymbol() + " ";
            }
        }
        board_rep += "|\n";
        // cout << next_line << endl;
    }
    board_rep += "    _______________\n";
    // cout << "    _______________" << endl;
    cout << board_rep << endl;
}

Chessboard::Chessboard(Color aiColor) {
    aiColor_ = aiColor;
    setupBoard();
}
