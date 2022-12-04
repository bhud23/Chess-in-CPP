#ifndef _BISHOP_H
#define _BISHOP_H

#include "piece.h"

class Bishop : public Piece {
    Board *next;
    int x, y;
    char team;
    bool alive;
    public:
        void move (int x1, int y1, int x2, int y2) override;
        char getTeam () override;
        char getTeam (int x1, int y1) override;
        char getType () override;
        void setDead (int x, int y) override;
        void setAlive (int x, int y) override;
        virtual char getTile (int x, int y) override;
        bool validMove (int x1, int y1, int x2, int y2) override;
        void undoMove (int x1, int y1, int x2, int y2) override;
        Bishop (Board *next, int x, int y, char team);
        ~Bishop ();
};

#endif
