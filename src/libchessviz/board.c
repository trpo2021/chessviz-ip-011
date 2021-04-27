#include <libchessviz/board.h>

int fillBoard(char board[][9])
{
    board[0][0] = 32;
    board[0][1] = 'a';
    board[0][2] = 'b';
    board[0][3] = 'c';
    board[0][4] = 'd';
    board[0][5] = 'e';
    board[0][6] = 'f';
    board[0][7] = 'g';
    board[0][8] = 'h';
    board[1][0] = '1';
    board[1][1] = 'R';
    board[1][2] = 'N';
    board[1][3] = 'B';
    board[1][4] = 'Q';
    board[1][5] = 'K';
    board[1][6] = 'B';
    board[1][7] = 'N';
    board[1][8] = 'R';
    board[2][0] = '2';

    for (int i = 1; i < 9; i++) {
        board[2][i] = 'P';
    }

    board[3][0] = '3';
    board[4][0] = '4';
    board[5][0] = '5';
    board[6][0] = '6';

    for (int i = 3; i < 6; i++) {
        for (int j = 1; j < 9; j++) {
            board[i][j] = 32;
        }
    }

    board[7][0] = '7';

    for (int i = 1; i < 9; i++) {
        board[7][i] = 'p';
    }

    board[8][0] = '8';
    board[8][1] = 'r';
    board[8][2] = 'n';
    board[8][3] = 'b';
    board[8][4] = 'q';
    board[8][5] = 'k';
    board[8][6] = 'b';
    board[8][7] = 'n';
    board[8][8] = 'r';

    return 0;
}
