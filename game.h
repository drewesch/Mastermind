#ifndef GAME_H
#define GAME_H

#include "sequence.h"
#include "peg.h"
#include "Color.h"
#include "time.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Game
{
    private:
    int count;
    Sequence hiddenCode;
    Sequence guess;

    bool guessFeedback();
    
    public:
    Game();
    ~Game();
    
    Game(int);
    
    int getCount();
    Sequence getHiddenCode();
    Sequence getGuess();

    void setCount(int);
    void setHiddenCode(Sequence);
    void setGuess(Sequence);

    void createCode();
    bool iterateGuess();
    void endGamePrint();
};

#endif