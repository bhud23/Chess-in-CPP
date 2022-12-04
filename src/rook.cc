#include "rook.h"

Rook::Rook (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

Rook::~Rook () {
    delete next;
}

void Queen::move (int x1, int y1, int x2, int y2) {
    if (x == x1 && y == y1) {
        x = x2;
        y = y2;
    }
    else return next->move(x1, y2, x2, y2);
}

char Rook::getTeam () { return team; }
char Rook::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
char Rook::getType () {
    if (team == 'w') return 'r';
    else return 'R';
}
void Rook::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1); }
}
void Rook::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1); }
}
char Rook::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w' && alive) return 'r';
    else if (x1 == x && y1 == y && alive) return 'R';
    else return next->getTile(x1, y1);
}
bool Rook::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}

void Rook::undoMove(int x1, int y1, int x2, int y2) {
    if (x != x1 && y != y2) {
        x = x2;
        y = y2;
    }
    else {
        return next->undoMove(x1, y1, x2, y2);
    }
}
