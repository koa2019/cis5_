/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 17, 2022, 12:00 PM
 * Purpose: Gaddis - 9th ed - #20 - Paint Coverage
 */

// System Libraries: 
#include <iostream> // input/output library
#include <cmath>    // floor()
using namespace std;

// Program execution begins here
int main(int argc, char** argv) {

    // declare variables
    float numPaintCans,     // total number of cans of paint needed
           sArea,                // surface area
           cArea;               // coverage area

    // initialize variables
    int paintCoverage = 340;    // 1 gallon of paint covers 340 sq ft
    int length = 100;               // length of fence
    int height = 6;                  // height of fence
    int numSides = 4;            // number of sides of the fence that need to be painted

   // calculates surface area = length x height
    sArea = length * height;        
    
    // calculates coverage area to paint fence twice on each side.
    // Area paint needs to cover = surface area x 4 sides of fence
    cArea = sArea * numSides;          
    
    // gets number of paint cans needed 
    // divide coverage area by paint coverage and then adds 1 to round up
    numPaintCans = cArea / paintCoverage + 1; 

    
    // Display inputs to outputs
    cout << "This program calculates the number of cans of paint \n";
    cout << "required to paint a fence on both sides twice \n\n";
    cout << "Fence length: " << length << " feet \n";
    cout << "Fence height: " << height << " feet \n";
    cout << "Paint coverage: " << paintCoverage << " feet^2/gallon \n";
    cout << "Surface Area = " << sArea << " feet^2 \n";
    cout << "Number of paint cans needed: " << floor(numPaintCans);

    // exit code
    return 0;
}
