#include "rook.h"

Rook::Rook (Board &b, int x, int y, char team):
    piece{b, next, x, y, team}, first_move{true} {}

int Rook::getX () { return x; }
int Rook::getY () { return y; }
char Rook::getTeam () { return team; }
char Rook::getType () {
    if (team == 'w') return 'r';
    else return 'R'
}
void Rook::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1) }
}
void Rook::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1) }
}
char Rook::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w') return 'r';
    else if (x1 == x && y1 == y) return 'R';
    else return next->getTile(x1, y1);
}
bool Rook::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
}