/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 21, 2022,  8:53 PM
 * Purpose:  Savitch - 10th ed - ch1 - problem 3 - Nickles, Dimes & Quarters
 */

// System Libraries: 
#include <iostream>     // input/output library fixed
#include <iomanip>      // setprecision()
using namespace std;

// Global Constants
const float PEN = .01;      //monetary value of a single penny 
const float NICK = .05;    //monetary value of a single nickle
const float DIME = .10;    //monetary value of a single dime
const float QTR = .25;      // monetary value of a single quarter 
const float HLFD = .50;     // monetary value of a single half dollar

// Program execution begins here
int main(int argc, char** argv) {

    // declare variables
    int nPen,               // number of pennies 
            numNick,     // number of nickles
            numDime,   // number of dimes
            numQtr,     // number of quarters
            nHlfD;       // number of half dollars

    float valPen,       // monetary value total pennies
            valNick,    // monetary value total nickles
            valDime,    // monetary value total dimes
            valQtr,     // monetary value total quarters
            valHlfD,    // monetary value total  half dollars
            total;      // monetary value of all the coins

    // map the inputs to the outputs
    cout << "\n\nThis program asks the user to enter a number of nickles, dimes, and quarters.\n";
    cout << "It then displays their monetary value. Only whole numbers are accepted. \n\n";

    cout << "Enter the number of pennies and then press Enter. ";
    cin >> nPen;
   
    cout << "Enter the number of nickles and then press Enter. ";
    cin >> numNick;
   
    cout << "Enter the number of dimes do you have and then press Enter. ";
    cin >> numDime;
    
    cout << "Enter the number of quarters you have and then press Enter. ";
    cin >> numQtr;
    
     cout << "Enter the number of half dollars you have and then press Enter. ";
     cin >> nHlfD;
    
   
     // get monetary values of each type of coin
     valPen = nPen * PEN;
     valNick = numNick * NICK;
     valDime = numDime * DIME;
     valQtr = numQtr * QTR;
     valHlfD = nHlfD * HLFD;
            
      // adds all the coins monetary values together
      total = valPen + valNick + valDime + valQtr + valHlfD;
    
       // Display inputs to outputs
        cout << "\n\n           Results \n";
        cout <<"******************************\n";
        cout << nPen <<" \tpennies       = $" << setprecision(2) << fixed<< valPen << endl;
        cout << numNick <<"\tnickles       = $" << valNick << endl;
        cout << numDime <<"\tdimes         = $" << valDime << endl;
        cout << numQtr <<"\tquarters      = $" << valQtr << endl;
        cout << nHlfD <<"\thalf dollars  = $" << valHlfD << endl;
        cout << "\nTotal pocket change   = $" << total;

    // exit code
    return 0;
}