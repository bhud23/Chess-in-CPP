#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include "gamemanager.h"
#include <iostream>


class TextDisplay : public Observer {
    GameManager &game;
    int row, col, sidenums;
    char bottomletters = 'a';
    
    std::ostream &out = std::cout;

    public:
<<<<<<< HEAD
    TextDisplay (GameManager &game, int row, int col, int sidenums);
=======
<<<<<<< HEAD
    	TextDisplay (GameManager &game);
    	~TextDisplay () = default;
    private:
	void display () override;
=======
    TextDisplay (GameManager &game);
>>>>>>> a0362db86f5007020a52cb1b29da2c1f27998905
    ~TextDisplay () = default;
    private:
    void display() override;
>>>>>>> daaa7cd09337e60175f8fb14b1558f8fb66394bc
};


#endif

