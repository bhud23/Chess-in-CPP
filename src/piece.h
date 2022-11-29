#ifndef _PIECE_H
#define _PIECE_H

#include "board.h"

class Piece : public Board {
    public:
        virtual int getX () = 0;
        virtual int getY () = 0;
        virtual char getTeam () = 0;
        virtual char getType () = 0;
        virtual void setDead (int x, int y) = 0;
        virtual void setAlive (int x, int y) = 0;
        Piece ();
        ~Piece () = default;
};

#endif