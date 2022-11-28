#include "gamemanager.h"

void GameManager::attach (Observer *ob) {
    observers.push_back(ob);
}

void GameManager::detach (Observer *ob) {
    int i = 0;
    for (auto o : observers) {
        if (ob == o) break;
        i++;
    }
    observers.erase(observers.begin() + i);
}

void GameManager::displayBoard () {
    for (auto o : observers) {
        o->display();
    }
}

GameManager::~GameManager () {
    for (auto o : observers) {
        delete o;
    }
}