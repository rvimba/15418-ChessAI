#pragma once
#include <vector>

// #include "chess_pieces.h"
// #include "chessboard.h"
#include "piece_moves.h"

// #ifndef MINIMAX
// #define MINIMAX

std::vector<move_t> allMoves(Chessboard* board, Color color);

float evaluateBoard(Chessboard* board, Color color, bool maximizing_player);

move_t minimaxProcess(Chessboard* board, move_t move, int depth, bool maximizing_player, Color color);

// #endif