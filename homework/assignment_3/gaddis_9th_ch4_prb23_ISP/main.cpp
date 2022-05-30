/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 6:50 PM
 * Purpose:  Gaddis 9th ed - ch4 prb 23 - ISP
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // setw()
#include <cstring>
using namespace std;

//Execution Begins Here!

int main(int argc, char** argv) {

    //Declare Variables
    const float PKGAFEE = 9.95, // Package A monthly fee
            PKGBFEE = 14.95, //Package B monthly fee
            PKGCFEE = 19.95, //Package C monthly fee
            OVERPKA = 2.00, // $2/hr fee if customer goes over their limit
            OVERPKB = 1.00; // $1/hr fee if customer goes over their limit
    const unsigned short ALIMIT = 10, // package A allowed 10 hrs
            BLIMIT = 20; // package B allowed 20 hrs

    const char pkgA = 'A';
    const int SIZE = 10;
    char pkg2[SIZE]; // ISP Package

    char pkg; // ISP Package
    float hrs, //hours
          bill, // customer's bill for the month
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
        if(strcmp(pkg,pkgA)<0){
         cout << "Invalid Package Input\n";
           return 0;
    }
     */

    /*
        // conditional validates input is a capital A,B,C
        if (!(pkg == 'A') || !(pkg == 'B') || !(pkg == 'C')) {
            cout << "Invalid Package Input\n";
            return 0;
        } 
     */

    /*
       if((pkg != 'A') || (pkg != 'B') || (pkg != 'C')){
           cout << "Invalid Package Input\n";
           return 0;
       }
     */

    //if (pkg == 'A' || pkg == 'B' || pkg == 'C' || pkg == 'a' || pkg == 'b' || pkg == 'c') {

    if (pkg == 'A' || pkg == 'B' || pkg == 'C') {

        switch (pkg) {

            case 'A':
            case 'a':
                if (hrs > ALIMIT) {     // checks if user went over packages allotted hours
                    overage = (hrs - ALIMIT) * OVERPKA;
                }
                bill = PKGAFEE + overage;
                break;

            case 'B':
            case 'b':
                if (hrs > BLIMIT) {     // checks if user went over packages allotted hours
                    overage = (hrs - BLIMIT) * OVERPKB;
                }
                bill = PKGBFEE + overage;
                break;

            case 'C': // package C has unlimited hours
            case 'c':
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


    cout << fixed << setprecision(2);
    cout << setw(8) << "Bill = $" << setw(6) << bill;

    //Exit stage right or left!
    return 0;
}