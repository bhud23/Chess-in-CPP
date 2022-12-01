#ifndef _GRAPHICDISPLAY_H
#define _GRAPHICDISPLAY_H

#include "window.h"
#include "observer.h"
#include "gamemanager.h"
#include <string>

class graphicDisplay : public Observer {
    GameManager &game;
    Xwindow win;
    const int width = 900;
    const int height = 900;
    public:
        GraphicDisplay (GameManager &game);
        ~GraphicDisplay () = default;
};

#endif