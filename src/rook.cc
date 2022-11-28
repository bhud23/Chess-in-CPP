#include "rook.h"

Rook::Rook (Board &b, int x, int y, char team):
    piece{b, next, x, y, team}, first_move{true} {}

int Rook::getX () { return x; }
int Rook::getY () { return y; }
char Rook::getTeam () { return team; }
char Rook::getType () {
    if (team == 'w') return 'p';
    else return 'P'
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
    if (x1 == x && y1 == y && team == 'w') return 'p';
    else if (x1 == x && y1 == y) return 'P';
    else return next->getTile(x1, y1);
}
bool Rook::validMove (int x1, int y1) {
    
}