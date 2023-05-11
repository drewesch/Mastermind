#include <iostream>
#include "game.h"
#include "peg.h"
#include "Color.h"
#include "sequence.h"
#include <string>

using namespace std;

int main() {
    // Show a welcome message, objective, and guide for users
    cout << "Welcome to the Mastermind Game!" << endl;
    cout << "\nObjective: Guess the 4-peg code within 10 guesses." << endl;
    cout << "\nAfter each guess, the program will respond with the number of \"Black\" and \"White\" pegs." << endl;
    cout << "-> Black Peg = Correct color at correct position\n-> White Peg = Correct color exists at an incorrect position" << endl;
    cout << "\nUsing these hints, try to guess the 4-peg code!" << endl;
    cout << "\nAvaiable peg colors: \nRed = \"Rd\", Yellow = \"Yl\", Green = \"Gr\", Blue = \"Bl\", White = \"Wt\", Black = \"Bk\"" << endl;

    // Start the game
    Game g(0);
    g.createCode();

    // Loop over guesses
    bool proceed = false;
    while (proceed == false) {
        // Print guess number
        cout << "\nGuess #" << g.getCount()+1 << endl;

        // Check if user has made a successful guess
        if (g.iterateGuess() == true) {
            proceed = true;
        }

        // If the user has surpassed 10 guesses, end the program
        if (g.getCount() == 10) {
            proceed = true;
        }
    }

    // End the game
    g.endGamePrint();
}