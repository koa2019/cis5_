/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 6:50 PM
 * Purpose:  Gaddis 9th ed - ch4 prb 23 - ISP
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    const float PKGAFEE = 9.95, //
                PKGBFEE = 14.95, //
                PKGCFEE = 19.95; //

    unsigned char pkg; // ISP Package
    float hrs,      //hours
          bill,   // customer's bill for the month
          overage = 0.00; // hours over 10 or 20

    //Map inputs -> outputs
    cout << "ISP Bill\n"
         << "Input Package and Hours\n";

    cin >> pkg >> hrs;

    // conditional validates hours does not exceed 744
    if (hrs > 744) {
        cout << "Error. Hours can not exceed 744\n";
        return 0;
    }
    /*
        // conditional validates input is a capital A,B,C
        if (!(pkg == 'A') || !(pkg == 'B') || !(pkg == 'C')) {
            cout << "Invalid Package Input\n";
            return 0;
        } 
     */
    /*   if((pkg != 'A') || (pkg != 'B') || (pkg != 'C')){
           cout << "Invalid Package Input\n";
           return 0;
       }
     */
    if (pkg == 'A' || pkg == 'B' || pkg == 'C') {

        switch (pkg) {

            case 'A':
                if (hrs > 10) {
                    overage = (hrs - 10)*2.00;
                }
                bill = PKGAFEE + overage;
                break;

            case 'B':
                if (hrs > 20) {
                    overage = (hrs - 20)*1.00;
                }
                bill = PKGBFEE + overage;
                break;

            case 'C':
                bill = PKGCFEE;
                break;

            default:
                cout << "Oops! Error.\n";
                return 0;
        }
    } else {
        cout << "Invalid Package Input\n";
        return 0;
    }


    //Display the outputs
    cout << fixed << setprecision(2);
    cout << setw(8) << "Bill = $" << setw(6) << bill;

    //Exit stage right or left!
    return 0;
}