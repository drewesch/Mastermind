#include "sequence.h"

Sequence::Sequence()
{
}

Sequence::~Sequence()
{
}

// User-inputed constructor
Sequence::Sequence(Peg* code)
{
    this->code = code;
}

// Copy constructor
Sequence::Sequence(const Sequence &s)
{
    code = s.code;
}

// Getters
Peg* Sequence::getSequence()
{
    return code;
}

// Setters
void Sequence::setSequence(Peg* code)
{
    this->code = code;
}

string Sequence::sequenceToString()
{
    // Read colors from a standard sequence, and return it in string form.
    string returnSequence;
    for (int i = 0; i < 4; i++) {
        if (code[i].getPeg() == red) {
            returnSequence += "Rd";
        } else if (code[i].getPeg() == yellow) {
            returnSequence += "Yl";
        } else if (code[i].getPeg() == green) {
            returnSequence += "Gr";
        } else if (code[i].getPeg() == blue) {
            returnSequence += "Bl";
        } else if (code[i].getPeg() == white) {
            returnSequence += "Wt";
        } else if (code[i].getPeg() == black) {
            returnSequence += "Bl";
        }

        if (i < 3) {
            returnSequence += ", ";
        }
    }

    return returnSequence;
}

bool Sequence::operator==(Sequence &s1) {
    return (code = s1.getSequence());
}