#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "subject.h"

class Board;

class GameManager : public Subject {
    Board **theBoard;
    private:
        explicit ~GameManager (Board **board): theBoard{board} {}
        char getTitle(int x1, int y1);
        Board **board();
        ~GameManager ();
};

#endif