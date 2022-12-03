#ifndef _GAME_H
#define _GAME_H

#include "board.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "gamemanager.h"

#include <utility>
#include <iostream>
#include <string>

class Game {
    int move;
    int row = 7;
    int col = 7;
    Board **head;
    GameManager *gm;
    std::pair<int, int> white_king;
    std::pair<int, int> black_king;
    Player *player1;
    Player *player2;
    private:
        std::pair<int, int> getCoords();
        void placePiece ();
        void removePiece ();
    public:
        Game (Board **b, GameManager *gm, Player *player1, Player *player2);
        ~Game ();
        char pieceAt (int x, int y);
        void defaultSetup ();
        void customSetup();
        void movePiece (int x1, int y1, int x2, int y2);
        std::pair<int, int> kingCoords (char team);
        bool isCheck (char team);
        bool isCheckmate (char team);
        bool isStalemate ();
        void printScore ();
        char playGame ();
        void setPlayer1 (Player *p);
        void setPlayer2 (Player *p);
};

#endif
