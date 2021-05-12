#include "minimax.h"

using namespace std;

int number_of_moves = 0;

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
            }
        }
    }
    return all_moves;
}

float evaluateBoard(Chessboard* board, Color color, bool maximizing_player) {
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
    
    // POSITIONAL SCORES MAY NOT BE AS IMPORTANT PAST EARLY GAME
    Color opponent_color = (color == Color::White) ? Color::Black : Color::White;
    score += allMoves(board, color).size() * 10;
    opponent_score += allMoves(board, opponent_color).size() * 10;
    if (maximizing_player) {
        return (float)(score - opponent_score);
    }
    return (float)(opponent_score - score);
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
        float score = evaluateBoard(board, color, maximizing_player); 
        move.score = score;
        return move;
    }

    move_t best_move;
    if (maximizing_player) {
        best_move.score = INT_MIN;
    } else {
        best_move.score = INT_MAX;
    }

    vector<move_t> all_moves = allMoves(board, color);
    if (depth == 1) {
        number_of_moves += all_moves.size();
    }

    for (vector<move_t>::iterator it = all_moves.begin(); it != all_moves.end(); it++) {

        Chessboard* adjusted_board = board->copy();
        move_t new_move = createMove(it->rank_source, it->file_source, it->rank_dest, it->file_dest);
        adjusted_board->makeMove(new_move);
        Color switch_color = (color == Color::White) ? Color::Black : Color::White;

        move_t curr_move = minimaxProcess(adjusted_board, new_move, depth-1, !maximizing_player, switch_color);

        // if (depth == 4) {
        //     char file_source = new_move.file_source + 97;
        //     char rank_source = new_move.rank_source + 49;
        //     char file_dest = new_move.file_dest + 97;
        //     char rank_dest = new_move.rank_dest + 49;

        //     cout << file_source << rank_source << file_dest << rank_dest << ": " << curr_move.score << endl;
        // }

        if (maximizing_player && (curr_move.score > best_move.score)) {
            best_move = new_move;
            best_move.score = curr_move.score;
        } else if (!maximizing_player && (curr_move.score < best_move.score)) {
            best_move = new_move;
            best_move.score = curr_move.score;
        }
    }
    
    return best_move;
}


move_t ABMinMax(Chessboard* board, move_t move, short int depth, Color color) {
	return ABMaxMove(board, move, depth, (int)0, (int)0, color);
}

move_t ABMaxMove(Chessboard* board, move_t move, short int depth, int a, int b, Color color) {

    move_t best_move;
    move_t best_real_move;
    bool is_best_move_set = false;

	int alpha = a, beta = b;

	if (depth == 0) {//if depth limit is reached
        cout << "In the base case baby." << endl;
        float score = evaluateBoard(board, color, true); 
        move.score = score;
        return move;
	} else {
        vector<move_t> all_moves = allMoves(board, color);
        number_of_moves += all_moves.size();

		for (vector<move_t>::iterator it = all_moves.begin(); it != all_moves.end(); it++) {
            Chessboard* adjusted_board = board->copy();
            move_t new_move = createMove(it->rank_source, it->file_source, it->rank_dest, it->file_dest);
            adjusted_board->makeMove(new_move);
			
            move_t curr_move = ABMinMove(adjusted_board, new_move, depth-1, alpha, beta, color);

            if (depth == 2) {
                char file_source = curr_move.file_source + 97;
                char rank_source = curr_move.rank_source + 49;
                char file_dest = curr_move.file_dest + 97;
                char rank_dest = curr_move.rank_dest + 49;

                cout << file_source << rank_source << file_dest << rank_dest << ": " << curr_move.score << endl;
            }
			
            if (!is_best_move_set || curr_move.score > best_move.score) {
				best_move = curr_move;
                best_real_move = new_move;
                alpha = curr_move.score;
                is_best_move_set = true;
			}
            
			if(beta > alpha){
                cout << "BEta > alpha" << endl;
				return best_real_move;
			}
		}
		return best_real_move;
	}
}

move_t ABMinMove(Chessboard* board, move_t move, short int depth, int a, int b, Color color) {
	
    move_t best_move;
    move_t best_real_move;
    bool is_best_move_set = false;

	int alpha = a, beta = b;

	if (depth == 0) {
        float score = evaluateBoard(board, color, false); 
        move.score = score;
        return move;
	} else {
        vector<move_t> all_moves = allMoves(board, color);
        for (vector<move_t>::iterator it = all_moves.begin(); it != all_moves.end(); it++) {
            Chessboard* adjusted_board = board->copy();
            move_t new_move = createMove(it->rank_source, it->file_source, it->rank_dest, it->file_dest);
            adjusted_board->makeMove(new_move);
			
			move_t curr_move = ABMaxMove(adjusted_board, new_move, depth-1, alpha, beta, color);
			
            if (!is_best_move_set || curr_move.score < best_move.score) {
				best_move = curr_move;
                best_real_move = new_move;
                beta = curr_move.score;
                is_best_move_set = true;
			}
            
			if (beta < alpha){
				return best_real_move;
			}
		}
		return best_real_move;
	}
}

move_t findNextMove(Chessboard *board, move_t move, int depth, bool maximizing_player, Color color) {
    move_t best_move = minimaxProcess(board, move, depth, maximizing_player, color);

    cout << "Total number of moves : " << number_of_moves << endl;
    return best_move;
}
