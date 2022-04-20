/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 8:16 PM
 * Purpose:  Savitch 9th ed - ch3 - prac prb 1 - Rock Paper Scissors
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstring>  // string
using namespace std;

//Function Prototypes
void playGameMsg();
void paperWinRk();   
void scissorWinPpr();
void rockWScsr();
void tie();
void p1_win();
void p2_win();

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    string p1, p2; // player1 player2
    char ans; // holds users answer to continue or quit the game

    // loop allows player to keep playing with a Y or y input
    do {
        
        // get user's inputs
        cout << "\nRock Paper Scissors Game\n"
                << "Input Player 1 and Player 2 Choices\n";
        cin >> p1 >> p2;

        // conditional converts lowercase r,s,p to uppercase for player 1's input
        p1 == "r" ? p1 = "R" :

                p1 == "p" ? p1 = "P" :

                p1 == "s" ? p1 = "S" : p1 = p1;

        // conditional converts lowercase r,s,p to uppercase for player 2's input
        p2 == "r" ? p2 = "R" :

                p2 == "p" ? p2 = "P" :

                p2 == "s" ? p2 = "S" : p2 = p2;

        // conditional checks who won. R = rock, P=paper, S=Scissors
        // rock beats Scissors, paper beats rock, Scissors beat paper, or Nobody wins
        if (p1 == p2) {
            tie();

        } else if (p1 == "P" && p2 == "R") {
            p1_win();
            paperWinRk();

        } else if (p1 == "P" && p2 == "S") {
            p2_win();
            scissorWinPpr();

        } else if (p1 == "R" && p2 == "S") {
            p1_win();
            rockWScsr();

        } else if (p1 == "R" && p2 == "P") {
            p2_win();
            paperWinRk();

        } else if (p1 == "S" && p2 == "P") {
            p1_win();
            scissorWinPpr();

        } else if (p1 == "S" && p2 == "R") {
            p2_win();
            rockWScsr();

        } else { cout << "Invalid Input.\n"; }

        playGameMsg();
        cin >> ans;

    } while ((ans == 'Y') || (ans == 'y'));

    //Exit stage right or left!
    return 0;
}

// function definitions
void playGameMsg() {
    cout << "Enter Y to play.\n";
}

void paperWinRk() {
    cout << "Paper covers rock.\n";
}

void scissorWinPpr() {
    cout << "Scissors cuts paper.\n";
}

void rockWScsr() {
    cout << "Rock breaks scissors.\n";
}

void tie() {
    cout << "Nobody wins.\n";
}

void p1_win() {
    cout << "Player 1 Wins!\n";
}

void p2_win() {
    cout << "Player 2 Wins!\n";
}