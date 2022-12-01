#ifndef _BLANK_H
#define _BLANK_H

#include "board.h"

class Blank : public Board {
    char getTile (int x, int y);
    bool validMove (int x1, int y1, int x2, int y2);
    Blank ();
    ~Blank ();
};

#endif