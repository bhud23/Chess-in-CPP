#include "bishop.h"

Bishop::Bishop (Board *next, int x, int y, char team):
    next{next}, x{x}, y{y}, team{team}, alive{true} {}

Bishop::~Bishop () {
    delete next;
}

void Bishop::move (int x1, int y1, int x2, int y2) {
    if (x == x1 && y == y1) {
        x = x2;
        y = y2;
    }
    else return next->move(x1, y2, x2, y2);
}

char Bishop::getTeam () { return team; }
char Bishop::getTeam (int x1, int y1) {
    if (x == x1 && y == y1) return team;
    else return next->getTeam(x1, y1);
}
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
    if (x1 == x && y1 == y && team == 'w'&& alive) return 'b';
    else if (x1 == x && y1 == y && alive) return 'B';
    else return next->getTile(x1, y1);
}
bool Bishop::validMove (int x1, int y1, int x2, int y2) {
    if (x1 != x || y1 != y) return next->validMove(x1, y1, x2, y2);
    return false;
}

void Bishop::undoMove (int x1, int y1, int x2, int y2) {
	if (x1 != x || y1 != y) {
		x = x2;
		y = y2;
	}
	else {
		return next->undoMove(x1, y1, x2, y2);
	}
}
