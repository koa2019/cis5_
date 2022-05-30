/* 
 * File:  main.cpp 
 * Author: Danielle Fernandez
 * Created on: 5/2/22 2:20 PM
 * Purpose:  12-hour notation v2
 *           cin is all on one line.
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
void again(char &);
void dsplyInst(int &, int &, char&, int &);   
void dsplyCrrnt(string, int, int);
void dsplyWaitPrd(string, int, int);
void getWaitPrd(string, int, int, int);

//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    char am_pm,
         ans;
    int hr,
        mins,
        wait;

    //Initialize or input i.e. set variable values
    do {

        // display instructions for user's input
        //cin >> hr >> mins >> am_pm >> wait;
        dsplyInst(hr, mins, am_pm, wait);

        string ampm = (am_pm == 'A' || am_pm == 'a') ? "AM"
                    : (am_pm == 'P' || am_pm == 'p') ? "PM"
                    : "Error with am pm input.\n";
            
        // call function to display current time in 12 hour format
        dsplyCrrnt(ampm, hr, mins);

        // calculate new wait time
        getWaitPrd(ampm, hr, mins, wait);

        again(ans);
        if(ans=='y' || ans=='Y') cout << endl;
        
    } while (ans=='Y' || ans=='y');

    //Exit stage right or left!
    return 0;
}

// calculate new wait time

void getWaitPrd(string ap, int crrntHr, int crrntMn, int w) {

    int add2Hr = w/60;    // calculate how many hours you need to add to current time's hour
    int add2Min = w % 60;   // calculate how many mins you need to add to current time's mins
    
    int newMin = crrntMn+add2Min;
    
    if(newMin>=60){
        add2Hr += (newMin/60);
        newMin%=60;
        //cout << "addHrs in m2 "<< addHrs << endl;
    }
    
    int newHr = crrntHr+add2Hr;
    
    if (newHr>12) {
        newHr -= 12;
        ap = (ap=="AM") ? "PM" : "AM";
    } else ap=ap;

/*    cout << "old ampm " << ap
            << "\nadd new hrs " << addHrs
            << "\nadd new mins " << addMins
            << "\nnew hours " << newHr
            << "\nnew mins " << newMins
            << "\nnew am pm " << newAmPm << endl;
*/
    dsplyWaitPrd(ap, newHr, newMin);
}

// displays time after waiting
void dsplyWaitPrd(string am_pm2, int newH, int newM) {

    int n10s=newM/10;
    int n1s=newM%10;
    
    cout << "Time after waiting period" << setw(1) << " " << setw(1)<<"=" << setw(1) << " " << newH 
         << setw(1) << ":" 
         << n10s << n1s << setw(1) << " " << am_pm2 << endl << endl;
}

// displays current time with user's inputs
void dsplyCrrnt(string ampm2, int h, int m) {

    cout << endl << "Current time" << setw(1) << " " << setw(1)<<"=" << setw(1) << " " << h 
         << setw(1) << ":" << m << setw(1) << " " << ampm2 << endl;
}

// display directions for user's inputs
void dsplyInst(int &hr, int &mins, char &am_pm, int &wait){
    
    cout << "Enter hour:" << endl;
    cin >> hr;
    
    cout << endl << "Enter minutes:" << endl;
    cin >> mins;

    cout << endl << "Enter A for AM, P for PM:" << endl;
    cin >> am_pm;

    cout << endl << "Enter waiting time:" <<endl;
    cin >> wait;
}
void again(char &ans){
    cout << "Again:" << endl;
    cin >> ans;
}