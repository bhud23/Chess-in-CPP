#include "blank.h"

char Blank::getTile (int x, int y) {
    if ((x + y) % 2 == 1) return '_';
    return ' ';
}

bool Blank::validMove (int x1, int y1, int x2, int y2) {
    return false;
}
