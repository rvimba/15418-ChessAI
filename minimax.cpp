#include "minimax.h"

using namespace std;

vector<move_t> allMoves(Chessboard* board, Color color) {
    // - vector<move_t> result
    // - for each square on the board
    //      - if a piece on our side exists in the square
    //          - append all possible moves from that piece to our result vector
    // return result
    vector<move_t> all_moves;

    for (int8_t rank = 0; rank < 8; rank++) {
        for (int8_t file = 0; file < 8; file++) {
            if (board == nullptr) {
                cout << "board is nullptr" << endl;
            }
            Piece *piece = board->pieceAt(rank, file);
            
            if (piece != nullptr && piece->getPieceColor() == color) {
                vector<move_t> piece_moves = getPieceMoves(board, piece, rank, file);
                for (vector<move_t>::iterator it = piece_moves.begin(); it != piece_moves.end(); it++) {
                    all_moves.push_back(*it);
                }
                // all_moves.insert(end(all_moves), begin(piece_moves), end(piece_moves));
            }
        }
    }
    cout << "number of moves: " << all_moves.size() << endl;
    return all_moves;
}

float evaluateBoard(Chessboard* board, Color color) {
    int score = 0;
    int opponent_score = 0;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece* p = board->pieceAt(row, col);
            if (p != nullptr) {
                if (p->getPieceColor() == color) {
                    score += p->getValue();
                } else {
                    opponent_score += p->getValue();
                }
            }
        }
    }
    cout << "totalled piece scores" << endl;
    Color opponent_color = (color == Color::White) ? Color::Black : Color::White;
    cout << "got op color" << endl;
    score += allMoves(board, color).size() * 10;
    cout << "our mobility score" << endl;
    opponent_score += allMoves(board, opponent_color).size() * 10;
    cout << "added piece mobility scores" << endl;
    return (float)(score - opponent_score);
}

move_t minimaxProcess(Chessboard *board, move_t move, int depth, bool maximizing_player, Color color) {
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
        cout << "In the base case baby." << endl;
        float score = evaluateBoard(board, color); 
        move.score = score;
        return move;
    }

    move_t best_move = move;
    vector<move_t> all_moves = allMoves(board, color);
    cout << "past allMoves" << endl;

    for (vector<move_t>::iterator it = all_moves.begin(); it != all_moves.end(); it++) {

        Chessboard* adjusted_board = board->copy();
        move_t new_move = createMove(it->rank_source, it->file_source, it->rank_dest, it->file_dest);
        adjusted_board->makeMove(new_move);

        move_t curr_move = minimaxProcess(adjusted_board, new_move, depth-1, !maximizing_player, color);
        cout << "retured from base base" << endl;
        if (maximizing_player && (curr_move.score > best_move.score)) {
            best_move = curr_move;
        } else if (!maximizing_player && (curr_move.score < best_move.score)) {
            best_move = curr_move;
        }
    }

    return best_move;
}