#ifndef _BOARD_H
#define _BOARD_H

class Board : public GameManager {
    public:
        virtual char getTile (int x, int y) = 0;
        ~Board () = default;
};

#endif