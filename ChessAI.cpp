#include <iostream>
#include "minimax.h"
#include "piece_moves.h"
#include "board_pieces.h"

using namespace std;

int main(int argc, char** argv) {
    // parse arguments determining whether player wants to be white or black
        // initialize chessboard
        // while (game not finished)
    //      - player makes move (user input) or AI makes move based on turn
    // return winner
}

Chessboard nextMoveAI(Chessboard board, Color color) {
    // use minimax to find the best move
    // update board
    int depth = 2;
    move_t move = createMove(0,0,0,0);
    move.score = INT_MIN;
    move_t best_move = minimaxProcess(board, move, depth, true, color);
    board.makeMove(best_move);
    return board;
}

Chessboard nextMoveUser(Chessboard board, Color color) {
    // ask for user input to move piece
    // current rank and file of source, new rank and file of destination
    // verify valid move
    // update board 
    string piece_source, piece_dest;
    
    cout << "Enter current rank and file of piece to move" << endl;
    cin >> piece_source;
    cout << "Enter destination rank and file for piece" << endl;
    cin >> piece_dest;

    move_t move = createUserMove(piece_source, piece_dest);
    if (move.score == 0) {
        // invalid move
        cout << "invalid move. Try again" << endl;
        return nextMoveUser(board, color);
    }
    board.makeMove(move);
    return board;
}

move_t createUserMove(string piece_source, string piece_dest) {
    move_t new_move;

    new_move.file_source = (int)(piece_source[0]) - 97;
    new_move.rank_source = (int)(piece_source[1]) - 49;
    new_move.file_dest = (int)(piece_dest[0]) - 97;
    new_move.rank_dest = int(piece_dest[1]) - 49;
    new_move.score = 1;
    
    if (new_move.file_source < 0 || new_move.file_source > 7 || 
        new_move.rank_source < 0 || new_move.rank_source > 7 ||
        new_move.file_dest < 0 || new_move.file_dest > 7 ||
        new_move.rank_dest < 0 || new_move.rank_dest > 7) {
            new_move.score = 0;
    } 
    return new_move;
}

int translateFile(char file) {
    return (int)file - 96;
}


