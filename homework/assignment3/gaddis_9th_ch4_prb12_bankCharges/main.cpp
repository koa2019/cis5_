/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 6:06 PM
 * Purpose:  Gaddis 9th ed - ch4 prb 12 - bank charges
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // setw()
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    // Constants
    const float LOWBALFEE = 15.00, // low balance bank fees
            MONTHFEE = 10.00; // monthly bank fee

    //Declare Variables
    unsigned short nChks;
    float balance = 0.00, fees = 0.00, lowBal = 0.00, ttlFees, newBal = 0.00;

    //Initialize or input i.e. set variable values

    //Map inputs -> outputs
    cout << "Monthly Bank Fees\n"
            << "Input Current Bank Balance and Number of Checks\n";
    cin >> balance >> nChks;

    if (balance < 0) { // Checks for a negative balance

        cout << "Account overdrawn";
        return 0;
    }

    if (balance < 400) { // adds LOW BALANCE fee to account charges

        lowBal = LOWBALFEE;

        ttlFees += LOWBALFEE + MONTHFEE;

    } else {
        ttlFees += MONTHFEE;
    }
    
    if (nChks >= 60) { // 60 or more checks written in the month

        fees = nChks * .04;
        ttlFees += fees;
        newBal = balance - ttlFees;

    } else if (nChks >= 40) { // 40-59 checks written in the month
        
        fees = nChks * .06;
        ttlFees += fees;
        newBal = balance - ttlFees;
        
    } else if (nChks >= 20) { // 20-39 checks written in the month
        
        fees = nChks * .08;
        ttlFees += fees;
        newBal = balance - ttlFees;
        
    } else if (nChks >= 0) { // 0-19 checks written in the month
        
        fees = nChks * .10;
        ttlFees += fees;
        newBal = balance - ttlFees;
    } else { cout << "Oops Error. "; }

    //Display the outputs
    cout << fixed << setprecision(2) << left;
    cout << setw(12) << "Balance" << setw(1) << right << "$" << setw(9) << balance << endl;
    cout << setw(12) << left << "Check Fee " << setw(1) << right << "$" << setw(9) << fees << endl;
    cout << setw(12) << left << "Monthly Fee " << setw(1) << right << "$" << setw(9) << MONTHFEE << endl;
    cout << setw(12) << left << "Low Balance " << setw(1) << right << "$" << setw(9) << lowBal << endl;
    cout << setw(12) << left << "New Balance " << setw(1) << right << "$" << setw(9) << newBal;


    //Exit stage right or left!
    return 0;
}