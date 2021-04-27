#include <libchessviz/board_print_plain.h>
#include <stdio.h>

int printBoard(char board[][9])
{
    printf("\n");

    for (int i = 9; i > -1; i--) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 32;
            }

            printf("%4c", board[i][j]);
        }

        printf("\n");
    }

    printf("\n-%d-\n", board[0][0]);

    return 0;
}
