#include "bishop.h"

Bishop::Bishop (Board &b, Piece *next, int x, int y, char team):
    b{b}, next{next}, x{x}, y{y}, team{team}, alive{true} {}

int Bishop::getX () { return x; }
int Bishop::getY () { return y; }
char Bishop::getTeam () { return team; }
char Bishop::getType () {
    if (team == 'w') return 'b';
    else return 'B';
}
void Bishop::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1); }
}
void Bishop::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1); }
}
char Bishop::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w') return 'b';
    else if (x1 == x && y1 == y) return 'B';
    else return next->getTile(x1, y1);
}
bool Bishop::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}