#ifndef _BLANK_H
#define _BLANK_H

#include "board.h"

class Blank : public Board {
    char getTile (int x, int y);
    bool validMove (int x1, int y1, int x2, int y2);
    void undoMove (int x1, int y1, int x2, int y2) override;
    public:
    Blank ();
    ~Blank ();
    void setX (int x1, int y1, int x2, int y2) override;
    void setY (int x1, int y1, int x2, int y2) override;
    char getTeam () override;
    char getTeam (int x1, int y1) override;
    char getType () override;
    void setAlive (int x, int y) override;
    void setDead (int x, int y) override;
};

#endif
