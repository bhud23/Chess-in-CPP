#include "blank.h"

void Blank::getTile (int x, int y) {
    if (x + y % 2) return ' ';
    return '_';
}