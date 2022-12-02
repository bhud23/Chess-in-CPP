#include "game.h"

Game::Game (Board **b):
    move{0}, head{b}, white_king{-1, -1}, black_king{-1, -1} {}

char Game::pieceAt (int x, int y) {
    return (*head)->getTile(x, y);
}

std::pair<int, int> Game::getCoords(std::string inp) {
    std::pair<int, int> res {-1, -1};
    if (inp.length() != 2) return res;
    if (inp[0] == "a") res.first = 0;
    if (inp[0] == "b") res.first = 1;
    if (inp[0] == "c") res.first = 2;
    if (inp[0] == "d") res.first = 3;
    if (inp[0] == "e") res.first = 4;
    if (inp[0] == "f") res.first = 5;
    if (inp[0] == "g") res.first = 6;
    if (inp[0] == "g") res.first = 7;

    if (inp[0] == "1") res.second = 0;
    if (inp[0] == "2") res.second = 1;
    if (inp[0] == "3") res.second = 2;
    if (inp[0] == "4") res.second = 3;
    if (inp[0] == "5") res.second = 4;
    if (inp[0] == "6") res.second = 5;
    if (inp[0] == "7") res.second = 6;
    if (inp[0] == "8") res.second = 7;
    return res;
}

void Game::removePiece () {
    std::string inp;
    (if cin >> inp) {
                std::pair<int, int> coords = getCoords(inp);
                if (coords.first != -1 && coords.second != -1) head->setDead(coords.first, coords.second);
                else std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
            }
            else {
                std::cout "Fatal error" << std::endl;
    }
}

void Game::placePiece () {
    // big fat ugly function to create pieces
    std::string inp;
    if (cin >> inp;) {
        if (inp == "K") {
            std::pair<int, int> coords = getCoords(inp);
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_')
                    *head = new King {*head, 3, 7, 'b'};
                    // if in check undo this
                else std::cout << "A piece already occupies " << inp << std::endl;
            }
            else std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
        }
        if (inp == "k") {
            std::pair<int, int> coords = getCoords(inp);
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_')
                    *head = new King {*head, 3, 7, 'b'};
                    // if in check undo this
                else std::cout << "A piece already occupies " << inp << std::endl;
            }
            else std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
        }
        // queen case
        // bishop case
        // knight case
        // rook case
        // pawn case
        if (inp == "P") {
            std::pair<int, int> coords = getCoords(inp);
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_')
                    *head = new Pawn {*head, coords.first, 7, 'b'};
                    // if in check undo this
                else std::cout << "A piece already occupies " << inp << std::endl;
            }
            else std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
        }
        if (inp == "p") {
            std::pair<int, int> coords = getCoords(inp);
            if (coords.first != -1 && coords.second != -1) {
                char tile = this->pieceAt(coords.first, coords.second);
                if (tile == ' ' || tile == '_')
                    *head = new Pawn {*head, 3, 7, 'b'};
                    // if in check undo this
                else std::cout << "A piece already occupies " << inp << std::endl;
            }
            else std::cout << "Invalid command " << inp << " use --help for more options" << std::endl;
        }
    }
    else {
        std::cout "Fatal error" << std::endl;
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
}

void Game::customSetup () {
    std::string inp;
    bool valid_white_king = false;
    bool valid_black_king == false;
    while (cin >> inp) {
        if (inp == "--help") {
            std::cout << "<piece> <coordinate>" << std::endl;
            std::cout << "\t - <piece> is one of K, k, Q, q, B, b, N, n, R, r, P, p" << std::endl;
            std::cout << "\t - <coordinate> takes the form <letter><number>" << std::endl;
        }
        else if (inp == "+") {
            if (cin >> inp) {
                this->placePiece();
            }
        }
        else if (inp == "-"){
            this->removePiece();
        }
        else if (inp == "=") {
            move++;
        }
        else if (inp == "done") {
            if (valid_black_king && valid_white_king) return;
            else std::cout << "Invalid king placement" << std::endl;
        }
    }
}

void Game::movePiece (int x1, int y1, int x2, int y2) {
    return;
}

bool Game::isCheck (char team) {
    return false;
}

bool Game::isCheckMate (char team) {
    return false;
}

bool Game::isStalemate() {
    return false;
}

void Game::printScore () {
    return;
}
