/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 17, 2022, 8:32 PM
 * Purpose: Gaddis - 9th ed - #19 - High Temperatures - 
 */

// System Libraries: 
#include <iostream>     // input/output library
#include <cmath>        // round()
using namespace std;

// Global Constants
const float RISE = .02;     // temperatures in July rise by 2%


// Program execution begins here
int main(int argc, char** argv) {
    
    // declare variables
    float tempNyc,      // New York City's increased average July temperature
           tempDnvr,   // Denver's increased average July temperature
           tempPhx;    // Phoenix's increased average July temperature
    
    
    // initialize variables
    // starting temperatures for each city
    int nyc = 85;          // NYC July's average temperature in degrees Fahrenheit
    int denver = 88;     // Denver July's average temperature in degrees Fahrenheit
    int phx = 106;       // Phoenix  July's average temperature in degrees Fahrenheit

    
   // calculates each city's new average July temperature by
   // multiplying city's temp by 2% and then adds it to city's starting temperature
    tempNyc = (nyc * RISE) + nyc;   
    tempDnvr = (denver * RISE) + denver;
    tempPhx = (phx * RISE) + phx;
    
    
    // Display inputs to outputs
    cout << "This program calculates and reports the new average\n";
    cout << "temperature if it rose by 2% in July. \n\n";
    cout << "City\t\tOld Temp\tNew Temp"<< endl;
    cout << "----------------------------------------" << endl;
    cout << "NYC    \t\t" << nyc << "\t\t" << round(tempNyc) <<endl;
    cout << "Denver\t\t" << denver << "\t\t" << round(tempDnvr) <<endl;
    cout << "Phoenix\t\t" << phx << "\t\t" << round(tempPhx) <<endl;
    
    // exit code
    return 0;
}