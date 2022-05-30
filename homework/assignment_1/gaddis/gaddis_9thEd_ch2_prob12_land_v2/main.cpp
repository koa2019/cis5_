/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 24, 2022, 10:20 AM
 * Purpose: Gaddis - 9th ed - #12 v2- land calculation
 */

// System Libraries: 
#include <iostream>
#include <cmath>    // math library
using namespace std;

// Global Constants
const float ACRFT2 = 43560; // conversion from 1 acre to feet^2
const float FTMILE = 5280; // conversion 5280 feet = 1 mile

// Program execution begins here

int main(int argc, char** argv) {

    float nAcres,       // number of acres
           nSqMls,      // number of square miles
           ft2,            // area in ft^2
           perMls;      // perimeter in square miles     

    // get feet^2 from user
    cout << "Program performs land calculations\n";
    cout << "Input  the square footage to convert \n";
    cin >> ft2;

     // get number of acres. Divide user's feet^2 by acre conversion
    nAcres = ft2 / ACRFT2;

    // get number of miles^2. Divide feet^2 by foot to mile conversion twice
    nSqMls = ft2 / FTMILE / FTMILE;
    
    // get perimeter of land. Square root of number of miles^2 and then multiply by 4
    perMls = 4 * sqrt(nSqMls);

    // output
    cout << "Square footage = " << ft2 << " ft^2\n";
    cout << "The number of acres = " << nAcres << " acres \n";
    cout << "Number of miles squared = " << nSqMls << " miles^2 \n";
    cout << "The perimeter in miles = " << perMls << " miles\n";

    // exit code
    return 0;
}

