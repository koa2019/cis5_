/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 17, 2022, 6:25 PM
 * Purpose: Gaddis - 9th ed - #17 - stocks 
 */

// System Libraries: 
#include <iostream>
using namespace std;

// Global Constants
 const float FEE = .02;     // stockbroker 2% fee

// Program execution begins here
int main(int argc, char** argv) {

    // declare variables
    float stckCost,                     // total cost of stocks
            commssn,                   // commission paid to stockbroker
            totalPaid;                    // total amount paid for stocks and commission
    
    // initialize variables
    float stckPerShare = 35.00;  // stock $35 per share
    int numShares = 750;          // number of shares of stock bought  

    // map the inputs to the outputs
    stckCost = numShares * stckPerShare; // calculates total amount paid for stocks
    
    commssn = stckCost * FEE;               // calculates commission paid to stockbroker
    
    totalPaid = stckCost + commssn;     // adds total amount paid for stocks and commission

    // Display inputs to outputs
    cout << "This program calculates the total costs of stocks and ";
    cout << "\nthe stockbrokers commission based on a 2% fee.\n";
    cout << "---------------------------------------------------------\n";
    cout << numShares << " shares of stock at $" << stckPerShare << "/share = $";
    cout << stckCost << endl;
    cout << "Commission Paid to broker $" << commssn << endl;
    cout << "Total Cost of stocks and commission $" << totalPaid << endl;

    // exit code
    return 0;
}

