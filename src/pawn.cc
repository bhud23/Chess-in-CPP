#include "pawn.h"

Pawn::Pawn (Board &b, Piece *next, int x, int y, char team):
    b{b}, next{next}, x{x}, y{y}, team{team}, alive{true} {}

int Pawn::getX () { return x; }
int Pawn::getY () { return y; }
char Pawn::getTeam () { return team; }
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
    if (x1 == x && y1 == y && team == 'w') return 'p';
    else if (x1 == x && y1 == y) return 'P';
    else return next->getTile(x1, y1);
}
bool Pawn::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}