/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 5, 2022, 10:10 PM
 * Purpose:  assignment 2 - gaddis_9thed_chp3_prb8_insurance
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    const float minPrcnt = .80;   // minimum percent house should be insuraced for
    
    float house,       // the worth of the uder's house
          minAmnt;    // minimum amount house should be insured for
    
    //Map inputs -> outputs
    cout << "Insurance Calculator\n";
    cout << "How much is your house worth?\n";
    cin >> house;
    
    minAmnt = house * minPrcnt; // minimum amount the house should be insured for
    
    //Display the outputs
    cout << "You need $" << minAmnt << " of insurance.";
    
    //Exit stage right or left!
    return 0;
}