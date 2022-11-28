#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include <vector>

class Observer;

class GameManager {
    vector <Observer *> observers;
    public:
        void attach (Observer *ob);
        void detach (Observer *ob);
        void displayBoard (); // like notify() function
        virtual void getTile (int x1, int y1) = 0; 
};

#endif