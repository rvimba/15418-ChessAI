#include "board_pieces.h"
#include <vector>
using namespace std;

typedef __INT8_TYPE__ int8_t;

struct move_header {
    int8_t rank_source;
    int8_t file_source;
    int8_t rank_dest;
    int8_t file_dest;
};
typedef struct move_header move_t;
// typedef move_struct* move_t;

move_t createMove(int8_t r_source, int8_t f_source, int8_t r_dest, int8_t f_dest);

vector<move_t> pawnMoves(Chessboard b, Color color, int8_t rank, int8_t file);
vector<move_t> knightMoves(Chessboard b, Color color, int8_t rank, int8_t file);
vector<move_t> bishopMoves(Chessboard b, Color color, int8_t rank, int8_t file);
vector<move_t> rookMoves(Chessboard b, Color color, int8_t rank, int8_t file);
vector<move_t> queekMoves(Chessboard b, Color color, int8_t rank, int8_t file);
vector<move_t> kingMoves(Chessboard b, Color color, int8_t rank, int8_t file);

void checkPawnMoves(Chessboard b, vector<move_t> moves, Color color, int8_t rank, int8_t file, Piece *forward_1, 
                    Piece *forward_2, Piece *left, Piece *right, int8_t new_rank_1, int8_t new_rank_2);

void checkKnightMove(Chessboard b, vector<move_t> moves, Color color, 
                    int8_t rank, int8_t file, int8_t new_rank, int8_t new_file);