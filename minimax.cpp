#include <vector>
#include "minimax.h"
#include "piece_moves.h"
#include "board_pieces.h"

using namespace std;

vector<move_t> getPieceMoves(Chessboard board, Piece *p, int8_t rank, int8_t file) {

}

vector<move_t> allMoves(Chessboard board, Color color) {
    // - vector<move_t> result
    // - for each square on the board
    //      - if a piece on our side exists in the square
    //          - append all possible moves from that piece to our result vector
    // return result
    vector<move_t> all_moves;
    for (int8_t rank = 0; rank < 8; rank++) {
        for (int8_t file = 0; file < 8; file++) {
            Piece *piece = board.pieceAt(rank, file);
            if (piece != nullptr && piece->getPieceColor() == color) {
                vector<move_t> piece_moves = getPieceMoves(board, piece, rank, file);
                for (vector<move_t>::iterator it = piece_moves.begin(); it != piece_moves.end(); it++) {
                    all_moves.push_back(*it);
                }
                // all_moves.insert(end(all_moves), begin(piece_moves), end(piece_moves));
            }
        }
    }
    return all_moves;
}

move_t minimaxProcess(int board, move_t move, int depth, bool maximizing_player) {
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

    if (depth == 0) {
        return move;
    }

    if (maximizing_player) {
        move_t best_move;
    }
}