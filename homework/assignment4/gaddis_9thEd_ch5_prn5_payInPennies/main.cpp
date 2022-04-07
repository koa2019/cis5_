/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 5, 2022 11:45 AM
 * Purpose: gaddis 9th ed - ch5 - prb 7 - pay in pennies
 */

//System Libraries
#include <iomanip>
#include <iostream>
using namespace std;

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    const int INCRMNT = 2;
    int nDays;

    double pennies = .01,
            pay,
            ttlPay = 0.00f;

    //Initialize or input i.e. set variable values
    cin >> nDays;

    if ((nDays < 1)) {

        cout << "Invalid Entry. Number of days CAN NOT be less than 1.\n";
    } else {

        //Map inputs -> outputs
        for (int i = 1; i <= nDays; i++) {

            ttlPay += pennies;
            pennies *= INCRMNT;
        }

        //Display the outputs
        cout << fixed << setprecision(2);
        cout << "Pay = $" << ttlPay;
    }

    //Exit stage right or left!
    return 0;
}