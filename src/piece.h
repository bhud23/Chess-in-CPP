#ifndef _PIECE_H
#define _PIECE_H

#include <utility>

class Piece {
    int x, y;
    char team;
    public:
        virtual int getX () = 0;
        virtual int getY () = 0;
        virtual char getTeam () = 0;
        virtual char getType () = 0;
        virtual std::pair getPos () = 0;
        virtual bool validMove () = 0;
        Piece (int x, int y, char team);
        ~Piece () = default;
};

#endif