#include "libchessviz/board_read.h"
#include "libchessviz/board.h"
#include "libchessviz/board_print_plain.h"
#include "libchessviz/move.h"
#include <stdio.h>

int main()
{
    char board[9][9];
    char moveChess[11];
    int check = 0;

    fillBoard(board);
    printBoard(board);

    printf("Move example: e2-e4 \nType 0 to exit program");

    while (1) {
        printf("\nType a move: ");
        readBoard(moveChess);

        check = move(board, moveChess);

        if (check == 1) {
            printf("\nInput data fail\n");
            break;
        }

        if (check == 2) {
            printf("\n\nExiting program\n");
            break;
        }
        
        if (check == 3) {
            printf("\n\nWrong figure chosen. Must be Pawn\n");
            break;
        }

        if (check == 4) {
            printf("\n\nWrong figure chosen. Must be King\n");
            break;
        }

        if (check == 5) {
            printf("\n\nStep out of border\n");
            break;
        }

        if (check == 6) {
            printf("\n\nWrong figure chosen. Must be Queen\n");
            break;
        }

        if (check == 7) {
            printf("\n\nWrong figure chosen. Must be Rook\n");
            break;
        }

        if (check == 8) {
            printf("\n\nWrong figure chosen. Must be knight\n");
            break;
        }

        if (check == 9) {
            printf("\n\nWrong figure chosen. Must be Bishop\n");
            break;
        }

        if (check == 10) {
            printf("\n\nCheckmate, well done!\n");
            break;
        }

        printBoard(board);
    }

    return 0;
}
