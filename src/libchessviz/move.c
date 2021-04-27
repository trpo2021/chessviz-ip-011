#include <libchessviz/move.h>
#include <stdio.h>

int move(char board[][9], char moveChess[])
{
    int i, j;
    char t;

    for (i = 0; i < 11; i++) {
        if (moveChess[i] == '0')
            return 2;
    }

    j = moveChess[0] - '`';
    i = moveChess[1] - '0';

    if (board[i][j] == 32) {
        return 1;
    }

    t = board[i][j];
    board[i][j] = 32;

    j = moveChess[3] - '`';
    i = moveChess[4] - '0';

    board[i][j] = t;

    return 0;
}
