
void Chessboard::setBoardUp() {

    // Start by clearing the Piece pointers.
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            board_[row][col] = NULL;
            // Setup white and black pawns on 0th and 6th rows.
            if (row == 0) { 
                board_[row][col] = WhitePieces_[col];
            } else if (row == 6) {
                board_[row][col] = BlackPieces_[col];
            } 
        }
    }

    // Rooks
    board_[0][0] = WhitePieces_[12];
    board_[0][7] = WhitePieces_[13];
    board_[7][0] = BlackPieces_[12];
    board_[7][7] = BlackPieces_[13];

    // Knights
    board_[0][1] = WhitePieces_[10];
    board_[0][6] = WhitePieces_[11];
    board_[7][1] = BlackPieces_[10];
    board_[7][6] = BlackPieces_[11];

    // Bishops
    board_[0][2] = WhitePieces_[8];
    board_[0][5] = WhitePieces_[9];
    board_[7][2] = BlackPieces_[8];
    board_[7][5] = BlackPieces_[9];

    // King & Queen
    board_[0][3] = WhitePieces_[15]; // Queen
    board_[0][4] = WhitePieces_[14]; // King
    board_[7][3] = BlackPieces_[15]; // Q
    board_[7][4] = BlackPieces_[14]; // K
}

void Chessboard::initializeBoard() {

    // Allocate and set all pieces (white and black).
    for (int i = 0; i < 16; i++) {
        WhitePieces_[i] = new Piece(Color::White);
        BlackPieces_[i] = new Piece(Color::Black);

        if (i < 8) {
            WhitePieces_[i]->setPieceType(PieceType::Pawn);
            BlackPieces_[i]->setPieceType(PieceType::Pawn);
        } else if (i < 10) {
            WhitePieces_[i]->setPieceType(PieceType::Bishop);
            BlackPieces_[i]->setPieceType(PieceType::Bishop);
        } else if (i < 12) {
            WhitePieces_[i]->setPieceType(PieceType::Knight);
            BlackPieces_[i]->setPieceType(PieceType::Knight);
        } else if (i < 14) {
            WhitePieces_[i]->setPieceType(PieceType::Rook);
            BlackPieces_[i]->setPieceType(PieceType::Rook);
        } else if (i == 14) {
            WhitePieces_[i]->setPieceType(PieceType::King);
            BlackPieces_[i]->setPieceType(PieceType::King);
        } else {
            WhitePieces_[i]->setPieceType(PieceType::Queen);
            BlackPieces_[i]->setPieceType(PieceType::Queen);
        }
    }

    setBoardUp();
}

bool Chessboard::isWhite()
{
	return (aiColor_ == Color::White);
}

void Chessboard::setPiece(int row, int col, PieceType newType)
{
    board[row][col]->setPieceType(newType);
};

Piece* Chessboard::movePiece(int oldrow, int oldcol, int newrow, int newcol)
{
    // Check if there is a piece in the old indexes.
    if (pieceAt(oldRow, oldCol) == NULL) return NULL;

    // Check range of moves.
    if (oldrow < 0 || 8 <= oldrow) return NULL;
    if (oldcol < 0 || 8 <= oldcol) return NULL;
    if (newrow < 0 || 8 <= newrow) return NULL;
    if (newcol < 0 || 8 <= newcol) return NULL;

    board[newrow][newcol] = board[oldrow][oldcol];
    board[oldrow][oldcol] = NULL;
    return board[newrow][newcol];
}

Piece* Chessboard::makeMove(int oldrow, int oldcol, int newrow, int newcol)
{
    // TODO(fleyva): account for special game instances (aka promoting pawn).

	return movePiece(oldrow, oldcol, newrow, newcol);
}

Piece* pieceAt(int row, int col) {
    return board_[row][col];
}

void ChessBoard::init()
{
	initialize();
}

ChessBoard* ChessBoard::copy()
{
	// TODO(Fleyva): add copy fxn
}

void ChessBoard::freePieces()
{
    for (int i = 0; i < 16; i++) {
        delete WhitePieces_[i];
        delete BlackPieces_[i];
    }
}

Chessboard::Chessboard(Color aiColor) : aiColor_(aiColor) {}