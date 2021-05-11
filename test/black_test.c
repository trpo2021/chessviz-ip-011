#include <libchessviz/constants.h>

#include <libchessviz/board_print_plain.h>
#include <libchessviz/scan.h>

#include "constants_test.h"

#include <ctest.h>

#include <stdio.h>

CTEST(move_suite, black_figures)
{
    int i, j;
    int result[SCAN_COUNT];
    int resultI = 0;
    char scan[STEPMAX];
    char EXPboard[BOARDSIZE][BOARDSIZE];
    char REALboard[BOARDSIZE][BOARDSIZE];
    // Fill real board with black figures
    REALboard[0][0] = 'r';
    REALboard[0][1] = 'n';
    REALboard[0][2] = 'b';
    REALboard[0][3] = 'q';
    REALboard[0][4] = 'k';
    REALboard[0][5] = 'b';
    REALboard[0][6] = 'n';
    REALboard[0][7] = 'r';
    for (i = 1; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++)
            REALboard[i][j] = ' ';
    }
    // Fill expecterd board
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++)
            EXPboard[i][j] = ' ';
    }
    EXPboard[BOARDSIZE - (BSTART - ROOKMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [ROOK1 - ASCII_CHAR_START]
            = 'r';
    EXPboard[BOARDSIZE - (BSTART - ROOKMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [ROOK2 - ASCII_CHAR_START]
            = 'r';
    EXPboard[BOARDSIZE - (BSTART - KNIGHTMOVENUMB_DISLOC - ASCII_NUMB_DISLOC)]
            [KNIGHT1 + KNIGHTMOVECHAR_DISLOC - ASCII_CHAR_START]
            = 'n';
    EXPboard[BOARDSIZE - (BSTART - KNIGHTMOVENUMB_DISLOC - ASCII_NUMB_DISLOC)]
            [KNIGHT2 - KNIGHTMOVECHAR_DISLOC - ASCII_CHAR_START]
            = 'n';
    EXPboard[BOARDSIZE - (BSTART - BISHOPMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [BISHOP1 + BISHOPMOVE_DISLOC - ASCII_CHAR_START]
            = 'b';
    EXPboard[BOARDSIZE - (BSTART - BISHOPMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [BISHOP2 - BISHOPMOVE_DISLOC - ASCII_CHAR_START]
            = 'b';
    EXPboard
            [BOARDSIZE
             - (BSTART - QUEENFIRSTMOVE_DISLOC + QUEENSECONDMOVE_DISLOC
                - ASCII_NUMB_DISLOC)]
            [QUEEN - QUEENFIRSTMOVE_DISLOC - ASCII_CHAR_START]
            = 'q';
    EXPboard[BOARDSIZE - (BSTART - KINGMOVE_DISLOC - ASCII_NUMB_DISLOC)]
            [KING - KINGMOVE_DISLOC - ASCII_CHAR_START]
            = 'k';
    for (i = 0; i < BOARDSIZE; i++)
        scan[i] = '0';
    // ROOK --1.from a8 to a4   2.from h8 to h4--
    scan[0] = ROOK1;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = ROOK1;
    scan[4] = BSTART - ROOKMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = ROOK2;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = ROOK2;
    scan[4] = BSTART - ROOKMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // KNIGHT --1.from b8 to c6   2.from g8 to f6--
    scan[0] = KNIGHT1;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = KNIGHT1 + KNIGHTMOVECHAR_DISLOC;
    scan[4] = BSTART - KNIGHTMOVENUMB_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = KNIGHT2;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = KNIGHT2 - KNIGHTMOVECHAR_DISLOC;
    scan[4] = BSTART - KNIGHTMOVENUMB_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // BISHOP --1.from c8 to g4   2.from f8 to b4--
    scan[0] = BISHOP1;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = BISHOP1 + BISHOPMOVE_DISLOC;
    scan[4] = BSTART - BISHOPMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = BISHOP2;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = BISHOP2 - BISHOPMOVE_DISLOC;
    scan[4] = BSTART - BISHOPMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // QUEEN --1.from d8 to b6   2.from b6 to b8--
    scan[0] = QUEEN;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = QUEEN - QUEENFIRSTMOVE_DISLOC;
    scan[4] = BSTART - QUEENFIRSTMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = QUEEN - QUEENFIRSTMOVE_DISLOC;
    scan[1] = BSTART - QUEENFIRSTMOVE_DISLOC;
    scan[2] = MOVETYPE;
    scan[3] = QUEEN - QUEENFIRSTMOVE_DISLOC;
    scan[4] = BSTART - QUEENFIRSTMOVE_DISLOC + QUEENSECONDMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    // KING --1.from e8 to e7   2.from e7 to d7--
    scan[0] = KING;
    scan[1] = BSTART;
    scan[2] = MOVETYPE;
    scan[3] = KING;
    scan[4] = BSTART - KINGMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    scan[0] = KING;
    scan[1] = BSTART - KINGMOVE_DISLOC;
    scan[2] = MOVETYPE;
    scan[3] = KING - KINGMOVE_DISLOC;
    scan[4] = BSTART - KINGMOVE_DISLOC;
    result[resultI++] = scan_step(REALboard, CTESTING, scan);
    for (i = 0; i < SCAN_COUNT; i++)
        ASSERT_EQUAL(CONTINUE_GAME, result[i]);
    for (i = 0; i < BOARDSIZE; i++)
        for (j = 0; j < BOARDSIZE; j++)
            ASSERT_EQUAL(EXPboard[i][j], REALboard[i][j]);
}