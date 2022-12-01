#ifndef _GAME_H
#define _GAME_H

#include "board.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

#include <utility>

class Game {
    Board &head;
    std::pair<int, int> white_king;
    std::pair<int, int> black_king;
    public:
        Game (Board &b);
        ~Game () = default;
        char pieceAt (int x, int y);
        void defaultSetup (Board **head);
        void movePiece (int x1, int y1, int x2, int y2);
        std::pair<int, int> kingCoords (char team);
        bool isCheck (char team);
        bool isCheckMate (char team);
        bool isStalemate ();
        void printScore ();
};

#endif
