/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 22, 2022,  11:16 AM
 * Purpose:  savitch - 10th ed - ch1 - problem 4 - distance
 */

// System Libraries: 
#include <iostream>
using namespace std;

// Global Constants
const float ACC = 32.174f;     // acceleration due to gravity 32 ft/sec^2

// Program execution begins here
int main(int argc, char** argv) {
    
    // declare variables
    float numSec,     // time in free fall in seconds
            dist;         // distance in free fall feet
    
    
    // map the inputs to the outputs
    cout << "This program calculates the distance drop in free fall. \n";
    cout << "Assumes no drag!\n";
    cout << "Enter a time in seconds. ";
    cin >> numSec;
    
    // calculates the distance
    dist = (ACC * (numSec * numSec))/2;
            
    // Display inputs to outputs
    cout << "\nDistance an object free falls in " << numSec;
    cout << " seconds is " << dist << " ft" << endl;
    
    // exit code
    return 0;
}