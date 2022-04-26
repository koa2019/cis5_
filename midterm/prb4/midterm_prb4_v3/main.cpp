/* 
 * File:   main.cpp
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 25, 2022,  1:20 PM
 * Purpose:  ISP charges v3
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float PLANA = 16.99;
const float PLANB = 26.99;
const float PLANC = 36.99;

//Function Prototypes Here
float pkgA(int);
float pkgB(int);
float pkgC(int);
string getBestA(int);
string getBestB(int);
string getBestC(int);
float getSavingsA(int, float);
float getSavingsB(int, float);
float getSavingsC(int, float);

//Program Execution Begins Here

int main(int argc, char** argv) {

    //Declare all Variables Here
    const string A = "A ";
    const string B = "B ";
    const string C = "C ";



    char package;
    unsigned short hours;
    float bill = 0.0f,
            save = 0.0f;
    string cheapst = "";
    //bill_A += PLANA;

    //do{
    //Input or initialize values Here
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> package>>hours;
    //} while (hours>0);

    //Basic Charges
    switch (package) {
        case 'a':
        case 'A':
        {
            bill = pkgA(hours);
            cheapst = getBestA(hours);
            save = getSavingsA(hours, bill);
            break;
        }
        case 'b':
        case 'B':
        {
            bill = pkgB(hours);
            cheapst = getBestB(hours);
            save = getSavingsB(hours, bill);
            break;
        }
        case 'c':
        case 'C':
        {
           bill=pkgC(hours);
           cheapst=getBestC(hours);
           save=getSavingsC(hours, bill);
            break;
        }
        default: cout << "Error in switch package default.\n";
    }

    //Output the Charge
    cout << fixed << setprecision(2);
    cout << "$" << bill << " ";

    //Output the cheapest package and the savings
    cout << cheapst << "$" << save << endl;

    //Exit
    return 0;
}

//  ********** FUNCTION DEFITIONs  *************
// ***********************************
//************ PACKAGE C *************
string getBestC(int hrs) {

    string bestPlan;
    bestPlan = (hrs>0 && hrs<11)? "A " :
    ((hrs > 10) && (hrs < 35)) ? "B " :
            (hrs > 34) ? "C " : "";
            
    return bestPlan;
}
float getSavingsC(int hrs, float cost) {

    float saving;
    if(hrs>0 && hrs<11){
        saving=PLANC-PLANA;
    } else if ((hrs > 10) && (hrs < 35)) {
        saving = PLANB-PLANC;
    } else if (hrs > 34) {
        saving = 0;
    } 

    return saving;
}

// 
float pkgC(int hrs) {

    float cost;
    
    if(hrs>0) cost= PLANC;

    return cost;
}

// ***********************************
//************ PACKAGE B *************
// 
float getSavingsB(int hrs, float cost) {

    float saving;
    if(hrs>0 && hrs<11){
        saving=PLANB-PLANA;
    } else if ((hrs > 10) && (hrs < 35)) {
        saving = 0;
    } else if (hrs > 34) {
        saving = cost-PLANC;
    } else "Error in getSavingsB() else.\n";

    return saving;
}

// 
string getBestB(int hrs) {

    string bestPlan;
    bestPlan = (hrs>0 && hrs<11)? "A " :
    ((hrs > 10) && (hrs < 35)) ? "B " :
            (hrs > 34) ? "C " :
            "Error in getBestB() else.\n";
    return bestPlan;
}

// 
float pkgB(int hrs) {

    float cost;
    
    if(hrs>0) cost= PLANB;

    if (hrs > 30) {
        cost += (10 * .74);
        cost += ((hrs - 30)*.64);

    } else if (hrs > 20 && hrs < 31) cost += ((hrs - 20)*.74);
    else return cost;

    return cost;
}

// ****************************
// ******** PACKAGE A  ********
// 
string getBestA(int hrs) {

    string bestPlan;
    bestPlan = ((hrs > 0) && (hrs < 11)) ? "A " :
            ((hrs > 10) && (hrs < 21)) ? "B " :
            (hrs > 20) ? "C " :
            "Error in getBestA() else.\n";
    return bestPlan;
}

// 
float getSavingsA(int hrs, float cost) {

    float saving;
    if ((hrs > 0) && (hrs < 11)) {
        saving = cost - PLANA;
    } else if ((hrs > 10) && (hrs < 21)) {
        saving = cost - PLANB;
    } else if (hrs > 20) {
        saving = cost - PLANC;
    } else "Error in getSavingsA() else.\n";

    return saving;
}

// 
float pkgA(int hrs) {

    float cost;
    if(hrs>0) cost = PLANA;
    

    if (hrs > 20) {
        cost += (10 * .95);
        cost += ((hrs - 20)*.85);

    } else if (hrs > 10 && hrs < 21) cost += ((hrs - 10)*.95);
    else return cost;

    return cost;
}
