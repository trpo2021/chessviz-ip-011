#include <libchessviz/checks.h>
#include <libchessviz/constants.h>
#include <libchessviz/fill_board_std.h>

#include <ctest.h>

CTEST(scan_suite, check_beg)
{
    char STARTK[STEPMAX];
    char STARTQ[STEPMAX];
    char STARTR[STEPMAX];
    char STARTB[STEPMAX];
    char STARTN[STEPMAX];
    char STARTP[STEPMAX];
    char STARTNOT[STEPMAX];
    STARTK[0] = 'K';
    STARTQ[0] = 'Q';
    STARTR[0] = 'R';
    STARTB[0] = 'B';
    STARTN[0] = 'N';
    STARTP[0] = 'P';
    STARTNOT[0] = '1';
    const int REALK = check_beginning(STARTK);
    const int REALQ = check_beginning(STARTQ);
    const int REALR = check_beginning(STARTR);
    const int REALB = check_beginning(STARTB);
    const int REALN = check_beginning(STARTN);
    const int REALP = check_beginning(STARTP);
    const int REALNOT = check_beginning(STARTNOT);
    const int EXPECTK = 1;
    const int EXPECTQ = 1;
    const int EXPECTR = 1;
    const int EXPECTB = 1;
    const int EXPECTN = 1;
    const int EXPECTP = 1;
    const int EXPECTNOT = 0;
    ASSERT_EQUAL(EXPECTK, REALK);
    ASSERT_EQUAL(EXPECTQ, REALQ);
    ASSERT_EQUAL(EXPECTR, REALR);
    ASSERT_EQUAL(EXPECTB, REALB);
    ASSERT_EQUAL(EXPECTN, REALN);
    ASSERT_EQUAL(EXPECTP, REALP);
    ASSERT_EQUAL(EXPECTNOT, REALNOT);
}