CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD

.PHONY:	all

all:	bin/Chess.exe Run clean

bin/Chess.exe:  obj/src/Chess/Chess.o obj/src/libChess/libChessHelper.a
	g++ $(CFLAGS) -o $@ $^

obj/src/Chess/Chess.o: src/Chess/Chess.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/libChess/libChessHelper.a: obj/src/Chess/ChessHelper.o
	ar rcs $@ $^

obj/src/Chess/ChessHelper.o: src/libChess/ChessHelper.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

Run:
	bin/Chess.exe

-include obj/src/Chess/Chess.d obj/src/Chess/ChessHelper.d

clean:
	rm -f obj/src/Chess/ChessHelper.o obj/src/libChess/libChessHelper.a obj/src/Chess/Chess.o obj/src/Chess/ChessHelper.d obj/src/Chess/Chess.d