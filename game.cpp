#include "game.h"

Game::Game()
{
}

Game::~Game()
{
}

// User-inputed constructor
Game::Game(int count)
{
    this->count = count;
}

// Getters
int Game::getCount()
{
    return count;
}

Sequence Game::getHiddenCode()
{
    return hiddenCode;
}

Sequence Game::getGuess()
{
    return guess;
}

// Setters
void Game::setCount(int count)
{
    this->count = count;
}

void Game::setHiddenCode(Sequence s)
{
    this->hiddenCode = s;
}

void Game::setGuess(Sequence s)
{
    this->guess = s;
}

// Private Functions
bool Game::guessFeedback() 
{
    // Create initial variables
    int blacks = 0;
    int whites = 0;
    int numPeg = 4;
    Peg* check = guess.getSequence();
    Peg* code = hiddenCode.getSequence();
    Peg* tempCheck;
    Peg* tempCode;

    /*
    Decision Logic:
        - If the correct peg is chosen for the correct spot, return one black peg.
        - If the correct colored peg is chosen, but placed in the incorrect spot, return one white peg.
        - If that color was already checked, do not check it again (remove it from the checkable list).
        - Otherwise, do not add any pegs.
    */

    bool nothingFound = false;
    while (nothingFound == false) {
        for (int i = 0; i < numPeg; i++) {
            // If it's exactly correct, add one black peg and remove from the list
            if (check[i].getPeg() == code[i].getPeg()) {
                blacks++;
                numPeg--;

                tempCheck = new Peg[numPeg];
                tempCode = new Peg[numPeg];
                int k = 0;
                for (int j = 0; j < numPeg; j++) {
                    if (j == i) {
                        continue;
                    } else {
                        Peg p1;
                        p1 = check[j];
                        tempCode[k] = p1;
                        Peg p2;
                        p2 = code[j];
                        tempCode[k] = p2;
                        k++;
                    }
                }
                check = tempCheck;
                code = tempCode;
                break;
            } else if (i == numPeg-1) {
                nothingFound = true;
            }
        }
    }

    nothingFound = true;
    while (nothingFound == false) {
        // Check if it's in an incorrect position
        // If that occurs, add one white peg and remove it from the list
        for (int i = 0; i < numPeg; i++) {
            for (int j = 0; j < numPeg; j++) {
                if (check[i].getPeg() == code[j].getPeg()) {
                    whites++;
                    numPeg--;

                    tempCheck = new Peg[numPeg];
                    tempCode = new Peg[numPeg];
                    int l = 0;
                    for (int k = 0; k < numPeg; k++) {
                        if (j == i) {
                            continue;
                        } else {
                            Peg p1;
                            p1 = check[k];
                            tempCode[l] = p1;
                            Peg p2;
                            p2 = code[k];
                            tempCode[l] = p2;
                            l++;
                        }
                    }
                    check = tempCheck;
                    code = tempCode;
                    break;
                } else if (i == numPeg-1) {
                    nothingFound = true;
                }
            }
        }
    }
    // If the user has guessed the sequence, end the loop, otherwise print feedback response to console.
    if (blacks == 4) {
        return true;
    } else {
        cout << "\nThis guess was incorrect." << endl;
        cout << "\nBlack Peg(s): " << blacks << ", White Peg(s): " << whites << endl;
        return false;
    }
}

// Public Functions
void Game::createCode()
{
    // Create initial variables
    int numPeg = 4;
    srand(time(0));
    Peg *random;
    random = new Peg[numPeg];

    // Generate a random-sequence for the hidden code that the user must decipher
    for (int i = 0; i < numPeg; i++) {
        int rnum = rand() % 6;
        Peg p;
        p.setPeg(rnum);
        random[i] = p;
    }

    // Convert dynamic peg array to hiddenCode data member
    Sequence hiddenCode(random);
    setHiddenCode(hiddenCode);
    cout << hiddenCode.sequenceToString() << endl;
}

bool Game::iterateGuess()
{
    // Increase guess count and create initial variables
    count++;
    string g;
    int numPeg = 4;
    Peg *guessList;
    guessList = new Peg[numPeg];

    // Iterate over each guess and add it to a dynamic peg array
    for (int i = 0; i < numPeg; i++) {
        cout << "Peg Color for Slot #" << to_string(i+1) << ":" << endl;
        cin >> g;
        Peg p;
        p.convertPeg(g);
        guessList[i] = p;
    }

    // Convert dynamic peg array to guess data member
    guess = Sequence(guessList);

    // User feedback
    cout << "\nYour guess: " << guess.sequenceToString() << endl;

    // Count the number of returned black and white pegs
    bool check = guessFeedback();

    return check;
    delete guessList;
}

void Game::endGamePrint()
{
    if (hiddenCode == guess) {
        cout << "\nYou guessed the code! Good job!" << endl;
        cout << "Total guesses: " << to_string(count) << endl;
    } else {
        cout << "\nYou did not guess the code. Better luck next time!" << endl;
        cout << "Mastermind 4-Peg Code: " << hiddenCode.getSequence() << endl;
    }

    cout << "\nThank you for playing!" << endl;
}