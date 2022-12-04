#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "piece.h"

class Knight : public Piece {
    Board *next;
    int x, y;
    char team;
    bool alive;
    public:
        int getX () override;
        int getY () override;
        char getTeam () override;
        char getTeam (int x1, int y1) override;
        char getType () override;
        void setDead (int x, int y) override;
        void setAlive (int x, int y) override;
        virtual char getTile (int x, int y) override;
        bool validMove (int x1, int y1, int x2, int y2) override;
        void undoMove (int x1, int y1, int x2, int y2) override;
        Knight (Board *next, int x, int y, char team);
        ~Knight ();
};

#endif
