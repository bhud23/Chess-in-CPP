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
#include "observer.h"
#include "graphicdisplay.h"
#include "textdisplay.h"

#include <utility>
#include <memory>
#include <iostream>
#include <string>

int main (int arc, char **argv) {
    int move = 1;
    int white_score = 0;
    int black_score = 0;

    std::unique_ptr<Board> head = std::make_unique<Blank>(); // like the canvas
    std::unique_ptr<GameManager> gm = std::make_unique<GameManager>(&head); // like the studio
    std::string inp;

    Observer *graph = new GraphicDisplay{gm};
    gm.attach(graph);
    Observer *txt = new TextDisplay{gm};
    gm.attach(txt);
    
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
        gm->displayBoard();
        move++;
    }
    return 0;
}