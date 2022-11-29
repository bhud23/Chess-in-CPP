#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "subject.h"

class GameManager {
    Board **theBoard;
    private:
        explicit ~GameManager (Board **board): theBoard{board} {}
        char getTile(int x1, int y1);
        Board **board();
        ~GameManager ();
};
#endif