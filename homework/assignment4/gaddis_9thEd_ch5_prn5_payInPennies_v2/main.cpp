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

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    const int INCRMNT = 2;
    int nDays;

    float pennies = 1.00f,
            pay,
            ttlPay=0.00f;

    //Initialize or input i.e. set variable values
    cin >> nDays;
    if ((nDays < 1)) {
        cout << "Invalid Entry. Number of days CAN NOT be less than 1.\n";
    } else {

        //Map inputs -> outputs
        for (int i = 0; i < nDays; i++) {

            cout << "pennies = " << pennies << endl;
            static_cast<int>(ttlPay += pennies/100);
            cout << "ttlPay = " << ttlPay << endl;
            
            static_cast<int>(pennies *= INCRMNT/100);
            cout << "pennies x2 = " << pennies << endl;
            //pay = nDays*.01;
            //ttlPay += pay;

        }
        //ttlPay += pay;
        //ttlPay = ttlPay / 100;
        //cout << "ttlPay/100 outside for loop = " << ttlPay << endl;


        //Display the outputs
        cout << fixed << setprecision(2);
        cout << "Pay = $" << ttlPay;
    }
    //Exit stage right or left!
    return 0;
}