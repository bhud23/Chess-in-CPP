#include "game.h"

Game::Game (Board **b, GameManager *gm, Player *player1, Player *player2):
    move{0}, head{b}, gm{gm}, white_king{-1, -1}, black_king{-1, -1}, player1{player1}, player2{player2} {}


Game::~Game () {
	delete gm;
    delete player1;
    delete player2;
}

char Game::pieceAt (int x, int y) {
    return (*head)->getTile(x, y);
}

std::pair<int, int> Game::getCoords() {
    std::string inp;
    std::pair<int, int> res {-1, -1};
    if (std::cin >> inp) {
   	 if (inp.length() != 2) return res;
	 res.first = inp[0] - 'a';
	 res.second = inp[1] - '1';
	 if (0 > res.first || res.first > 7) res.first = -1;
	 if (0 > res.second || res.second > 7) res.second = -1;
    }
    else {
    	std::cout << "Could not interpret " << inp << std::endl;
    }
    return res;
}

void Game::removePiece () {
    std::string inp;
    if (std::cin >> inp) {
                std::pair<int, int> coords = getCoords();
                if (coords.first != -1 && coords.second != -1) {
                    (*head)->setDead(coords.first, coords.second);
                    char tile = this->pieceAt(coords.first, coords.second);
                    if ('a' <= tile && tile <= 'z' && this->isCheck('b')) (*head)->setAlive (coords.first, coords.second);
                    else if ('A' <= tile && tile <= 'Z' && this->isCheck('w')) (*head)->setAlive (coords.first, coords.second);
                }
                else std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
            }
    else {
        std::cout << "Fatal error" << std::endl;
    }
}

void Game::placePiece () {
    // big fat ugly function to create pieces
    std::string inp;
    if (std::cin >> inp) {
        if (inp == "K") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                std::cout << "x=" << coords.first << " y=" << coords.second << std::endl;
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new King {*head, coords.first, coords.second, 'b'};
                    // if in check undo this
                    if (this->isCheck('b')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "The king cannot be placed in check" << std::endl;
                    }
                    else {
                        this->black_king.first = coords.first;
                        this->black_king.second = coords.second;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        else if (inp == "k") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new King {*head, coords.first, coords.second, 'w'};
                    // if in check undo this
                    if (this->isCheck('w')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "The king cannot be placed in check" << std::endl;
                    }
                    else {
                        this->white_king.first = coords.first;
                        this->white_king.second = coords.second;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        // queen case
        else if (inp == "Q") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Queen {*head, coords.first, coords.second, 'b'};
                    // if in check undo this
                    if (this->isCheck('w')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        else if (inp == "q") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Queen {*head, coords.first, coords.second, 'w'};
                    // if in check undo this
                    if (this->isCheck('b')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        // bishop case
        else if (inp == "B") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Bishop {*head, coords.first, coords.second, 'b'};
                    // if in check undo this
                    if (this->isCheck('w')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        else if (inp == "b") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Bishop {*head, coords.first, coords.second, 'w'};
                    // if in check undo this
                    if (this->isCheck('b')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        // knight case
        else if (inp == "N") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Knight {*head, coords.first, coords.second, 'b'};
                    // if in check undo this
                    if (this->isCheck('w')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        else if (inp == "n") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Knight {*head, coords.first, coords.second, 'w'};
                    // if in check undo this
                    if (this->isCheck('b')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        // rook case
        else if (inp == "R") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Rook {*head, coords.first, coords.second, 'b'};
                    // if in check undo this
                    if (this->isCheck('w')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        else if (inp == "r") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Rook {*head, coords.first, coords.second, 'w'};
                    // if in check undo this
                    if (this->isCheck('b')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        // pawn case
        else if (inp == "P") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1 && coords.second != 0) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Pawn {*head, coords.first, coords.second, 'b'};
                    // if in check undo this
                    if (this->isCheck('w')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
        else if (inp == "p") {
            std::pair<int, int> coords = getCoords();
            if (coords.first != -1 && coords.second != -1 && coords.second != 7) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_') {
                    *head = new Pawn {*head, coords.first, coords.second, 'w'};
                    // if in check undo this
                    if (this->isCheck('b')) {
                        (*head)->setDead(coords.first, coords.second);
                        std::cout << "Cannot place piece that would put the king in check" << std::endl;
                    }
                }
                else {std::cout << "A piece already occupies " << inp << std::endl;}
            }
            else {std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;}
        }
    }
    else {
        std::cout << "Fatal error" << std::endl;
    }
}

void Game::defaultSetup () {
    // setup white pieces
    for (int i = 0; i < 8; i++) {
        *head = new Pawn {*head, i, 1, 'w'};
    }
    *head = new Rook {*head, 0, 0, 'w'};
    *head = new Rook {*head, 7, 0, 'w'};
    *head = new Knight {*head, 1, 0, 'w'};
    *head = new Knight {*head, 6, 0, 'w'};
    *head = new Bishop {*head, 2, 0, 'w'};
    *head = new Bishop {*head, 5, 0, 'w'};
    *head = new Queen {*head, 3, 0, 'w'};
    *head = new King {*head, 4, 0, 'w'};
    white_king.first = 4;
    white_king.second = 0;
    // setup black pieces
    for (int i = 0; i < 8; i++) {
        *head = new Pawn {*head, i, 6, 'b'};
    }
    *head = new Rook {*head, 0, 7, 'b'};
    *head = new Rook {*head, 7, 7, 'b'};
    *head = new Knight {*head, 1, 7, 'b'};
    *head = new Knight {*head, 6, 7, 'b'};
    *head = new Bishop {*head, 2, 7, 'b'};
    *head = new Bishop {*head, 5, 7, 'b'};
    *head = new Queen {*head, 4, 7, 'b'};
    *head = new King {*head, 3, 7, 'b'};
    black_king.first = 3;
    black_king.second = 7;
    std::cout << "Board default constructed" << std::endl;
    gm->displayBoard();
}

void Game::customSetup () {
    std::string inp;
    while (std::cin >> inp) {
        if (inp == "--help") {
            std::cout << "<piece> <coordinate>" << std::endl;
            std::cout << "\t - <piece> is one of K, k, Q, q, B, b, N, n, R, r, P, p" << std::endl;
            std::cout << "\t - <coordinate> takes the form <letter><number>" << std::endl;
        }
        else if (inp == "+") {
                this->placePiece();
                gm->displayBoard();
        }
        else if (inp == "-"){
            this->removePiece();
            gm->displayBoard();
        }
        else if (inp == "=") {
            move++;
        }
        else if (inp == "done") {
            if (black_king.first == -1 || black_king.second == -1) {
                std::cout << "Cannot exit - Black King not placed" << std::endl;
                gm->displayBoard();
            }
            else if (white_king.first == -1 || white_king.second == -1) {
                std::cout << "Cannot exist - White King is not placed" << std::endl;
                gm->displayBoard();
            }
            else return;
        }
        else {
            std::cout << "Invalid king placement" << std::endl;
            gm->displayBoard();
        }
    }
}

void Game::movePiece (int x1, int y1, int x2, int y2) {
    return;
}

bool Game::isCheck (char team) {
    int x = -1;
    int y = -1;
    if (team == 'w') {
        x = white_king.first;
        y = white_king.second;
    }
    else {
        x = black_king.first;
        y = black_king.second;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char tile = (*head)->getTeam(j, i);
            if (tile != ' ' && tile != team) {
                if ((*head)->validMove(j, i, x, y)) return true;
            }
        }
    }
    return false;
}

bool Game::isCheckmate (char team) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < row; k++) {
                for (int l = 0; l < col; l++) {
                    char tile = (*head)->getTeam(j, i);
                    if (tile != ' ' && tile != team && (*head)->validMove(j, i, l, k)) return false;
                }
            }
        }
    }
    return true;
}

bool Game::isStalemate() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < row; k++) {
                for (int l = 0; l < col; l++) {
                    if ((*head)->validMove(j, i, l, k)) return false;
                }
            }
        }
    }
    return true;
}

bool Game::validMove (int x1, int y1, int x2, int y2) {
    if (0 > x1 || x1 > col || 0 > y1 || y1 > row || 0 > x2 || x2 > 0 || x2 > col || 0 > y2 || y2 > row) return false;
    if (!((*head)->validMove(x1, y1, x2, y2))) return false;
    char team = (*head)->getTeam(x1, y1);
    if ('a' <= team && team <= 'z' && this->isCheck('w')) {
        (*head)->undoMove(x2, y2, x1, y1);
        return false;
    }
    else if ('A' <= team && team <= 'Z' && this->isCheck('b')) {
        (*head)->undoMove(x2, y2, x1, y1);
        return false;
    }
    return true;
}

char Game::playGame () {
    std::cout << "The game has started. Use  --help to display options" << std::endl;
    std::string inp;
    while (std::cin >> inp) {
        //if (this->isStalemate()) return 'w';
        //else if (this->isCheckmate('w')) return 'b';
        //else if (this->isCheckmate('b')) return 'w';
        // if not stalemate or checkmate
        if (inp == "move") {
                Player *player;
                if (move % 2) {
                    player = player1;
                    std::cout << "White's turn" << std::endl;
                }
                else {
                    player = player2;
                    std::cout << "Black's turn" << std::endl;
                }
                std::pair<int, int> piece = player->getMove();
                std::pair<int, int> newMove = player->getMove();
                if (!(this->validMove(piece.first, piece.second, newMove.first, newMove.second))) {
                    std::cout << "Invalid move" << std::endl;
                }
                else {
                    move++;
                    gm->displayBoard();
                }
        }
        else if (inp == "resign") {
            if (move % 2 == 0) {
                std::cout << "White has resigned" << std::endl;
                return 'b';
            }
            else {
                std::cout << "Black has resigned" << std::endl;
                return 'w';
            }
        }
        else if (inp == "--help") {
            std::cout << "options <move> <resign>" << std::endl;
        }
        else {
            std::cout << " Invalid input " << inp << " use --help for more options" << std::endl; 
        }
    }
    std::cout << "Fatal Error" << std::endl;
    return 'd';
}


void Game::setPlayer1 (Player *p){
    player1 = p;
}

void Game::setPlayer2 (Player *p) {
    player2 = p;
}
