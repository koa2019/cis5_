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
void pkgB();
void pkgC();
string getCheapst(int);
float getSavings(int,float);

//Program Execution Begins Here

int main(int argc, char** argv) {

    //Declare all Variables Here
    const string A = "A ";
    const string B = "B ";
    const string C = "C ";

    

    char package;
    unsigned short hours;
    float bill_A = 0.0f,
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
            bill_A = pkgA(hours);
            cheapst = getCheapst(hours);
            save=getSavings(hours, bill_A);
            break;
        }
        default: cout << "Error in switch package default.\n";
    }

    //Output the Charge
    cout << fixed << setprecision(2);
    cout << "$" << bill_A << " ";

    //Output the cheapest package and the savings
    cout << cheapst << "$" << save << endl;

    //Exit
    return 0;
}

//  ********** FUNCTION DEFITION  *************

//
float getSavings(int hrs , float cost){
    
    float saving;
    if((hrs > 0) && (hrs < 11)){
        saving =  cost-PLANA;
    } else if((hrs > 10) && (hrs < 21)){
        saving =  cost-PLANB;
    } else if(hrs > 20) {
        saving =  cost-PLANC;
    } else "Error in getCheapst else.\n";
    
    return saving;
}

// 
string getCheapst(int hrs) {

    string bestPlan;
    bestPlan = ((hrs > 0) && (hrs < 11)) ? "A " :
            ((hrs > 10) && (hrs < 21)) ? "B " :
            (hrs > 20) ? "C " :
            "Error in getCheapst else.\n";
    return bestPlan;
}

float pkgA(int hrs) {

    float cost = 16.99;

    if (hrs > 20) {
        cost += (10 * .95);
        cost += ((hrs - 20)*.85);

    } else if (hrs > 10 && hrs < 21) cost += ((hrs - 10)*.95);
    else return cost;

    return cost;
}