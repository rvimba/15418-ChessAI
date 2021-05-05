#pragma once
// #include "board_pieces.h" // remove this when we can
#include "chessboard.h"
#include "chess_pieces.h"
#include <vector>

using namespace std;

typedef __INT8_TYPE__ int8_t;

vector<move_t> getPieceMoves(Chessboard board, Piece *p, int8_t rank, int8_t file);

// vector<move_t> pawnMoves(Chessboard b, Color color, int8_t rank, int8_t file);
// vector<move_t> knightMoves(Chessboard b, Color color, int8_t rank, int8_t file);
// vector<move_t> bishopMoves(Chessboard b, Color color, int8_t rank, int8_t file);
// vector<move_t> rookMoves(Chessboard b, Color color, int8_t rank, int8_t file);
// vector<move_t> queekMoves(Chessboard b, Color color, int8_t rank, int8_t file);
// vector<move_t> kingMoves(Chessboard b, Color color, int8_t rank, int8_t file);

// void checkPawnMoves(Chessboard b, vector<move_t> moves, Color color, int8_t rank, int8_t file, Piece *forward_1, 
//                     Piece *forward_2, Piece *left, Piece *right, int8_t new_rank_1, int8_t new_rank_2);

// void checkKnightMove(Chessboard b, vector<move_t> moves, Color color, 
//                     int8_t rank, int8_t file, int8_t new_rank, int8_t new_file);

// move_t createMove(int8_t r_source, int8_t f_source, int8_t r_dest, int8_t f_dest);

move_t createMove(int8_t r_source, int8_t f_source, int8_t r_dest, int8_t f_dest) {
    move_t new_move;
    new_move.rank_source = r_source;
    new_move.file_source = f_source;
    new_move.rank_dest = r_dest;
    new_move.file_dest = f_dest;
    return new_move;
}

int checkMove(Chessboard b, vector<move_t> moves, Color color, 
                    int8_t rank, int8_t file, int8_t new_rank, int8_t new_file) {
    
    if (new_rank < 0 || new_rank > 7 || new_file < 0 || new_file > 7) {
        return 0;
    }

    Piece *check_square = b.pieceAt(new_rank, new_file);
    if (check_square == nullptr) {
        moves.push_back(createMove(rank, file, new_rank, new_file));
        return 1;
    } else if (check_square->getPieceColor() != color) {
        moves.push_back(createMove(rank, file, new_rank, new_file));
        return 0;
    }
    return 0; // TODO: is it 
}