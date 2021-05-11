#include <libchessviz/constants.h>

#include <libchessviz/board_print_plain.h>
#include <libchessviz/fill_board_std.h>
#include <libchessviz/scan.h>

#include <ctest.h>

const char MOVETYPEPAWN = '-';
const int PAWN_START = 1;
const int PAWN_END = 2;

CTEST(move_suite, pawn)
{
    int i, j;
    int result;
    char scan[STEPMAX];
    char EXPboard[BOARDSIZE][BOARDSIZE];
    char REALboard[BOARDSIZE][BOARDSIZE];
    for (i = 0; i < STEPMAX; i++)
        scan[i] = '0';
    fill_board_std(EXPboard);
    for (i = 0; i < BOARDSIZE; i++) {
        EXPboard[BOARDSIZE - PAWN_START - COLOR_DISLOC][i] = ' ';
        EXPboard[BOARDSIZE - PAWN_END - COLOR_DISLOC][i] = 'P';
        EXPboard[PAWN_START][i] = ' ';
        EXPboard[PAWN_END][i] = 'p';
    }
    fill_board_std(REALboard);
    // white
    for (i = 0; i < BOARDSIZE; i++) {
        scan[0] = ASCII_CHAR_START + i;
        scan[1] = ASCII_NUMB_START + PAWN_START;
        scan[2] = MOVETYPEPAWN;
        scan[3] = ASCII_CHAR_START + i;
        scan[4] = ASCII_NUMB_START + PAWN_END;
        result = scan_step(REALboard, CTESTING, scan);
        ASSERT_EQUAL(CONTINUE_GAME, result);
    }
    // black
    for (i = 0; i < BOARDSIZE; i++) {
        scan[0] = ASCII_CHAR_START + i;
        scan[1] = ASCII_NUMB_START + BOARDSIZE - PAWN_START - COLOR_DISLOC;
        scan[2] = MOVETYPEPAWN;
        scan[3] = ASCII_CHAR_START + i;
        scan[4] = ASCII_NUMB_START + BOARDSIZE - PAWN_END - COLOR_DISLOC;
        result = scan_step(REALboard, CTESTING, scan);
        ASSERT_EQUAL(CONTINUE_GAME, result);
    }
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++)
            ASSERT_EQUAL(EXPboard[i][j], REALboard[i][j]);
    }
}