#include "libchessviz/board.h"
#include "libchessviz/move.h"
#include <ctest.h>
#include <string.h>

CTEST(movechess_suite, success_exit)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "e2-e4");

    int testExp = SUCCESS;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, wrong_input)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "Q1e");

    int testExp = WRONGINPUT;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, manual_exit)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "0");

    int testExp = EXITSUCCESS;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, pawn_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "e1-e8");

    int testExp = PAWNERROR;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, king_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "Ke2-e4");

    int testExp = KINGERROR;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, border_limit)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "e2-e9");

    int testExp = BORDERLIMIT;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, queen_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "Qe2-e4");

    int testExp = QUEENERROR;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, rook_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "Re2-e4");

    int testExp = ROOKERROR;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, knight_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "Ne2-e4");

    int testExp = KNIGHTERROR;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, bishop_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "Be2-e4");

    int testExp = BISHOPERROR;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}

CTEST(movechess_suite, checkmate_test)
{
    char board[9][9];
    fillBoard(board);

    char testStep[11];
    strcpy(testStep, "e2-e4#");

    int testExp = CHECKMATE;

    int testResult = move(board, testStep);

    ASSERT_EQUAL(testExp, testResult);
}
