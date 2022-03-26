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

//Execution Begins Here!

int main(int argc, char** argv) {

    //Declare Variables
    string p1, p2;
    char ans;

    do {
        //Map inputs -> outputs
        cout << "Rock Paper Scissors Game\n"
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
        if (p1 == "P" && p2 == "R") {
            cout << "Paper covers rock.";

        } else if (p1 == "P" && p2 == "S") {
            cout << "Scissors cuts paper.";

        } else if (p1 == "R" && p2 == "S") {
            cout << "Rock breaks scissors.";

        } else if (p1 == "R" && p2 == "P") {
            cout << "Paper covers rock.";

        } else if (p1 == "S" && p2 == "P") {
            cout << "Scissors cuts paper.";

        } else if (p1 == "S" && p2 == "R") {
            cout << "Rock breaks scissors.";

        } else if (p1 == p2) {
            cout << "Nobody wins.\n";
        } else {
            cout << "Invalid Input.\n";
        }
        cout << "\nPress Y to continue playing.\n";
        cin >> ans;

    } while (ans == 'Y' || ans == 'y');

    //Exit stage right or left!
    return 0;
}