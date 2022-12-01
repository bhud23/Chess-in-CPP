#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
    virtual void display() = 0;
    virtual ~Observer () = default;
};

#endif
