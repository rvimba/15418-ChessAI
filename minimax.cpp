#include <vector>
#include "minimax.h"

using namespace std;

vector<move_t> allMoves(int board, int side) {
    // - vector<move_t> result
    // - for each square on the board
    //      - if a piece on our side exists in the square
    //          - append all possible moves from that piece to our result vector
    // return result
}

int minimaxProcess(int board, int move, int depth, bool maximizing_player) {
    // if (depth == 0):
    //      - return move
    // if (maximizing_player):
    //      - best move
    //      - for all possible moves from current position:
    //          - move = minimaxProcess(board + move, move, depth - 1, ~maximizing_player)
    //          - if move > best move: best move = move
    // else:
    //      - best move
    //      - for all possible moves from current position:
    //          - get best move: minimaxProcess(board + move, move, depth - 1, ~maximizing_player)
    //          - if move > best move: best move = move
    // return move

}