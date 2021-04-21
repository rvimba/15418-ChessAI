#include <vector>


vector<move_t> allMoves(Chessboard board, Color color);

scored_move_t evaluateBoard(Chessboard board, Color color, move_t move);

scored_move_t minimaxProcess(Chessboard board, move_t move, 
                            int depth, bool maximizing_player, Color color);
