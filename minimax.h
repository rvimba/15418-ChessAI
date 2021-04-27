#include <vector>


vector<move_t> allMoves(Chessboard board, Color color);

float evaluateBoard(Chessboard board, Color color, move_t move);

move_t minimaxProcess(Chessboard board, move_t move, int depth, bool maximizing_player, Color color);
