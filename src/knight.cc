#include "knight.h"

Knight::Knight (Board &b, int x, int y, char team):
    piece{b, next, x, y, team}, first_move{true} {}

int Knight::getX () { return x; }
int Knight::getY () { return y; }
char Knight::getTeam () { return team; }
char Knight::getType () {
    if (team == 'w') return 'p';
    else return 'P'
}
void Knight::setDead (int x1, int y1) {
    if (x1 == x && y1 == y) alive = false;
    else { next->setAlive(x1, y1) }
}
void Knight::setAlive (int x1, int y1) {
    if (x1 == x && y1 == y) alive = true;
    else { next->setAlive(x1, y1) }
}
char Knight::getTile (int x1, int y1) {
    if (x1 == x && y1 == y && team == 'w') return 'p';
    else if (x1 == x && y1 == y) return 'P';
    else return next->getTile(x1, y1);
}
bool Knight::validMove (int x1, int y1) {
    
}