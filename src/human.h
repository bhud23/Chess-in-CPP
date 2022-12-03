#ifndef _HUMAN_H
#define _HUMAN_H

#include "player.h"
#include <string>

class Human : public Player {
    std::istream &in = std::cin;
    public:
        std::pair<int, int> getMove() override;
        ~Human () = default;
};

#endif