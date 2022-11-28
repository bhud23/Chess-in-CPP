#include "piece.h"

Piece::Piece (Board &b, Piece *next, int x, int y, char team):
    b{b}, xnext{next}, {x}, y{y}, team{team}, alive{true} {}
