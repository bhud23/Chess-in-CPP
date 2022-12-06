#include "pawn.h"
#include <iostream>

Pawn::Pawn (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

Pawn::~Pawn () {
    delete next;
}

void Pawn::move (int x1, int y1, int x2, int y2) {
    if (x == x1 && y == y1 && alive) {
        this->x = x2;
        this->y = y2;
	return;
    }
    else {
	 return next->move(x1, y1, x2, y2);
    }
}

char Pawn::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
void Pawn::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setDead(x1, y1); }
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
void Pawn::setFirstMove (int x, int y) {
    first_move = false;
}
bool Pawn::getFirstMove (int x, int y) {
    return first_move;
}
