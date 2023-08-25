/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 20, 2022,  6:00 PM
 * Purpose: Project 1. Covers chapters 1-5 in Gaddis. Battleship v3
 * Version 3: 
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // string library
#include <iomanip>  // fixed, setprecision()
#include <fstream>  // ofstream 
#include <cmath>    // round()

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
    ifstream inputFile; // for reading an existing file
    ofstream outputFile; // for outputting to a file
    const char MIN = 1,
            MAX = 14;
    const string HIT = "IT\'S A HIT!\n";
    const string MISS = "IT\'S A MISS!\n";
    const string P1 = "Player 1 ";
    const string P2 = "Player 2 ";

    bool p1_crrt,
            p2_crrt;
    char ans;
    int nGames = 0,
            round = 1,
            p1Guess,
            p2Guess,
            p1Ship1,
            p2Ship1,
            p1Win = 0,
            p2Win = 0;
    float avg1, avg2, avg1Rdd;
    string gussMsg = "\nEnter a number between 1 and 14. \n";

    // open an existing file
    inputFile.open("numberOfGames.txt");

    // create a file to output to
    outputFile.open("Scores.txt");

    // read in maximum number of games that can be played from file
    inputFile >> nGames;

    do {
        // initial variables 
        p1Ship1 = rand() % (MAX - MIN) + MIN;
        p2Ship1 = rand() % (MAX - MIN) + MIN;

        // reset variables to default value
        p1_crrt = p2_crrt = false;

        // call function to display game banner
        banner("BATTLESHIP");

        //while ((p1Win <= nGames) && (p2Win <= nGames)) {

        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {


            cout << endl << setw(20) << "**************" << endl;
            cout << setw(16) << "Round " << round << endl;
            cout << setw(20) << "**************" << endl;

            //*************** Player 1's Guess *************  
            cout << "\n\t" << P1 << gussMsg;
            p1Guess = rand() % (MAX - MIN) + MIN;

            // map the inputs to the outputs
            // conditional checks if guess is where their opponent's ship is
            if (p1Guess == p2Ship1) {

                // increment player 1 number of wins
                p1Win++;

                // reassign bool value
                p1_crrt = true;
                //if (p1Win > 0) cout << p1Guess << " == " << p2Ship1 << endl;                
                cout << p1Guess << " == " << p2Ship1 << endl;
                cout << HIT << endl;

            } else {

                // reassign bool value
                //p1_crrt = false;

                // display message for wrong guess
                cout << p1Guess << endl;
                cout << setw(18) << MISS;
            }

            // conditional does NOT run if player 1 hit player 2's ship
            if (!p1_crrt) {

                //*************** Player 2's Guess *************
                cout << "\n\t" << P2 << gussMsg;
                p2Guess = rand() % (MAX - MIN) + MIN;

                // conditional checks if guess is where their opponent's ship is
                if (p2Guess == p1Ship1) {

                    // increment player 2 number of wins
                    p2Win++;

                    // reassign bool value
                    p2_crrt = true;

                    // independent if conditional displays message 
                    // when player 2 guesses correctly
                    if (p2Win > 0) {
                        cout << p2Guess << " == " << p1Ship1 << endl;
                        cout << HIT << endl;
                    }
                } else {

                    // display message for wrong guess
                    cout << p2Guess << endl;
                    cout << setw(18) << MISS;
                }
            }

            // if both players guess wrong, then increment round by 1
            // and display message to try guessing again
            if ((!p1_crrt) && (!p2_crrt)) {
                round++;
                cout << "You Both Missed. Try Again...\n";
            }
        }

        // Display tally of player's wins
        banner("SCOREBOARD");
        cout << setw(8) << P1 << setw(7) << left << " vs " << setw(5) << right << P2 << endl;
        cout << setw(8) << p1Win << setw(12) << p2Win << endl;

        // calculate total number of won games 
        int ttlGmes = p1Win + p2Win;

        // calculates each players percentage of winning
        avg1 = p1Win / static_cast<float> (ttlGmes)*100;
        avg2 = p2Win / static_cast<float> (ttlGmes)*100;

        float num = 11.5;
        //avg1Rdd = round(num);

        // conditional checks maximum number of games has NOT been played
        if (ttlGmes < nGames) {
            cout << "\nTotal # Games = " << ttlGmes << endl;
            cout << "Play again? ";
            cin >> ans;

            // conditional validates user's input
            if (ans == 'y') {
                //playAgn = true;
                round = 1;
                cout << endl;
            } else if (ans == 'Y') {
                //playAgn = true;
                round = 1;
                cout << endl;
            } else {
                cout << "\nThanks for playing!\n";
                cout << showpoint << setprecision(5);
                cout << "\nAverages out of " << ttlGmes << " played\n";
                cout << "Player 1 won " << avg1 << "% of the time." << endl;
                cout << "Player 2 won " << avg2 << "% of the time." << endl;
            }
        } else {

            // display end of game results
            cout << showpoint << setprecision(5);
            cout << "\nAverages out of " << nGames << " played\n";
            cout << "Player 1 won " << avg1 << "% of the time." << endl;
            cout << "Player 2 won " << avg2 << "% of the time." << endl;
            //cout << "Player 1 won round(" << avg1 << ") = " << round(num) << "% " << endl;

            //cout << "round() = " << round(num) << endl;
            //cout << "round() = " << avg1Rdd << endl;            

            // reassign ans so it will end the do..while()
            ans = 'n';
        }

        // write scores to file
        outputFile << "\nAverages out of " << nGames << " games played\n";
        //outputFile << P1 << "Wins: " << p1Win << endl;
        //outputFile << P2 << "Wins: " << p2Win << endl;
        outputFile << "Player 1 won " << avg1 << "% of the time.\n"; 
        outputFile << "Player 2 won " << avg2 << "% of the time.\n";

        // continue doing all the previous statements until 
        // ans does not equal y or Y
    } while ((ans == 'y') || ans == 'Y');

    // close file being read in
    inputFile.close();

    // close scores.txt file
    outputFile.close();

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
