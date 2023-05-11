#ifndef PEG_H
#define PEG_H

#include <string>
#include <iostream>
#include "Color.h"

using namespace std;

class Peg
{
    private:
    Color c;
    
    public:
    Peg();
    ~Peg();
    
    Peg(Color);
    Peg(const Peg &p);

    Color getPeg();
    void setPeg(Color);
    void setPeg(int);

    void convertPeg(string);

    bool operator==(Peg &p1) {
        return (getPeg() == p1.getPeg());
    }
};

#endif