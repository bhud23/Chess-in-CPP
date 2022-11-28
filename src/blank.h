#ifndef _BLANK_H
#define _BLANK_H

#include "board.h"

class Blank : public Board {
    virtual char getTile (int x, int y);
};

#endif