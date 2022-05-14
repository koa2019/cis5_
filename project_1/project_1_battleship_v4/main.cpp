/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 12, 2022,  5:16 PM
 * Purpose: Project 1. Covers chapters 1-5 in Gaddis. Battleship v3
 * Version 4: added ternary, removed banner(), added ceil(), added decrement
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <fstream>  // ofstream 
#include <cstring>  // string library
#include <ctime>    // time library for rand()

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes
//void banner(string);

// Program execution begins here

int main(int argc, char** argv) {

    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables
    ifstream     inFile; // for reading an existing file
    ofstream     outFile; // for outputting to a file

    const int    MIN = 1, // minimum number for rand()
                 MAX = 14; // maximum number for rand()
    const string HIT = "IT\'S A HIT!\n";
    const string MISS = "IT\'S A MISS!\n";
    const string P1 = "Player 1 ";
    const string P2 = "Player 2 ";

    bool         p1_crrt, // player 1 correct
                 p2_crrt; // player 2 correct
    char         ans; // answer  
    int          maxGmes = 0, // number of games
                 round = 1, // round
                 p1Guess, // player 1 guess
                 p2Guess, // player 2 guess
                 p1Ship1, // player 1 ship number 1
                 p2Ship1, // player 2 ship number 1
                 p1Win = 0, // number of wins player 1 has
                 p2Win = 0, // number of wins player 2 has
                 ttlGmes = 0,
                 ttlRnds = 0;
    float        avg1, // average number of wins for player 1
                 avg2, // average number of wins for player 2
                 avgRnds;
    string       gussMsg = "\nGuess a number between 1 and ";

    // open an existing file that holds max number of games a user can play
    inFile.open("maxNGms.txt");

    // create a file to output to
    outFile.open("scores.txt");
    
    // read in maximum number of games that can be played from file
    inFile >> maxGmes;
    int nGmsLft = maxGmes;  // set numberOfGamesLeft to equal maxGames
    
    do { // game starts here
        
        // initial variables to represent the location of each player's ship
        p1Ship1 = rand()%(MAX-MIN)+MIN;
        p2Ship1 = rand()%(MAX-MIN)+MIN;

        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display 3 line game banner
        for(int i=0;i<=2;i++){
            switch(i){  // print a border or string depending on i
                case 0:
                case 2:
                {
                    for (int j=0; j<32; j++) {
                        cout << "*";
                    }
                    cout << endl;
                    break;
                }
                case 1:
                {
                    cout << setw(21) << "BATTLESHIP" << endl;
                    break;
                }
                default: cout << "Error in banner().\n";
            }
        }

        // display games introduction message
        cout << setw(2) << " " << "Try to guess the location of \n"
             << setw(6) << " " << "the computer\'s ship." << endl;
        
        // loops until a player correctly guesses opponents ship location
        while((!p1_crrt) && (!p2_crrt)){

            cout << endl << setw(26) << "********************" << endl;
            cout << setw(18) << "Round " << round << endl;
            cout << setw(26) << "********************" << endl;

            //*************** Player 1's Guess ************* 
            //**********************************************
            // display instructions to player 1
            cout << endl << setw(21) << P1 << gussMsg << MAX << endl;
            
            // program generates random number guess
            p1Guess = rand()%(MAX-MIN)+MIN;

            // checks if player1 guess is correct
            if(p1Guess == p2Ship1){

                // increment player 1 number of wins
                p1Win++;
                nGmsLft--;  // decrease number of total games

                // reassign player 1's value for a correct guess
                p1_crrt = true;                             

                // display HIT message for correct guess
                cout << setw(13) << p1Guess << " == " << p2Ship1 << endl;
                cout << setw(23) << HIT << endl;
              
            } else {  // if player1 guess is wrong 
                
                // display MISS message for wrong guess
                cout << p1Guess << endl;
                cout << setw(23) << MISS;
            }

            // conditional only runs if player 1 misses player 2's ship
            if(!p1_crrt){

                //*************** Player 2's Guess *************
                //**********************************************
                // display instructions to player 2
                cout << endl << setw(21) << P2 << gussMsg << MAX << endl;

                // program automatically generates a guess for player 2
                p2Guess = rand()%(MAX-MIN)+MIN;

                // conditional checks if guess is correct
                if(p2Guess == p1Ship1){

                    // increment player 2 number of wins
                    p2Win++;
                    nGmsLft--;  // decrease number of total games
                    
                    // reassign player 2's value for a correct guess
                    p2_crrt = true;

                    // display HIT message for correct guess                  
                    cout << setw(13) << p2Guess << " == " << p1Ship1 << endl;
                    cout << setw(23) << HIT << endl;
                   
                } else { // display message for wrong guess                    
                    cout << p2Guess << endl;
                    cout << setw(23) << MISS;
                }
            }

            // if both players guess wrong, then increment round by 1
            // and display message to tell them to continue guessing 
            if((!p1_crrt) && (!p2_crrt)){
                round++;
                cout << endl << "You Both Missed. Try Again...\n\n";
            }
        }// ends while()

        // Display scoreboard banner       
        for(int k=0; k<=2; k++){
            ((k==0)||(k==2)) ? cout << "********************************\n"
                    : (k==1) ? cout << setw(21) << "SCOREBOARD" << endl
                    : cout << "Error in banner().\n";
        }
        
        cout << setw(4) << " " << P1 << setw(4) << "vs" << setw(3) << " " 
             << right << P2 << endl;
        cout << setw(8) << p1Win << setw(16) << p2Win << endl;

        // calculate total number of games won & number rounds played
        ttlGmes = p1Win+p2Win;
        ttlRnds += round; // sums the total number of rounds from all games

        // calculates each players percentage of winning
        avg1 = p1Win/static_cast<float>(ttlGmes)*100;
        avg2 = p2Win/static_cast<float>(ttlGmes)*100;
        avgRnds = static_cast<float>(ttlRnds)/ttlGmes;
        
        // checks maximum number of games has NOT been played
        if(ttlGmes<maxGmes){

            cout << "\nTotal # Games Played = " << ttlGmes << endl;
            cout << nGmsLft << " of " << maxGmes << " max games allowed.\n";
            cout << "Play again? ";
            cin >> ans;

            // conditional validates user's input
            if(ans=='y'){                
                round = 1;
                cout << endl << endl;
            } else if(ans=='Y'){                
                round = 1;
                cout << endl << endl;
            } else {
                cout << "\nThanks for playing!\n";               
                cout << fixed << showpoint << setprecision(2); 
                cout << "\nAverages for " << ttlGmes << " games \n"
                     << "Player 1 won ceil(" << avg1 << ")% = " 
                     << ceil(avg1) << endl
                     << "Player 2 won ceil(" << avg2 << ")% = " 
                     << ceil(avg2) << endl;
                cout << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                     << ceil(avgRnds) << endl;
            }           
        } else { // display end of game results
           
            cout << "Max number of games has been reached." << endl;
            cout << fixed << showpoint << setprecision(2);           
            cout << "\nAverages for " << ttlGmes << " games \n"
                 << "Player 1 won ceil(" << avg1 << ")% = " 
                 << ceil(avg1) << endl
                 << "Player 2 won ceil(" << avg2 << ")% = " 
                 << ceil(avg2) << endl;
            cout << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                 << ceil(avgRnds) << endl;      

            // reassign ans so it will end the do..while()
            ans = 'n';
        }        
        
      // continue doing all the statements above until 
      // ans does not equal y or Y
    } while((ans=='y')||(ans=='Y'));   

    // write scores to file
    outFile << fixed << showpoint << setprecision(2);  
    outFile << "\nAverages for " << ttlGmes << " games \n"
            << "Player 1 won ceil(" << avg1 << ")% = " 
            << ceil(avg1) << endl
            << "Player 2 won ceil(" << avg2 << ")% = " 
            << ceil(avg2) << endl;
    outFile << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
            << ceil(avgRnds) << endl; 
        
    // close file being read in
    inFile.close();

    // close scores.txt file
    outFile.close();

    // exit code
    return 0;
}