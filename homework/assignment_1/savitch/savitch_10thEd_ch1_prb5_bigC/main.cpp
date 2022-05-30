/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 22, 2022,  11:29 AM
 * Purpose:  savitch - 10th ed - ch1 - problem 5 - Big C
 */

// System Libraries: 
#include <iostream> // input/output lib
#include <cstdlib>  // random()
#include <ctime>    // time to set random number seed
using namespace std;

// Program execution begins here
int main(int argc, char** argv) {
    
    // set random number seed
    srand(static_cast<int> (time(0)));

    // declare variables
    char ltr; 

    // initial variables
    ltr = rand()%26+65;   //generates random [A-Z]- [65-91]

    // Display big block letter using random number the computer picked
    cout << "This program creates a banner using \n";
    cout << "a character randomly picked by the computer. \n\n";
    cout << "  " << ltr << ltr << ltr << endl;
    cout << " " << ltr << "  " << ltr << endl;
    cout << ltr << endl;
    cout << ltr << endl;
    cout << ltr << endl;
    cout << ltr << endl;
    cout << ltr << endl;
    cout << " " << ltr << "  " << ltr << endl;
    cout << "  " << ltr << ltr << ltr << endl;

    // exit code
    return 0;
}