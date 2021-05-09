#include <iostream>
#include <climits>
// #include "chess_pieces.h"
// #include "chessboard.h"
// #include "piece_moves.h"
#include "minimax.h"
// #include "board_pieces.h"

/************************** Helper Functions ******************************/


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

void nextMoveUser(Chessboard *board, Color color) {
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
        nextMoveUser(board, color);
        return;
    }
    board->makeMove(move);
    return;
}

int translateFile(char file) {
    return (int)file - 96;
}

/*****************************************************************************/

void nextMoveAI(Chessboard *board, Color color) {
    // use minimax to find the best move
    // update board
    int depth = 2;
    move_t move = createMove(0,0,0,0);
    cout << "passed createMove" << endl;
    move.score = INT_MIN;
    move_t best_move = minimaxProcess(board, move, depth, true, color);
    cout << "passed minimax." << endl;
    board->makeMove(best_move);
    // return board;
}

int main(int argc, char** argv) {
    // parse arguments determining whether player wants to be white or black
        // initialize chessboard
        // while (game not finished)
    //      - player makes move (user input) or AI makes move based on turn
    // return winner
    std::cout << "Whatcha know about Amdhal's Gambit baby? " << argc << " arguments:\n";
 
    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    std::string input = " ";
    std::cout << "Choose your color: 'white' or 'black'?\n";
    std::cin >> input;

    // string player_color = argv[2];
    Color ai_color = Color::Black;
    Color player_color = Color::White;
    if (input == "black") {
        // If ai is white, then let it make the first move.
        ai_color = Color::White;        
        player_color = Color::Black;        
    }

    Chessboard* b = new Chessboard(ai_color);
    if (ai_color == Color::White) {
        nextMoveAI(b, ai_color);
    }
    b->printBoard();
    
    while (true) {
        nextMoveUser(b, player_color);
        nextMoveAI(b, ai_color);
        b->printBoard();
    }

    return 0;
}

