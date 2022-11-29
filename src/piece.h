#ifndef _PIECE_H
#define _PIECE_H

class Board;

class Piece : public Board {
    public:
        virtual int getX () = 0;
        virtual int getY () = 0;
        virtual char getTeam () = 0;
        virtual char getType () = 0;
        virtual void setDead (int x, int y) = 0;
        virtual void setAlive (int x, int y) = 0;
        Piece (Board &b, Piece *next, int x, int y, char team);
        ~Piece () = default;
};

#endif