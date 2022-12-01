#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include <iostream>


class TextDisplay : public Observer {
    GameManager &game;
    int row = 10, col = 9, sidenums = 8;
    char bottomletters = 'a';
    
    std::ostream &out = std::cout;

    public:
    void display() override;
};


#endif

