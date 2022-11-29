#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H


#include "board.h"

class GameManager {
    Board **theBoard;
    public:
        explicit GameManager (Board **board): theBoard{board} {}
        char getTile(int x1, int y1);
        Board **board();
        ~GameManager ();
};
#endif