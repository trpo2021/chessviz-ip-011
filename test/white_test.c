#include <libchessviz/constants.h>

#include <libchessviz/board_print_plain.h>
#include <libchessviz/scan.h>

#include "constants_test.h"

#include <ctest.h>

#include <stdio.h>

CTEST(move_suite, white_figures)
{
    int i, j;
    int result[SCAN_COUNT];
    int resultI = 0;
    char scan[STEPMAX];
    char EXPboard[BOARDSIZE][BOARDSIZE];
    char REALboard[BOARDSIZE][BOARDSIZE];
    // Fill real board with white figures
    for (i = 0; i < BOARDSIZE - 1; i++) {
        for (j = 0; j < BOARDSIZE; j++)
            REALboard[i][j] = ' ';
    }
    REALboard[BOARDSIZE - 1][0] = 'R';
    REALboard[BOARDSIZE - 1][1] = 'N';
    REALboard[BOARDSIZE - 1][2] = 'B';
    REALboard[BOARDSIZE - 1][3] = 'Q';
    REALboard[BOARDSIZE - 1][4] = 'K';
    REALboard[BOARDSIZE - 1][5] = 'B';
    REALboard[BOARDSIZE - 1][6] = 'N';
    REALboard[BOARDSIZE - 1][7] = 'R';
    // Fill expecterd board
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++)
            EXPboard[i][j] = ' ';
    }
    EXPboard[BOARDSIZE - (WSTART + ROOKMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [ROOK1 - ASCII_CHAR_START]
            = 'R';
    EXPboard[BOARDSIZE - (WSTART + ROOKMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [ROOK2 - ASCII_CHAR_START]
            = 'R';
    EXPboard[BOARDSIZE - (WSTART + KNIGHTMOVENUMB_DISLOC - ASCII_NUMB_DISLOC)]
            [KNIGHT1 + KNIGHTMOVECHAR_DISLOC - ASCII_CHAR_START]
            = 'N';
    EXPboard[BOARDSIZE - (WSTART + KNIGHTMOVENUMB_DISLOC - ASCII_NUMB_DISLOC)]
            [KNIGHT2 - KNIGHTMOVECHAR_DISLOC - ASCII_CHAR_START]
            = 'N';
    EXPboard[BOARDSIZE - (WSTART + BISHOPMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [BISHOP1 + BISHOPMOVE_DISLOC - ASCII_CHAR_START]
            = 'B';
    EXPboard[BOARDSIZE - (WSTART + BISHOPMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [BISHOP2 - BISHOPMOVE_DISLOC - ASCII_CHAR_START]
            = 'B';
    EXPboard
            [BOARDSIZE
             - (WSTART + QUEENFIRSTMOVE_DISLOC - QUEENSECONDMOVE_DISLOC
                - ASCII_NUMB_DISLOC)]
            [QUEEN - QUEENFIRSTMOVE_DISLOC - ASCII_CHAR_START]
            = 'Q';
    EXPboard[BOARDSIZE - (WSTART + KINGMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [KING - KINGMOVE_DISLOC - ASCII_CHAR_START]
            = 'K';
    for (i = 0; i < BOARDSIZE; i++)
        scan[i] = '0';
    // ROOK --1.from a1 to a5   2.from h1 to h5--
    scan[0] = ROOK1;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = ROOK1;
    scan[4] = WSTART + ROOKMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = ROOK2;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = ROOK2;
    scan[4] = WSTART + ROOKMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // KNIGHT --1.from b1 to c3   2.from g1 to f3--
    scan[0] = KNIGHT1;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = KNIGHT1 + KNIGHTMOVECHAR_DISLOC;
    scan[4] = WSTART + KNIGHTMOVENUMB_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = KNIGHT2;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = KNIGHT2 - KNIGHTMOVECHAR_DISLOC;
    scan[4] = WSTART + KNIGHTMOVENUMB_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // BISHOP --1.from c1 to g5   2.from f1 to b5--
    scan[0] = BISHOP1;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = BISHOP1 + BISHOPMOVE_DISLOC;
    scan[4] = WSTART + BISHOPMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = BISHOP2;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = BISHOP2 - BISHOPMOVE_DISLOC;
    scan[4] = WSTART + BISHOPMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // QUEEN --1.from d1 to b3   2.from b3 to b1--
    scan[0] = QUEEN;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = QUEEN - QUEENFIRSTMOVE_DISLOC;
    scan[4] = WSTART + QUEENFIRSTMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = QUEEN - QUEENFIRSTMOVE_DISLOC;
    scan[1] = WSTART + QUEENFIRSTMOVE_DISLOC;
    scan[2] = MOVETYPE;
    scan[3] = QUEEN - QUEENFIRSTMOVE_DISLOC;
    scan[4] = WSTART + QUEENFIRSTMOVE_DISLOC - QUEENSECONDMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // KING --1.from e1 to e2   2.from e2 to d2--
    scan[0] = KING;
    scan[1] = WSTART;
    scan[2] = MOVETYPE;
    scan[3] = KING;
    scan[4] = WSTART + KINGMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = KING;
    scan[1] = WSTART + KINGMOVE_DISLOC;
    scan[2] = MOVETYPE;
    scan[3] = KING - KINGMOVE_DISLOC;
    scan[4] = WSTART + KINGMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    for (i = 0; i < SCAN_COUNT; i++)
        ASSERT_EQUAL(CONTINUE_GAME, result[i]);
    for (i = 0; i < BOARDSIZE; i++)
        for (j = 0; j < BOARDSIZE; j++)
            ASSERT_EQUAL(EXPboard[i][j], REALboard[i][j]);
}