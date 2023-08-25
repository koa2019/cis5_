/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February , 2022,  M
 * Purpose: template
 */

// System Libraries: 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes

// Program execution begins here
int main(int argc, char** argv) {
    // set random number seed
    
    // declare variables
    const float PI = 3.14159;
    const float SLICE_AREA = 14.125;
    const int SLICE_PER_PERSON = 4;
    
    int radius, nPpl=20, diam = 36;
    float area, numSlic, numPiz, slices_needed;
        
    // map the inputs to the outputs
    radius = diam/2;
    area = (radius * radius)*PI;
    numSlic = area/SLICE_AREA;
    slices_needed = nPpl * SLICE_PER_PERSON;
    numPiz = slices_needed/numSlic;
    
    // Display inputs to outputs
    cout << fixed << setprecision(1);
    cout<<"Diameter: "<< diam <<endl;
    cout << "Radius: "<< radius << endl;
    cout << "Area: " << area << endl;
    cout << "A " << diam << " inch pizza has " << numSlic << " slices in it\n";
    cout << nPpl << " people need " << slices_needed << " slices\n";
    cout << numPiz << " number of pizzas needed\n";
    
    
    // exit code
    return 0;
}