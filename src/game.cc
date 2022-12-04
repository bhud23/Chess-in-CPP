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
            std::cout << " + <piece> <coordinate>" << std::endl;
            std::cout << "\t - <piece> is one of K, k, Q, q, B, b, N, n, R, r, P, p" << std::endl;
            std::cout << "\t - <coordinate> is composed of a letter a-h and number 1-8" << std::endl;
            std::cout << " - <piece> <coordinate>" << std::endl;
            std::cout << " = <colour>" << std::endl;
            std::cout << "\t - where <colour> is either <white> or <black>" << std::endl;
            std::cout << "done" << std::endl;
            std::cout << "\t - to leave setup mode (can only be performed if setup is valid" << std::endl;
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
            if (std::cin >> inp) {
                if (inp == "white") move = 0;
                else move = 1;
            }
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
            std::cout << "Invalid command " << inp << " use --help to display options." << std::endl;
            gm->displayBoard();
        }
    }
}

void Game::setAlive (int x1, int y1) {
    return (*head)->setAlive(x1, y1);
}

void Game::setDead (int x1, int y1) {
    return (*head)->setDead(x1, y1);
}

bool Game::pawnValidMove(int x1, int y1, int x2, int y2) {
	std::cout << "made it here\n";
    char team = (*head)->getTeam(x1, y1);
    int dir = 1;
    if (team == 'b') dir = -1; 
    if ((x2 - x1 == 0 || x2 - x1 == 1 || x2 - x1 == -1) && (y1 + dir == y2)) {
        this->setDead(x2, y2);
        (*head)->setX(x1, y1, x2, y2);
        (*head)->setY(x2, y1, x2, y2);
        if (this->isCheck(team)) {
            (*head)->setX(x2, y2, x1, y1);
            (*head)->setY(x1, y2, x1, y1);
            this->setAlive(x2, y2);
            return false;
        }
	std::cout << "Also made it here\n";
    }
    if ((team == 'B' && y2 == 0) || (team == 'w' && y2 == 7)) {
        std::string inp;
        while (std::cin >> inp) {
            if (inp == "Q") {
                this->setDead(x2, y2);
                *head = new Queen {*head, x2, y2, team};
                break;
            }
            else if (inp == "R") {
                this->setDead(x2, y2);
                *head = new Queen {*head, x2, y2, team};
                break;
            }
            else if (inp == "B") {
                this->setDead(x2, y2);
                *head = new Queen {*head, x2, y2, team};
                break;
            }
            else if (inp == "N") {
                this->setDead(x2, y2);
                *head = new Queen {*head, x2, y2, team};
                break;
            }
            else {
                std::cout << "Invalid piece " << inp << " ensure the piece you enter is capitalized" << std::endl;
            }
        }
    }
    return true;
}

bool Game::rookValidMove(int x1, int y1, int x2, int y2) {
    char team = (*head)->getTeam(x1, y1);
    int newX = x2 - x1;
    int newY = y2 - y1;

    if ((newX == 0 && newY != 0) || (newY == 0 && newX != 0)) {
        int delta_x = 1;
        int delta_y = 1;
        if (newX == 0) delta_x = 0;
        if (newY == 0) delta_y = 0;
        for (int i = newX + delta_x; i != newX ; i += delta_x) {
            for (int j = newY + delta_y; j != newY; j += delta_y) {
                char tile = (*head)->getTile(i, j);
                if (tile != ' ' || tile != '_') return false;
            }
        }
        this->setDead(x2, y2);
        (*head)->setX(x1, y1, x2, y2);
        (*head)->setY(x2, y1, x2, y2);
        if (this->isCheck(team)) {
            (*head)->setX(x2, y2, x1, y1);
            (*head)->setY(x1, y2, x1, y1);
            this->setAlive(x2, y2);
            return false;
        }
        return true;
    }
    return false;
}
bool Game::knightValidMove(int x1, int y1, int x2, int y2) {
    char team = (*head)->getTeam(x1, y1);
    int newX = x2 - x1;
    int newY = y2 - y1;
    if ((newX == 1 || newX == -1) && (newY == 2 || newY == -2)) {
        this->setDead(x2, y2);
        (*head)->setX(x1, y1, x2, y2);
        (*head)->setY(x2, y1, x2, y2);
        if (this->isCheck(team)) {
            (*head)->setX(x2, y2, x1, y1);
            (*head)->setY(x1, y2, x1, y1);
            this->setAlive(x2, y2);
            return false;
        }
        return true;
    }
    else if ((newX == 2 || newX == -2) && (newY == 1 || newY == -1)) {
        this->setDead(x2, y2);
        (*head)->setX(x1, y1, x2, y2);
        (*head)->setY(x2, y1, x2, y2);
        if (this->isCheck(team)) {
            (*head)->setX(x2, y2, x1, y1);
            (*head)->setY(x1, y2, x1, y1);
            this->setAlive(x2, y2);
            return false;
        }
        return true;
    }
    else return false;
}

bool Game::bishopValidMove(int x1, int y1, int x2, int y2) {
    char team = (*head)->getTeam(x1, y1);
    int newX = x2 - x1;
    int newY = y2 - y1;

    int dist = newX;
    if (dist < 0) dist *= -1;

    if (newX != -1 * newY || newX != newY) return false;
    else {
        int delta_x = 1;
        if (newX < 0) delta_x = -1;
        int delta_y = 1;
        if (newY < 0) delta_y = -1;
        for (int i = newX + delta_x; i != newX ; i += delta_x) {
            for (int j = newY + delta_y; j != newY; j += delta_y) {
                char tile = (*head)->getTile(i, j);
                if (tile != ' ' || tile != '_') return false;
            }
        }
        this->setDead(x2, y2);
        (*head)->setX(x1, y1, x2, y2);
        (*head)->setY(x2, y1, x2, y2);
        if (this->isCheck(team)) {
            (*head)->setX(x2, y2, x1, y1);
            (*head)->setY(x1, y2, x1, y1);
            this->setAlive(x2, y2);
            return false;
        }
        return true;
    }
}

bool Game::queenValidMove(int x1, int y1, int x2, int y2) {
    return this->rookValidMove(x1, y1, x2, y2) || this->bishopValidMove(x1, y1, x2, y2);
    
}
bool Game::kingValidMove(int x1, int y1, int x2, int y2) {
    char team = (*head)->getTeam(x1, y1);
    int newX = x2 - x1;
    int newY = y2 - y1;

    if (newX < 0) newX *= -1;
    if (newY < 0) newY *= -1;

    if ((newX == 0 || newX == 1) && (newY == 0 || newY == 1)) {
        this->setDead(x2, y2);
        (*head)->setX(x1, y1, x2, y2);
        (*head)->setY(x2, y1, x2, y2);
        if (this->isCheck(team)) {
            (*head)->setX(x2, y2, x1, y1);
            (*head)->setY(x1, y2, x1, y1);
            this->setAlive(x2, y2);
            return false;
        }
	return true;
    }
    else return false;
}

bool Game::validMove (int x1, int y1, int x2, int y2) {
    if (0 > x1 || x1 > col || 0 > y1 || y1 > row || 0 > x2 || x2 > 0 || x2 > col || 0 > y2 || y2 > row) return false;
    if ((*head)->getTeam(x1, y1) == (*head)->getTeam(x1, y2)) return false; // cannot take own piece
    char piece = (*head)->getTile(x1, y1);
    if (piece == 'P' || piece == 'p') return pawnValidMove(x1, y1, x2, y2);
    else if (piece == 'R' || piece == 'r') return rookValidMove(x1, y1, x2, y2);
    else if (piece == 'B' || piece == 'b') return bishopValidMove(x1, y1, x2, y2);
    else if (piece == 'N' || piece == 'n') return knightValidMove(x1, y1, x2, y2);
    else if (piece == 'Q' || piece == 'q') return queenValidMove(x1, y1, x2, y2);
    else if (piece == 'K' || piece == 'k') return kingValidMove(x1, y1, x2, y2);
    else return false;
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
                if (this->validMove(j, i, x, y)) return true;
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
                    if (tile != ' ' && tile != team && this->validMove(j, i, l, k)) return false;
                }
            }
        }
    }
    return true;
}

bool Game::isStalemate() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char tile = (*head)->getTile(j, i);
            if (tile == ' ' || tile == '_') continue;
            for (int k = 0; k < row; k++) {
                for (int l = 0; l < col; l++) {
                    if (this->validMove(j, i, l, k)) return false;
                }
            }
        }
    }
    return true;
}

char Game::playGame () {
    std::cout << "The game has started. Use  --help to display options" << std::endl;
    std::string inp;
    while (true) {
	Player *player;
        if (move % 2 == 0) {
                player = player1;
                    std::cout << "White's turn" << std::endl;
        }
        else if (move % 2 == 1) {
        	player = player2;
                std::cout << "Black's turn" << std::endl;
        }
    if (std::cin >> inp) {
        if (this->isStalemate()) return 'd';
        else if (this->isCheckmate('w')) return 'b';
        else if (this->isCheckmate('b')) return 'w';
	
        if (inp == "move") {
		std::pair<int, int> piece = player->getMove();
              	std::pair<int, int> newMove = player->getMove();
                std::cout << "---> x1=" << piece.first << " y1=" << piece.second << " x2=" << newMove.first << " y2=" << newMove.second << std::endl;
                bool res = this->validMove(piece.first, piece.second, newMove.first, newMove.second);
        if (!res) {
                std::cout << "Invalid move" << std::endl;
        }
	else {
            move++;
            gm->displayBoard();
	    continue;
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
        else if (inp == "undo") {
            if (move % 2 == 0) {
                std::cout << "undoing White's move" << std::endl;
            }
            else {
                std::cout << "undoing Black's move" << std::endl;
            }
            gm->displayBoard();
            // undo the move
        }
        else if (inp == "--help") {
            std::cout << "Commands:" << std::endl;
            std::cout << "- move <coordinate> <coordinate>" << std::endl;
            std::cout << "\twhere <coordinate> is composed of a letter a-h and number 1-8" << std::endl;
            std::cout << " - resign" << std::endl;
        }
        else {
            std::cout << " Invalid input " << inp << " use --help for more options" << std::endl; 
        }
    }
    std::cout << "Fatal Error" << std::endl;
    return 'd';
}
}

void Game::setPlayer1 (Player *p){
    player1 = p;
}

void Game::setPlayer2 (Player *p) {
    player2 = p;
}
