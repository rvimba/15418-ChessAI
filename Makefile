# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -std=c++11 -O2 -fopenmp

chessai: chess_ai.o minimax.o piece_moves.o chessboard.o chess_pieces.o
	$(CC) $(CFLAGS) -o chessai chess_ai.o minimax.o piece_moves.o chessboard.o chess_pieces.o

chess_ai.o: chess_ai.cpp minimax.h
	$(CC) $(CFLAGS) -c chess_ai.cpp

minimax.o: minimax.cpp minimax.h
	$(CC) $(CFLAGS) -c minimax.cpp

piece_moves.o: piece_moves.cpp piece_moves.h
	$(CC) $(CFLAGS) -c piece_moves.cpp

chessboard.o: chessboard.cpp chessboard.h
	$(CC) $(CFLAGS) -c chessboard.cpp

chess_pieces.o: chess_pieces.cpp chess_pieces.h
	$(CC) $(CFLAGS) -c chess_pieces.cpp

clean:
			$(RM) *.o chessai