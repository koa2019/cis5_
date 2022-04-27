/* 
 * File:   main.cpp
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 25, 2022,  1:20 PM
 * Purpose:  ISP charges
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
    cout << fixed << showpoint << setprecision(2);
    cout << setw(1) << "$" << setw(6) << left << bill;

    //Output the cheapest package and the savings
    cout << setw(2) <<cheapst << setw(1) << "$" << save << endl;

    //Exit
    return 0;
}

//  ********** FUNCTION DEFITIONs  *************
// ***********************************
//************ PACKAGE C *************
string getBestC(int hrs) {

    string bestPlan;
    bestPlan = (hrs>0 && hrs<=10)? "A " :
    ((hrs >=11) && (hrs <=34)) ? "B " :
            (hrs >=35) ? "C " : "";
            
    return bestPlan;
}
float getSavingsC(int hrs, float cost) {

    float saving;
    if(hrs>0 && hrs<=10) saving=PLANC-PLANA;
    else if ((hrs >=11) && (hrs <=34)) saving = PLANC-PLANB;
    else if (hrs > 34) saving = 0;

    return saving;
}
// 
float pkgC(int hrs) {
    
    float cost;
    if(hrs>=0) cost= PLANC;
    return cost;
}

// ***********************************
//************ PACKAGE B *************
// 
float getSavingsB(int hrs, float cost) {

    float saving;
    if(hrs>0 && hrs<=10) saving=PLANB-PLANA;
    else if ((hrs >=11) && (hrs <= 34)) saving = 0;
    else if (hrs >=35) saving = cost-PLANC;

    return saving;
}

// 
string getBestB(int hrs) {

    string bestPlan;
    bestPlan = (hrs>0 && hrs<=10) ? "A " :
    ((hrs >=11) && (hrs <= 34)) ? "B " :
            (hrs >=35) ? "C " : "";
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
    bestPlan = ((hrs > 0) && (hrs <=20)) ? "A " :
            ((hrs >=21) && (hrs <=32)) ? "B " :
           (hrs >= 33) ? "C " :
            "Error in getBestA() else.\n";
    return bestPlan;
}

// 
float getSavingsA(int hrs, float cost) {

    float saving;
    if ((hrs > 0) && (hrs <=20)) {
        saving = 0;
    } else if ((hrs >=21) && (hrs <=32)) {
        saving =cost- PLANB;
    } else if (hrs >= 33) {
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
