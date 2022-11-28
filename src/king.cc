#include "king.h"

King::King (Board &b, int x, int y, char team):
    piece{b, next, x, y, team}, first_move{true} {}

int King::getX () { return x; }
int King::getY () { return y; }
char King::getTeam () { return team; }
char King::getType () {
    if (team == 'w') return 'p';
    else return 'P'
}
void King::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1) }
}
void King::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1) }
}
char King::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w') return 'p';
    else if (x1 == x && y1 == y) return 'P';
    else return next->getTile(x1, y1);
}
bool King::validMove (int x1, int y1) {
    
}