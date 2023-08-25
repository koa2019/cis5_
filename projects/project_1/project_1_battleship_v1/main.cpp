/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 20, 2022,  1:22 PM
 * Purpose: Project 1. Covers chapters 1-5 in Gaddis. Battleship v1
 * This version 1 plays until a player wins 1 game and then asks
 * if they want to play again. Ships locations and players guesses
 * are randomly generated.
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // string library

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes
void startMsg();

// Program execution begins here

int main(int argc, char** argv) {
    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables
    const char MIN = 1,
            MAX = 14;
    const string HIT = "IT\'S A HIT!\n";
    const string MISS = "IT\'S A MISS!\n";
    const string P1 = "Player 1 ";
    const string P2 = "Player 2 ";
    char ans;
    int p1Guess,
            p2Guess,
            p1Ship1,
            p2Ship1,
            p1Win = 0,
            p2Win = 0;
    string gussMsg = "\nEnter a number between 1 and 14. \n";

    do {
        // initial variables
        p1Ship1 = rand() % (MAX - MIN) + MIN;
        p2Ship1 = rand() % (MAX - MIN) + MIN;

        startMsg();

        while ((p1Win < 1) && (p2Win < 1)) {

            //*************** Player 1's Turn *************
            cout << "\n\t" << P1 << gussMsg;
            p1Guess = rand() % (MAX - MIN) + MIN;


            // map the inputs to the outputs
            if (p1Guess == p2Ship1) {
                p1Win++;
                cout << HIT;

                if (p1Win > 0) {
                    cout << p1Guess << " == " << p2Ship1 << endl;
                }

            } else {
                cout << p1Guess << endl << MISS;
            }

            if (p1Win < 1) {

                //*************** Player 2's Turn *************
                cout << "\n\t" << P2 << gussMsg;                
                p2Guess = rand() % (MAX - MIN) + MIN;

                if (p2Guess == p1Ship1) {
                    p2Win++;
                    cout << HIT;

                    if (p2Win > 0) {
                        cout << p2Guess << " == " << p1Ship1 << endl;
                    }
                } else {
                    cout << p2Guess << endl << MISS;
                }
            }
        }
        // Display inputs to outputs
        cout << "\n****************************\n";
        cout << "\tResults\n";
        cout << "****************************\n";
        cout << "Player 1 Wins: " << p1Win << endl;
        cout << "Player 2 Wins: " << p2Win << endl;
        cout << "****************************\n\n";

        cout << "Play again? ";
        cin >> ans;
        
        bool playAgn = false;
        if (ans == 'y') {
            playAgn = true;
            p1Win = p2Win = 0;
            cout << endl;
        } else if (ans == 'Y') {
            playAgn = true;
            p1Win = p2Win = 0;
            cout << endl;
        } else {
            cout << "Thanks for playing!\n";
        }

    } while ((ans == 'y') || ans == 'Y');






    // exit code
    return 0;
}
//*************************************
//      FUNCTION DEFTIONTIONS
//*************************************

void startMsg() {
    cout << "**************************"
            << "\n\tBATTLESHIP\n"
            << "**************************";
}
