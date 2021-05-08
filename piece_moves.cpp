#include <iostream>
#include <vector>
#include "piece_moves.h"

//     0 , 1  , 2  , 3  , 4  , 5  , 6  , 7  
// 0 [w_r, w_n, w_b, w_q, q_k, w_b, w_n, w_r]
// 1 [w_p, w_p, w_p, w_p, w_p, w_p, w_p, w_p]
// 2 [   ,    ,    ,    ,    ,    ,    ,    ]
// 3 [   ,    ,    ,    ,    ,    ,    ,    ]
// 4 [   ,    ,    ,    ,    ,    ,    ,    ]
// 5 [   ,    ,    ,    ,    ,    ,    ,    ]
// 6 [b_p, b_p, b_p, b_p, b_p, b_p, b_p, b_p]
// 7 [b_r, b_n, b_b, b_q, b_k, b_b, b_n, b_r]

void checkPawnMoves(Chessboard* b, std::vector<move_t> moves, Color color, int8_t rank, int8_t file, Piece *forward_1, 
                    Piece *forward_2, Piece *left, Piece *right, int8_t new_rank_1, int8_t new_rank_2) {
    
    int8_t new_file_left = file - 1;
    int8_t new_file_right = file + 1;
    
    if (forward_1 == nullptr) {
        // empty square directly ahead
        moves.push_back(createMove(rank, file, new_rank_1, file));
        
        if ( (rank == 1 && color == Color::White) || (rank == 6 && color == Color::Black) ) {
            if (forward_2 == nullptr) {
                // two empty squares ahead
                moves.push_back(createMove(rank, file, new_rank_2, file));
            } 
        }

        if (left != nullptr && left->getPieceColor() != color) {
            moves.push_back(createMove(rank, file, new_rank_1, new_file_left));
        }
        if (right != nullptr && left->getPieceColor() != color) {
            moves.push_back(createMove(rank, file, new_rank_1, new_file_right));
        }
    }
}

std::vector<move_t> pawnMoves(Chessboard* b, Color color, int8_t rank, int8_t file) {
    std::vector<move_t> moves;
    Piece *forward_1, *forward_2, *left, *right;
    int8_t new_rank_1, new_rank_2;
    switch (color) {
        case Color::White:
            new_rank_1 = rank + 1;
            new_rank_2 = rank + 2;
            forward_1 = b->pieceAt(new_rank_1, file);
            forward_2 = b->pieceAt(new_rank_2, file);
            left = b->pieceAt(new_rank_1, file-1);
            right = b->pieceAt(new_rank_1, file+1);
            checkPawnMoves(b, moves, Color::White, rank, file, forward_1, forward_2, left, right, new_rank_1, new_rank_2);
            break;
        case Color::Black:
            new_rank_1 = rank - 1;
            new_rank_2 = rank - 2;
            forward_1 = b->pieceAt(new_rank_1, file);
            forward_2 = b->pieceAt(new_rank_2, file);
            left = b->pieceAt(new_rank_1, file-1);
            right = b->pieceAt(new_rank_1, file+1);
            checkPawnMoves(b, moves, Color::Black, rank, file, forward_1, forward_2, left, right, new_rank_1, new_rank_2);
            break;
        default:
            break;
    }
    return moves;
}

std::vector<move_t> knightMoves(Chessboard* board, Color color, int8_t rank, int8_t file) {
    std::vector<move_t> moves;
    int8_t new_rank, new_file;

    for (new_rank = -2; new_rank < 3; new_rank += 1) {
        if (new_rank == -2 || new_rank == 2) {
            for (new_file = -1; new_file < 2; new_file += 2) {
                checkMove(board, moves, color, rank, file, new_rank, new_file);
            }
        } else if (new_rank == -1 || new_rank == 1) {
            for (new_file = -2; new_file < 3; new_file += 4) {
                checkMove(board, moves, color, rank, file, new_rank, new_file);
            }
        }
    }

    return moves;
}

std::vector<move_t> bishopMoves(Chessboard* b, Color color, int8_t rank, int8_t file) {
    std::vector<move_t> moves;
    int8_t new_rank, new_file, rank_delta, file_delta, result;

    for (rank_delta = -1; rank_delta < 2; rank_delta += 2) {
        for (file_delta = -1; file_delta < 2; file_delta += 2) {
            new_rank = rank;
            new_file = file;
            result = 1;
            while (result == 1) {
                new_rank += rank_delta;
                new_file += file_delta;
                result = checkMove(b, moves, color, rank, file, new_rank, new_file);
            }
        }
    }
    return moves;
}

std::vector<move_t> rookMoves(Chessboard* b, Color color, int8_t rank, int8_t file) {
    std::vector<move_t> moves;
    int8_t new_rank, new_file, rank_delta, file_delta, result;

    for (rank_delta = -1; rank_delta < 2; rank_delta += 2) {
        file_delta = 0;
        new_rank = rank;
        new_file = file;
        result = 1;
        while (result == 1) {
            new_rank += rank_delta;
            result = checkMove(b, moves, color, rank, file, new_rank, new_file);
        }
    }

    for (file_delta = -1; file_delta < 2; file_delta += 2) {
        rank_delta = 0;
        new_rank = rank;
        new_file = file;
        result = 1;
        while (result == 1) {
            new_file += file_delta;
            result = checkMove(b, moves, color, rank, file, new_rank, new_file);
        }
    }
    return moves;
}

std::vector<move_t> queenMoves(Chessboard* b, Color color, int8_t rank, int8_t file) {
    std::vector<move_t> queen_moves;
    
    std::vector<move_t> rook_moves = rookMoves(b, color, rank, file);
    for (std::vector<move_t>::iterator it = rook_moves.begin(); it != rook_moves.end(); it++) {
                    queen_moves.push_back(*it);
    }

    std::vector<move_t> bishop_moves = bishopMoves(b, color, rank, file);
    for (std::vector<move_t>::iterator it = bishop_moves.begin(); it != bishop_moves.end(); it++) {
                    queen_moves.push_back(*it);
    }

    return queen_moves;

}

std::vector<move_t> kingMoves(Chessboard* b, Color color, int8_t rank, int8_t file) {
    std::vector<move_t> moves;
    int8_t new_rank, new_file;

    for (new_rank = -1; new_rank < 2; new_rank += 1) {
        for (new_file = -1; new_file < 2; new_file += 1) {
            if (new_rank == 0 && new_file == 0) {
                continue;
            }
            checkMove(b, &moves, color, rank, file, new_rank, new_file);
        }
    }
    return moves;
}

std::vector<move_t> getPieceMoves(Chessboard* board, Piece *p, int8_t rank, int8_t file) {
    std::vector<move_t> moves;
    if (p == nullptr) {
        return moves;
    }
    switch(p->getPieceType()) {
        case PieceType::Pawn:
            moves = pawnMoves(board, p->getPieceColor(), rank, file);
            break;
        case PieceType::Knight:
            moves = knightMoves(board, p->getPieceColor(), rank, file);
            break;
        case PieceType::Bishop:
            moves = bishopMoves(board, p->getPieceColor(), rank, file);
            break;
        case PieceType::Rook:
            moves = rookMoves(board, p->getPieceColor(), rank, file);
            break;
        case PieceType::Queen:
            moves = queenMoves(board, p->getPieceColor(), rank, file);
            break;
        case PieceType::King:
            moves = kingMoves(board, p->getPieceColor(), rank, file);
            break;
        default:
            std::cout << "move not valid" << "\n";
            break;
    }
    return moves;
}

move_t createMove(int8_t r_source, int8_t f_source, int8_t r_dest, int8_t f_dest) {
    move_t new_move;
    new_move.rank_source = r_source;
    new_move.file_source = f_source;
    new_move.rank_dest = r_dest;
    new_move.file_dest = f_dest;
    return new_move;
}

int checkMove(Chessboard* b, vector<move_t> &moves, Color color, 
                    int8_t rank, int8_t file, int8_t new_rank, int8_t new_file) {
    
    if (new_rank < 0 || new_rank > 7 || new_file < 0 || new_file > 7) {
        return 0;
    }

    Piece *check_square = b->pieceAt(new_rank, new_file);
    if (check_square == nullptr) {
        moves.push_back(createMove(rank, file, new_rank, new_file));
        return 1;
    } else if (check_square->getPieceColor() != color) {
        moves.push_back(createMove(rank, file, new_rank, new_file));
        return 0;
    }
    return 0; // TODO: is it 
}