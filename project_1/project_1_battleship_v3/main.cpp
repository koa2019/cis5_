/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 20, 2022,  : PM
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

    char ans;
    int nGames = 0,
            round = 1,
            p1Guess,
            p2Guess,
            p1Ship1,
            p2Ship1,
            p1Win = 0,
            p2Win = 0;
    string gussMsg = "\nEnter a number between 1 and 14. \n";
    bool p1_crrt,
         p2_crrt;

    // open an existing file
    inputFile.open("numberOfGames.txt");

    // create a file to output to
    outputFile.open("Scores.txt");

    // read in how many games will be played
    inputFile >> nGames;

    do {
        // initial variables & resets variables to default values
        p1Ship1 = rand() % (MAX - MIN) + MIN;
        p2Ship1 = rand() % (MAX - MIN) + MIN;
        p1_crrt = p2_crrt = false;


        banner("BATTLESHIP");



        //while ((p1Win <= nGames) && (p2Win <= nGames)) {

        while ((!p1_crrt) && (!p2_crrt)) {

            //*************** Player 1's Guess *************  
            cout << endl << setw(15) << "*********" << endl;
            cout << setw(13) << "Round " << round << endl;
            cout << setw(15) << "*********" << endl;
            
            cout << "\n\t" << P1 << gussMsg;
            p1Guess = rand() % (MAX - MIN) + MIN;

            // map the inputs to the outputs
            if (p1Guess == p2Ship1) {
                p1Win++;
                //round++;
                p1_crrt = true;
                //if (p1Win > 0) cout << p1Guess << " == " << p2Ship1 << endl;                
                cout << p1Guess << " == " << p2Ship1 << endl;
                cout << HIT << endl;

            } else {
                p1_crrt = false;
                cout << p1Guess << endl;
                cout << setw(18) << MISS;
            }

            // conditional does NOT run if player 1 hit player 2's ship
            if (!p1_crrt) {

                //*************** Player 2's Guess *************
                cout << "\n\t" << P2 << gussMsg;
                p2Guess = rand() % (MAX - MIN) + MIN;

                if (p2Guess == p1Ship1) {
                    p2Win++;
                    p2_crrt = true;
                    if (p2Win > 0) cout << p2Guess << " == " << p1Ship1 << endl;
                    cout << HIT << endl;

                } else {
                    //p2_crrt = false;
                    cout << p2Guess << endl;
                    cout << setw(18) << MISS;
                }
                //if ((!p1_crrt) && (!p2_crrt)) {
                //round++;
                //}
            }
            //p1_crrt = true;
            //cout << setw(12) << "Round " << round << " over.\n";
            if ((!p1_crrt) && (!p2_crrt)) {
                round++;
                cout << "You Both Missed. Try Again...\n";

            }
            
        }

        // write scores to file
        //outputFile << P1 << "Wins: " << p1Win << endl;
        //outputFile << P2 << "Wins: " << p2Win << endl;


        // Display inputs to outputs
        //banner("WINS");
        cout << setw(8) << P1 << setw(7) << left << " vs " << setw(5) << right << P2 << endl;
        cout << setw(8) << p1Win << setw(12) << p2Win << endl;

        int ttlGmes = p1Win + p2Win;

        if (ttlGmes < nGames) {
            cout << "TTl Games " << ttlGmes << endl;
            cout << "Play again? ";
            cin >> ans;

            //bool playAgn = false;
            if (ans == 'y') {
                //playAgn = true;
                round = 0;
                cout << endl;
            } else if (ans == 'Y') {
                //playAgn = true;
                round = 0;
                cout << endl;
            } else {
                cout << "Thanks for playing!\n";
            }
        } else {
            float avg1 = p1Win / static_cast<float>(ttlGmes)*100;
            float avg2 = p2Win / static_cast<float>(ttlGmes)*100;
            //int avg1Rdd = round(avg1);
            cout << "Averages out of " << nGames << " played\n";
            cout << "Player 1 won " << avg1 << "% of the time." << endl;
            cout << "Player 2 won " << avg2 << "% of the time." << endl;
            //cout << "Player 1 won " << avg1Rdd << "% of the time." << endl;
            cout << "Player 2 won " << avg2 << "% of the time." << endl;
            ans = 'n';
        }
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
