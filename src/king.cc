#include "king.h"

King::King (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

King::~King () {
    delete next;
}

int King::getX () { return x; }
int King::getY () { return y; }
char King::getTeam () { return team; }
char King::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
char King::getType () {
    if (team == 'w') return 'k';
    else return 'K';
}
void King::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1); }
}
void King::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1); }
}
char King::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w' && alive) return 'k';
    else if (x1 == x && y1 == y && alive) return 'K';
    else return next->getTile(x1, y1);
}
bool King::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}

void King::undoMove(int x1, int y1, int x2, int y2) {
    if (x != x1 && y != y2) {
        x = x2;
        y = y2;
    }
    else {
        return next->undoMove(x1, y1, x2, y2);
    }
}
