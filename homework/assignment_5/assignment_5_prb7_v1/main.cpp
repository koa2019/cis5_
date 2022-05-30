/* 
 * File:  main.cpp 
 * Author: Danielle Fernandez
 * Created on: 5/2/22 5:05 PM
 * Purpose:  convert from 24hr format to 12hr format v1
 *           
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
void dsplyInto();
void dsplyInst(int &, int &);   
int convert12Hr(char &, int);
void dsply12Hr(string , int , int , int);


int main(int argc, char** argv) {   //Execution Begins Here!
    //Set the random number seed

    //Declare Variables
    char ampm,
         ans,
         c;
    int hour,
        hour2,
        minute;
        
     dsplyInto();
     
    //Initialize or input i.e. set variable values
    do {

        // display instructions for user's input
        //dsplyInst(hour, minute);
        cin >> hour >> c >> minute;
    
         if( (minute>59) || (hour>24) ) {
             cout << hour << ":" << minute << " is not a valid time"<< endl;
         } else {
    
            hour2=convert12Hr(ampm, hour);

            string ampmStr = (ampm=='A' || ampm=='a') ? "AM"
                           : (ampm=='P' || ampm=='p') ? "PM"
                           : "Error with am pm input.\n";
            
        // call function to display current time in 12 hour format
        dsply12Hr(ampmStr, hour, minute, hour2);
       }
        again(ans);
        
    } while (ans=='Y' || ans=='y');

    //Exit stage right or left!
    return 0;
}

// 
int convert12Hr(char &ampm, int hr) {

    if((hr==0)) {
        ampm='A';
        hr=12;
        
    } else if(hr>=1 && hr<=11){
        ampm='A';
        hr=hr;
        
    } else if (hr>=12) {
        ampm = 'P';
        if(hr==12) hr=12; 
        else hr=(hr-12);
        
    } else return 0;
    return hr;
}

// displays current time with user's inputs
void dsply12Hr(string ampm2, int hr1, int min, int hr2) {

    if(hr1==0) { cout << hr1 << hr1 << ":" << min << setw(1) << " " << setw(1) <<"=" << setw(1) << " " 
         << hr2 << setw(1) << ":" << min << setw(1) << " " << ampm2 << endl;
        
    } else{
         
    cout << hr1 << ":" << min << setw(1) << " " << setw(1) <<"=" << setw(1) << " " 
         << hr2 << setw(1) << ":" << min << setw(1) << " " << ampm2 << endl;
    }
}

// display directions for user's inputs
void dsplyInst(int &hour, int &minute){
    
    char c;
    cin >> hour >> c >> minute;   
}

// asks user if they want to compute another time
void again(char &ans){
    cout << "Would you like to convert another time (y/n)" << endl;
    cin >> ans;
}

void dsplyInto(){
    cout << "Military Time Converter to Standard Time" << endl;
    cout << "Input Military Time hh:mm"<<endl;
}