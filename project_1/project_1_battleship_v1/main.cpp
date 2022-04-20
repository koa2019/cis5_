/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 20, 2022,  1:22 PM
 * Purpose: Project 1. Covers chapters 1-5 in Gaddis. Battleship v1
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // string library

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes

// Program execution begins here

int main(int argc, char** argv) {
    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables
    const char MIN=1, 
            MAX=14;
    
    int     p1Guess,
            p2Guess,
            p1Ship1,
            p2Ship1,
            p1Win = 0,
            p2Win = 0;

    // initial variables
    p1Ship1 = rand()%(MAX-MIN)+MIN;
    p2Ship1 = rand()%(MAX-MIN)+MIN;
    
    cout << "\tPlayer 1 \nEnter a number between 1 and 14. \n";
    //cin >> p1Guess;
    p1Guess = rand()%(MAX-MIN)+MIN;
    cout << p1Guess << endl;
    
    
     // map the inputs to the outputs
    if(p1Guess==p2Ship1){
        p1Win++;
        cout << "IT\'S A HIT!\n";
    } else {
        cout << "IT\'S A MISS!\n";
    }
    
    cout << "\n\tPlayer 2 \nEnter a number between 1 and 14. \n";
    //cin >> p2Guess;
    p2Guess = rand()%(MAX-MIN)+MIN;
    cout << p2Guess << endl;
    
    
     if(p2Guess==p1Ship1){
        p2Win++;
        cout << "IT\'S A HIT!\n";
    } else {
        cout << "IT\'S A MISS!\n";
    }
    
    // Display inputs to outputs
    cout << "\n\tResults\n";
    cout << "****************************\n";
    cout << "Player 1 ship\'s location: " << p1Ship1 << endl;
    cout << "Player 2 ship\'s location: " << p2Ship1 << endl;
    cout << "Player 1 Wins: " << p1Win << endl;
    cout << "Player 2 Wins: " << p2Win << endl;
    // exit code
    return 0;
}