#include "knight.h"

Knight::Knight (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

Knight::~Knight () {
    delete next;
}

int Knight::getX () { return x; }
int Knight::getY () { return y; }
char Knight::getTeam () { return team; }
char Knight::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
char Knight::getType () {
    if (team == 'w') return 'n';
    else return 'N';
}
void Knight::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1); }
}
void Knight::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1); }
}
char Knight::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w' && alive) return 'n';
    else if (x1 == x && y1 == y && alive) return 'N';
    else return next->getTile(x1, y1);
}
bool Knight::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}

void Knight::undoMove(int x1, int y1, int x2, int y2) {
    if (x != x1 && y != y2) {
        x = x2;
        y = y2;
    }
    else {
        return next->undoMove(x1, y1, x2, y2);
    }
}