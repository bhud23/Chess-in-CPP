/*
    main entry point for program, holds main game loop
*/
#include "subject.h"
#include "piece.h"
#include "gamemanager.h"
#include "blank.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

#include <utility>
#include <memory>
#include <iostream>
#include <string>

int main (int arc, char **argv) {
    int move = 1;
    int white_score = 0;
    int black_score = 0;

    std::unique_ptr<Board> board = std::make_unique<Blank>();
    std::unique_ptr<GameManger> gm = std::make_unique<GameManager>(&board);
    std::unique_ptr<Subject> s = std::make_unique<Subject>(GameManager);
    std::string inp;
    while (std::cin >> inp) {
        // if move % 2 == 1, then it is whites turn, blacks turn otherwise
        if (inp == "game") {
            cin >> inp;
            if (in)
        }
        else if (inp == "resign") {

        }
        else if ("move") {
            std::pair<int, int> start;
            std::pair<int, int> end;

        }
        else if (inp == "setup") {
            cin >> inp;
            if (inp == "default") // setup board to default
        }
        else {
            std::cout << "Invalid Input\n";
        }
        s->displayBoard();
        move++;
    }
    return 0;
}