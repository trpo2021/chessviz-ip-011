#pragma once

enum test {
    SUCCESS,
    WRONGINPUT,
    EXITSUCCESS,
    PAWNERROR,
    KINGERROR,
    BORDERLIMIT,
    QUEENERROR,
    ROOKERROR,
    KNIGHTERROR,
    BISHOPERROR,
    CHECKMATE
};

int move(char board[][9], char moveChess[]);
