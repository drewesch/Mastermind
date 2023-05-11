#include "peg.h"
#include "Color.h"

Peg::Peg()
{
}

Peg::~Peg()
{
}

// User-inputed constructor
Peg::Peg(Color c)
{
    this->c = c;
}

// Copy constructor
Peg::Peg(const Peg &p)
{
    this->c = p.c;
}

// Getters
Color Peg::getPeg()
{
    return c;
}

// Setters
void Peg::setPeg(Color c)
{
    this->c = c;
}

void Peg::setPeg(int c) 
{
    this->c = Color(c);
    
/*     Color color;
    switch (c) {
        case 0: 
            color = red;
        case 1: 
            color = yellow;
        case 2: 
            color = green;
        case 3: 
            color = blue;
        case 4: 
            color = white;
        case 5: 
            color = black;
    };
    
    this->c = color; */
}

void Peg::convertPeg(string colorType) 
{
    bool proceed = false;
    while (proceed == false) {
        if (colorType == "Rd") {
            this->c = red;
        } else if (colorType == "Yl") {
            this->c = yellow;
        } else if (colorType == "Gr") {
            this->c = green;
        } else if (colorType == "Bl") {
            this->c = blue;
        } else if (colorType == "Wt") {
            this->c = white;
        } else if (colorType == "Bk") {
            this->c = black;
        } else {
            cout << "\nPlease Enter a Valid Peg Color." << endl;
            cout << "Avaiable peg colors: \nRed = \"Rd\", Yellow = \"Yl\", Green = \"Gr\", Blue = \"Bl\", White = \"Wt\", Black = \"Bk\"" << endl;
            continue;
        }
        proceed = true;
    }
}