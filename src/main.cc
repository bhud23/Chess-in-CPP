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
#include "game.h"

#include <utility>
#include <memory>
#include <iostream>
#include <string>

int main (int arc, char **argv) {
    int move = 1;
    int white_score = 0;
    int black_score = 0;

    Board *head = new Blank{}; // like the canvas
    GameManager *gm = new GameManager{&head}; // like the studio
    Game game {head};
    std::string inp;


    Observer *txt = new TextDisplay {*gm, 8, 8, 8};
    gm->attach(txt);
    Observer *graph = new GraphicDisplay {*gm, 8, 8};
    gm->attach(graph);
    
    std::cout << "Welcome to Chess - the CS246 orignal game" << std::endl;
    game.defaultSetup(&head);
    gm->displayBoard();
    while (std::cin >> inp) {
        // if move % 2 == 1, then it is whites turn, blacks turn otherwise
        if (inp == "game") {
		std::cin >> inp;
        }
        else if (inp == "resign") {

        }
        else if ("move") {
            std::pair<int, int> start;
            std::pair<int, int> end;
        }
        else if (inp == "setup") {
	//	std::cin >> inp;	
        }
        else {
            std::cout << "Invalid Input\n";
        }
        gm->displayBoard();
        move++;
    }
    return 0;
}
