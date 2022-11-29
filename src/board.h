#ifndef _BOARD_H
#define _BOARD_H

class Board {
    public:
        virtual char getTile (int x, int y) = 0;
        virtual bool validMove (int x1, int y1, int x2, int y2) = 0;
        ~Board () = default;
};

#endif