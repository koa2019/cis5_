/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 7:35 PM
 * Purpose:  Savitch 9th Ed - ch4 - prb 1 - MPG
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   // setprecision(), fixed
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float LTR2Gal = 0.264179;     // one liter equals 0.264179 gallons

//Function Prototypes
float getMlsPrGal(int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    char ans;
    int ltrsUsd,
        nMiles;
    float mlPrGal;
    
    do { 
        
    //Initialize or input i.e. set variable values
    cout << "Enter number of liters of gasoline:\n\n";
    cin >> ltrsUsd;
    cout << "Enter number of miles traveled:\n\n";
    cin >> nMiles;
    
    // call function to calculate miles per gallon traveled
    mlPrGal =  getMlsPrGal(nMiles, ltrsUsd); 
    
    //Display the outputs
    cout << fixed << setprecision(2);
    cout << "miles per gallon:\n" << mlPrGal << endl;
    
    // ask user if they want to run the problem again
    cout << "Again:\n";
    cin >> ans;
    
    // if ans is true, then display an endl
    if(ans=='Y' || ans=='y') cout << endl;

    } while(ans=='Y' || ans=='y');
    
    //Exit stage right or left!
    return 0;
}

// function calculates number of miles traveled per gallon of gas used to travel
float getMlsPrGal(int miles, int ltrsGas){
    
    // convert liters to gallons before dividing by number of miles traveled
    return miles/(ltrsGas * LTR2Gal); 
}