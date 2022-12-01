#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include "gamemanager.h"
#include <iostream>


class TextDisplay : public Observer {
    GameManager &game;
    int row = 8, col = 8, sidenums = 8;
    char bottomletters = 'a';
    
    std::ostream &out = std::cout;

    public:
<<<<<<< HEAD
    	TextDisplay (GameManager &game);
    	~TextDisplay () = default;
    private:
	void display () override;
=======
    TextDisplay (GameManager &game);
    ~TextDisplay () = default;
    void display() override;
>>>>>>> daaa7cd09337e60175f8fb14b1558f8fb66394bc
};


#endif

