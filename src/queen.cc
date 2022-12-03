#include "queen.h"

Queen::Queen (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

Queen::~Queen () {
    delete next;
}

int Queen::getX () { return x; }
int Queen::getY () { return y; }
char Queen::getTeam () { return team; }
char Queen::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
char Queen::getType () {
    if (team == 'w') return 'q';
    else return 'Q';
}
void Queen::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1); }
}
void Queen::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1); }
}
char Queen::getTile (int x1, int y1 ) {
    if (x1 == x && y1 == y && team == 'w' && alive) return 'q';
    else if (x1 == x && y1 == y && alive) return 'Q';
    else return next->getTile(x1, y1);
}
bool Queen::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}