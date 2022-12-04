#include "blank.h"

Blank::Blank () {
    return;
}

Blank::~Blank () {
    return;
}

char Blank::getTile (int x, int y) {
    if ((x + y) % 2 == 1) return '_';
    return ' ';
}

bool Blank::validMove (int x1, int y1, int x2, int y2) {
    return false;
}

void Blank::setX (int x1, int y1, int x2, int y2) {
    return;
}

void Blank::setY (int x1, int y1, int x2, int y2) {
    return;
}

char Blank::getTeam () {
    return ' ';
}

char Blank::getTeam (int x1, int y1) {
    return ' ';
}

char Blank::getType () {
    return ' ';
}

void Blank::setDead (int x, int y) {
    return;
}

void Blank::setAlive (int x, int y) {
    return;
}

void Blank::undoMove(int x1, int y1, int x2, int y2) {
    return;
}
