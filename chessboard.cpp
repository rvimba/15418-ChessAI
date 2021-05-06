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


// void Chessboard::setBoardUp() {

//     // Start by clearing the Piece pointers.
//     for (int row = 0; row < 8; row++) {
//         for (int col = 0; col < 8; col++) {
//             board_[row][col] = nullptr;
//             // Setup white and black pawns on 0th and 6th rows.
//             if (row == 1) { 
//                 board_[row][col] = WhitePieces_[col];
//             } else if (row == 6) {
//                 board_[row][col] = BlackPieces_[col];
//             } 
//         }
//     }

//     // Rooks
//     board_[0][0] = WhitePieces_[12];
//     board_[0][7] = WhitePieces_[13];
//     board_[7][0] = BlackPieces_[12];
//     board_[7][7] = BlackPieces_[13];

//     // Knights
//     board_[0][1] = WhitePieces_[10];
//     board_[0][6] = WhitePieces_[11];
//     board_[7][1] = BlackPieces_[10];
//     board_[7][6] = BlackPieces_[11];

//     // Bishops
//     board_[0][2] = WhitePieces_[8];
//     board_[0][5] = WhitePieces_[9];
//     board_[7][2] = BlackPieces_[8];
//     board_[7][5] = BlackPieces_[9];

//     // King & Queen
//     board_[0][3] = WhitePieces_[15]; // Queen
//     board_[0][4] = WhitePieces_[14]; // King
//     board_[7][3] = BlackPieces_[15]; // Q
//     board_[7][4] = BlackPieces_[14]; // K
// }

// void Chessboard::initializeBoard() {

//     // Allocate and set all pieces (white and black).
//     for (int i = 0; i < 16; i++) {
//         WhitePieces_[i] = new Piece(Color::White);
//         BlackPieces_[i] = new Piece(Color::Black);

//         if (i < 8) {
//             WhitePieces_[i]->setPieceType(PieceType::Pawn);
//             BlackPieces_[i]->setPieceType(PieceType::Pawn);
//         } else if (i < 10) {
//             WhitePieces_[i]->setPieceType(PieceType::Bishop);
//             BlackPieces_[i]->setPieceType(PieceType::Bishop);
//         } else if (i < 12) {
//             WhitePieces_[i]->setPieceType(PieceType::Knight);
//             BlackPieces_[i]->setPieceType(PieceType::Knight);
//         } else if (i < 14) {
//             WhitePieces_[i]->setPieceType(PieceType::Rook);
//             BlackPieces_[i]->setPieceType(PieceType::Rook);
//         } else if (i == 14) {
//             WhitePieces_[i]->setPieceType(PieceType::King);
//             BlackPieces_[i]->setPieceType(PieceType::King);
//         } else {
//             WhitePieces_[i]->setPieceType(PieceType::Queen);
//             BlackPieces_[i]->setPieceType(PieceType::Queen);
//         }
//     }

//     setBoardUp();
// }

bool Chessboard::isWhite()
{
	return (aiColor_ == Color::White);
}

void Chessboard::setPiece(int row, int col, PieceType newType)
{
    board_[row][col]->setPieceType(newType);
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
    // TODO(fleyva): account for special game instances (aka promoting pawn).

	return movePiece(move.rank_source, move.file_source, move.rank_dest, move.file_dest);
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
	// TODO(Fleyva): add copy fxn
    Chessboard *b = new Chessboard(aiColor_);
    for (int i  = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* p = board_[i][j];
            if (p != nullptr) {
                b->board_[i][j] = p->copy();
            }
        }
    }
    return b;
}

void Chessboard::freeBoard()
{
    // for (int i = 0; i < 16; i++) {
    //     delete WhitePieces_[i];
    //     delete BlackPieces_[i];
    // }
    for (int i  = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board_[i][j] != nullptr) {
                delete board_[i][j];
            }
        }
    }
}

Chessboard::Chessboard(Color aiColor) {
    aiColor_ = aiColor;
    setupBoard();
}
