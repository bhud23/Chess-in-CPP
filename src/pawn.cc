#include "pawn.h"
#include <iostream>

Pawn::Pawn (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

Pawn::~Pawn () {
    delete next;
}

void Pawn::move (int x1, int y1, int x2, int y2) {
    std::cout "Pawn move called" << std::endl;
    if (x == x1 && y == y1) {
        x = x2;
        y = y2;
    }
    else return next->move(x1, y2, x2, y2);
}

char Pawn::getTeam () { return team; }
char Pawn::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
char Pawn::getType () {
    if (team == 'w') return 'p';
    else return 'P';
}
void Pawn::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1); }
}
void Pawn::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1); }
}
char Pawn::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w' && alive) return 'p';
    else if (x1 == x && y1 == y && alive) return 'P';
    else return next->getTile(x1, y1);
}
bool Pawn::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}

void Pawn::undoMove(int x1, int y1, int x2, int y2) {
    if (x != x1 && y != y2) {
        x = x2;
        y = y2;
    }
    else {
        return next->undoMove(x1, y1, x2, y2);
    }
}
