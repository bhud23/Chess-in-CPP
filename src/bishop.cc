#include "bishop.h"

Bishop::Bishop (Board &b, int x, int y, char team):
    piece{b, next, x, y, team}, first_move{true} {}

int Bishop::getX () { return x; }
int Bishop::getY () { return y; }
char Bishop::getTeam () { return team; }
char Bishop::getType () {
    if (team == 'w') return 'b';
    else return 'B'
}
void Bishop::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1) }
}
void Bishop::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1) }
}
char Bishop::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w') return 'b';
    else if (x1 == x && y1 == y) return 'B';
    else return next->getTile(x1, y1);
}
bool Bishop::validMove (int x1, int y1) {
    
}