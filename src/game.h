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
#include "player.h"
#include "stack.h"

#include <utility>
#include <iostream>
#include <string>

class Game {
    int move;
    int row = 7;
    int col = 7;
    Board **head;
    GameManager *gm;
    Stack stack;
    std::pair<int, int> white_king;
    std::pair<int, int> black_king;
    Player *player1;
    Player *player2;
    private: // for setting up board
        std::pair<int, int> getCoords();
        void placePiece ();
        void removePiece ();
    private: // for moving piece
        void setAlive (int x1, int y1);
        void setDead (int x1, int y1);
    private: // for moving pieces
        bool pawnValidMove (int x1, int y1, int x2, int y2);
        bool rookValidMove (int x1, int y1, int x2, int y2);
        bool bishopValidMove (int x1, int y1, int x2, int y2);
        bool knightValidMove (int x1, int y1, int x2, int y2);
        bool kingValidMove (int x1, int y1, int x2, int y2);
        bool queenValidMove (int x1, int y1, int x2, int y2);
    private: // helper functions
        char pieceAt (int x, int y);
        std::pair<int, int> kingCoords (char team);
        bool isCheck (char team);
        bool isCheckmate (char team);
        bool isStalemate ();
        bool validMove(int x1, int y1, int x2, int y2);
    public:
        Game (Board **b, GameManager *gm, Player *player1, Player *player2);
        ~Game ();
        void defaultSetup ();
        void customSetup();
        char playGame ();
        void setPlayer1 (Player *p);
        void setPlayer2 (Player *p);
};

#endif
