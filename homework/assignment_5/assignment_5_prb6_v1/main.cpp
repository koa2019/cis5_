/* 
 * File:  main.cpp 
 * Author: Danielle Fernandez
 * Created on: 5/2/22 2:20 PM
 * Purpose:  12-hour notation v1
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void dsplyCrrnt(char, int, int);
void dsplyWaitPrd(string, int, int);
void getWaitPrd(char, int, int, int);

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    char ampm1,
         ampm2,
         ans;
    int hr,
            newHr,
            mins,
            newMins,
            wait;

    //Initialize or input i.e. set variable values
    do {

        cout << "Enter hour:\n";
        cin >> hr;

        cout << "\nEnter minutes:\n";
        cin >> mins;

        cout << "\nEnter A for AM, P for PM:\n";
        cin >> ampm1;

        cout << "\nEnter waiting time:\n";
        cin >> wait;


        // call function to display current time in 12 hour format
        dsplyCrrnt(ampm1, hr, mins);

        // calculate new wait time
        getWaitPrd(ampm1, hr, mins, wait);

        cout << "Again:" << endl;
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');

    //Map inputs -> outputs

    //Display the outputs

    //Exit stage right or left!
    return 0;
}

// calculate new wait time

void getWaitPrd(char ap, int newHr, int newMins, int w) {

    string newAmPm;
    unsigned int addHrs = w / 60;
    unsigned int addMins = w % 60;
    
    newMins += addMins;
    if(newMins>=60){
        addHrs += (newMins/60);
        newMins%=60;
        //cout << "addHrs in m2 "<< addHrs << endl;
    }
    
    newHr += addHrs;
    if (newHr > 12) {
        newHr -= 12;
        newAmPm = (ap=='A' || ap=='a') ? " PM" : " AM";
    }

    

/*    cout << "old ampm " << ap
            << "\nadd new hrs " << addHrs
            << "\nadd new mins " << addMins
            << "\nnew hours " << newHr
            << "\nnew mins " << newMins
            << "\nnew am pm " << newAmPm << endl;
*/
    dsplyWaitPrd(newAmPm, newHr, newMins);
}

// displays time after waiting
void dsplyWaitPrd(string am_pm2, int newH, int newM) {

    int n10s=newM/10;
    int n1s=newM%10;
    cout << "Time after waiting period =" 
            << setw(3) << newH 
            << setw(1) << ":" 
            << n10s << n1s << am_pm2 << endl;

}

// displays current time with user's inputs
void dsplyCrrnt(char am_pm, int h, int m) {

    string str = (am_pm == 'A' || am_pm == 'a') ? " AM"
            : (am_pm == 'P' || am_pm == 'p') ? " PM"
            : "Error with am pm input.\n";

    cout << "\nCurrent time =" << setw(3) << h << ":" << m << str << endl;
}