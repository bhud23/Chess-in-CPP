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
    Game game {&head, gm};
    std::string inp;


    Observer *txt = new TextDisplay {*gm, 8, 8, 8};
    gm->attach(txt);
    Observer *graph = new GraphicDisplay {*gm, 8, 8};
    gm->attach(graph);
    
    std::cout << "Welcome to Chess - the CS246 orignal game" << std::endl;
    std::cout << "Here is what a default game board looks like" << std::endl;
    gm->displayBoard();
    while (std::cin >> inp) {
        // if move % 2 == 1, then it is whites turn, blacks turn otherwise
        if (inp == "game") {
		    std::cin >> inp;
            if (inp == "human") {}
            else if (inp == "computer[1]") {}
        }
        else if (inp == "setup") {
	        std::cin >> inp;
		if (inp == "default") {
			game.defaultSetup();
		}
		else if (inp == "custom") {
			game.customSetup();
		}
		else {
			std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
		}	
        }
        else if (inp == "--help") {
            std::cout << "Commands:" << std::endl;
            std::cout << "- game <white-player> <black-player>" << std::endl;
            std::cout << "\twhere <white-player> or <black-player> can be <human> or <computer[x]>\n" << std::endl;
            std::cout << " - setup" << std::endl;
            std::cout << "\t followed by either <default> or <custom>" << std::endl;
        }
        else {
            std::cout << "Invalid Input\n";
        }
    }
    std::cout << "Final Score:" << std::endl;
    std::cout << "White: " << white_score << std::endl;
    std::cout << "Black: " << black_score << std::endl;
    return 0;
}
