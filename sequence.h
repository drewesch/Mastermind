#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "peg.h"
#include "Color.h"
using namespace std;

class Sequence
{
    private:
    Peg* code;

    public:
    Sequence();
    ~Sequence();
    
    Sequence(Peg*);
    Sequence(const Sequence &s);
    
    Peg* getSequence();
    void setSequence(Peg*);

    string sequenceToString();

    bool operator==(Sequence &s1);
};

#endif