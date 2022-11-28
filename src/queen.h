#ifndef _QUEEN_H
#define _QUEEN_H

#include "piece.h"

class Queen : public Piece {
    public:
        int getX () override;
        int getY () override;
        char getTeam () override;
        char getType () override;
        void setDead (int x, int y) override;
        void setAlive (int x, int y) override;
        virtual char getTile (int x, int y) override;
        bool validMove () override;
        Pawn(int x, int y, char team);
};