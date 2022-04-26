/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 20, 2022,  4:16 PM
 * Purpose: Project 1. Covers chapters 1-5 in Gaddis. Battleship v2
 * Version 2: inside the banner() I added a for loop to output 3 rows, then
 *            there's a switch() outputs the contents of each row which is 
 *            either stars or a variable that was passed from the function call.
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // string library
#include <iomanip>  // fixed, setprecision()

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes
void banner(string);

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

        banner("BATTLESHIP");

        while ((p1Win < 1) && (p2Win < 1)) {

            //*************** Player 1's Turn *************
            cout << "\n\t" << P1 << gussMsg;
            p1Guess = rand() % (MAX - MIN) + MIN;

            // map the inputs to the outputs
            if (p1Guess == p2Ship1) {
                p1Win++;
                cout << HIT;

                if (p1Win > 0) cout << p1Guess << " == " << p2Ship1 << endl;
                
            } else cout << p1Guess << endl << MISS;
       

            if (p1Win < 1) {

                //*************** Player 2's Turn *************
                cout << "\n\t" << P2 << gussMsg;
                p2Guess = rand() % (MAX - MIN) + MIN;

                if (p2Guess == p1Ship1) {
                    p2Win++;
                    cout << HIT;

                    if (p2Win > 0) cout << p2Guess << " == " << p1Ship1 << endl;
                    
                } else cout << p2Guess << endl << MISS;
            }
        }
        
        // Display inputs to outputs
        banner("SCOREBOARD");     
        cout << P1 << "Wins: " << p1Win << endl;
        cout << P2 << "Wins: " << p2Win << endl;

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

void banner(string header) {
    
    for (int i = 0; i <= 2; i++) {

        switch (i) {
            case 0:
            case 2:
            {
                for (int j = 0; j < 32; j++) {
                    cout << "*";
                }
                cout << endl;
                break;
            }
            case 1:
            {
                cout << setw(21) << header << endl;
                break;
            }
            default: cout << "Error in banner().\n";
        }

    }
}
