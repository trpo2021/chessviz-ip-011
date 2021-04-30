#include <libchessviz/move.h>
#include <stdio.h>

int move(char board[][9], char moveChess[])
{
    int i, j, m, n, c;
    char t;

    if (moveChess[0] == '0')
        return EXITSUCCESS;

    if (moveChess[0] > '`' && moveChess[0] < 'i') {
        j = moveChess[0] - '`';
        i = moveChess[1] - '0';
        c = 0;

        if (moveChess[2] != '-' && moveChess[2] != 'x' && moveChess[2] != 'e'
            && moveChess[3] != '.' && moveChess[4] != 'p'
            && moveChess[5] != '.')
            return WRONGINPUT;

        if (moveChess[2] == 'e' && moveChess[3] == '.' && moveChess[4] == 'p'
            && moveChess[5] == '.')
            c = 3;

        if ((board[i][j] != 'p') && (board[i][j] != 'P'))
            return PAWNERROR;

        n = moveChess[3 + c] - '`';
        m = moveChess[4 + c] - '0';

        if (moveChess[5 + c] == '#')
            return CHECKMATE;
    }

    if (moveChess[0] == 'K') {
        j = moveChess[1] - '`';
        i = moveChess[2] - '0';

        c = 0;

        if (moveChess[3] != '-' && moveChess[3] != 'x' && moveChess[3] != 'e'
            && moveChess[4] != '.' && moveChess[5] != 'p'
            && moveChess[6] != '.')
            return WRONGINPUT;

        if (moveChess[3] == 'e' && moveChess[4] == '.' && moveChess[5] == 'p'
            && moveChess[6] == '.')
            c = 3;

        if ((board[i][j] != 'k') && (board[i][j] != 'K'))
            return KINGERROR;

        n = moveChess[4 + c] - '`';
        m = moveChess[5 + c] - '0';
        if (moveChess[6 + c] == '#')
            return CHECKMATE;
    }

    if (moveChess[0] == 'Q') {
        j = moveChess[1] - '`';
        i = moveChess[2] - '0';

        if (moveChess[3] != '-' && moveChess[3] != 'x' && moveChess[3] != 'e'
            && moveChess[4] != '.' && moveChess[5] != 'p'
            && moveChess[6] != '.')
            return WRONGINPUT;

        if (moveChess[3] == 'e' && moveChess[4] == '.' && moveChess[5] == 'p'
            && moveChess[6] == '.')
            c = 3;

        if ((board[i][j] != 'q') && (board[i][j] != 'Q'))
            return QUEENERROR;

        n = moveChess[4 + c] - '`';
        m = moveChess[5 + c] - '0';
        if (moveChess[6 + c] == '#')
            return CHECKMATE;
    }

    if (moveChess[0] == 'R') {
        j = moveChess[1] - '`';
        i = moveChess[2] - '0';

        if (moveChess[3] != '-' && moveChess[3] != 'x' && moveChess[3] != 'e'
            && moveChess[4] != '.' && moveChess[5] != 'p'
            && moveChess[6] != '.')
            return WRONGINPUT;

        if (moveChess[3] == 'e' && moveChess[4] == '.' && moveChess[5] == 'p'
            && moveChess[6] == '.')
            c = 3;

        if ((board[i][j] != 'r') && (board[i][j] != 'R'))
            return ROOKERROR;

        n = moveChess[4 + c] - '`';
        m = moveChess[5 + c] - '0';
        if (moveChess[6 + c] == '#')
            return CHECKMATE;
    }

    if (moveChess[0] == 'N') {
        j = moveChess[1] - '`';
        i = moveChess[2] - '0';

        if (moveChess[3] != '-' && moveChess[3] != 'x' && moveChess[3] != 'e'
            && moveChess[4] != '.' && moveChess[5] != 'p'
            && moveChess[6] != '.')
            return WRONGINPUT;

        if (moveChess[3] == 'e' && moveChess[4] == '.' && moveChess[5] == 'p'
            && moveChess[6] == '.')
            c = 3;

        if ((board[i][j] != 'n') && (board[i][j] != 'N'))
            return KNIGHTERROR;

        n = moveChess[4 + c] - '`';
        m = moveChess[5 + c] - '0';
        if (moveChess[6 + c] == '#')
            return CHECKMATE;
    }

    if (moveChess[0] == 'B') {
        j = moveChess[1] - '`';
        i = moveChess[2] - '0';

        if (moveChess[3] != '-' && moveChess[3] != 'x' && moveChess[3] != 'e'
            && moveChess[4] != '.' && moveChess[5] != 'p'
            && moveChess[6] != '.')
            return WRONGINPUT;

        if (moveChess[3] == 'e' && moveChess[4] == '.' && moveChess[5] == 'p'
            && moveChess[6] == '.')
            c = 3;

        if ((board[i][j] != 'b') && (board[i][j] != 'B'))
            return BISHOPERROR;

        n = moveChess[4 + c] - '`';
        m = moveChess[5 + c] - '0';
        if (moveChess[6 + c] == '#')
            return CHECKMATE;
    }

    if (i > 8 || i < 1 || j < 1 || j > 8 || m > 8 || m < 1 || n < 1 || n > 8)
        return BORDERLIMIT;
    {
        t = board[i][j];
        board[i][j] = 32;
        board[m][n] = t;
    }

    return SUCCESS;
}
