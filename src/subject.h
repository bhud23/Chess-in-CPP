#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <vector>

class Observer;

class Subject {
    vector <Observer *> observers;
    public:
        void attach (Observer *ob);
        void detach (Observer *ob);
        void displayBoard (); // like notify() function
};

#endif