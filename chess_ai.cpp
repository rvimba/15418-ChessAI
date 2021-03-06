#include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
#include <climits>
// #include "chess_pieces.h"
// #include "chessboard.h"
// #include "piece_moves.h"
#include "minimax.h"
// #include "board_pieces.h"


#include <chrono>
using namespace std::chrono;

/************************** Helper Functions ******************************/

// midgame #1 deepblue (white) vs Kasparov (black) board
const char board1[] = {   '-','-','R','-','-','-','K','-',
                    '-','-','-','-','-','P','P','-',
                    'P','P','-','-','-','-','-','P',
                    '-','-','-','p','-','-','-','-',
                    '-','N','Q','-','-','p','-','-',
                    '-','-','n','-','-','q','-','-',
                    '-','p','-','-','-','p','-','p',
                    '-','-','-','-','-','-','r','k'};


const char startBoard[] = {'R','N','B','Q','K','B','N','R',
                    'P','P','P','P','P','P','P','P',
                    '-','-','-','-','-','-','-','-',
                    '-','-','-','-','-','-','-','-',
                    '-','-','-','-','-','-','-','-',
                    '-','-','-','-','-','-','-','-',
                    'p','p','p','p','p','p','p','p',
                    'r','n','b','q','k','b','n','r'};

// char getTestBoard (int boardNumber)[] {
//     switch (boardNumber) {
//         case 1: 
//             return board1;
//         case 2: 
//             return 0;
//         case 3:
//             return 0;
//         default:
//             return startBoard;
//     }
// }

move_t createUserMove(string source_dest) {
    move_t new_move;

    new_move.file_source = (int)(source_dest[0]) - 97;
    new_move.rank_source = (int)(source_dest[1]) - 49;
    new_move.file_dest = (int)(source_dest[2]) - 97;
    new_move.rank_dest = int(source_dest[3]) - 49;
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
    string source_dest;
    
    // cout << "Enter current rank and file of piece to move" << endl;
    // cin >> piece_source;
    // cout << "Enter destination rank and file for piece" << endl;
    // cin >> piece_dest;
    // example: a2a3
    cout << "Enter rank/file source, rank/file destination: ";
    cin >> source_dest;

    move_t move = createUserMove(source_dest);
    if (move.score == 0) {
        // invalid move
        cout << "invalid move. Try again" << endl;
        nextMoveUser(board, color);
        return;
    }
    board->makeMove(move);
}

int translateFile(char file) {
    return (int)file - 96;
}

/*****************************************************************************/

void nextMoveAI(Chessboard *board, Color color) {
    // use minimax to find the best move
    // update board
    int depth = 4;
    move_t move = createMove(0,0,0,0);
    cout << "passed createMove" << endl;
    move.score = INT_MIN;
    
    auto start = high_resolution_clock::now();
    move_t best_move = findNextMove(board, move, depth, true, color);
    auto stop = high_resolution_clock::now();

    auto durationOfFunction = duration_cast<microseconds>(stop - start);
    cout << "minimax duration: " << durationOfFunction.count() << "ms at depth: " << depth << endl;

    // move_t best_move = ABMinMax(board, move, depth, color);

    char file_source = best_move.file_source + 97;
    char rank_source = best_move.rank_source + 49;
    char file_dest = best_move.file_dest + 97;
    char rank_dest = best_move.rank_dest + 49;

    cout << "move made: " << file_source << rank_source << file_dest << rank_dest << ": " << best_move.score << endl;
    board->makeMove(best_move);
    // return board;
}

void runTestBoard() {

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

    char buffer[256];
    std::cout << "Choose test board number [1, 10]\n";
    std::cin >> buffer;
    int boardNumber = atoi(buffer);
    
    Chessboard* b;
    if (boardNumber == 1) {
        b = new Chessboard(ai_color, board1);
    } else {
        b = new Chessboard(ai_color, startBoard);
    }
    
    // odd turn   ==> user moves
    // even turns ==> ai moves
    b->printBoard();

    std::string whoseTurn = " ";
    std::cout << "Is it your turn? yes/no\n";
    std::cin >> whoseTurn;
    
    int turn = (whoseTurn == "yes") ? 1 : 0;

    while (true) {
        if (turn & 0x1) {
            nextMoveUser(b, player_color);
        } else {
            nextMoveAI(b, ai_color);
        }
        if (!b->printBoard()) { // printBoard returns true if 2 kings alive
            string whoWon = (turn & 0x1) ? "User Won" : "AI Won";
            cout << "Game Over: " << whoWon << endl;
            return;
        }
        turn++;
    }
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

    std::string test = " ";
    std::cout << "Start from existing board ?\n";
    std::cin >> test;

    if (test == "yes") {
        runTestBoard();
        return 0;
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
    
    // odd turn   ==> user moves
    // even turns ==> ai moves
    int turn = 0;

    if (ai_color != Color::White) {
        turn++;
    }
    b->printBoard();
    
    while (true) {
        if (turn & 0x1) {
            nextMoveUser(b, player_color);
        } else {
            nextMoveAI(b, ai_color);
        }
        if (!b->printBoard()) { // printBoard returns true if 2 kings alive
            string whoWon = (turn & 0x1) ? "User Won" : "AI Won";
            cout << "Game Over: " << whoWon << endl;
            return 0;
        }
        turn++;
    }

    return 0;
}

