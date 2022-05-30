/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 17, 2022, 8:08 PM
 * Purpose: Gaddis - 9th ed - #18 - Energy Drinks
 */

// System Libraries: 
#include <iostream>     // input/output library
using namespace std;


// Program execution begins here
int main(int argc, char** argv) {
    
    // declare variables
    int numOneOrMore,     // number of customers who buy 1 or energy drinks per week 
         numCitrus;           // number of customers who prefer citrus flavored energy drinks
    
    // initialize variables
    int numCust = 16500;                    // number of customers an energy drink company surveyed 
    
    float percentOneOrMore = .15;       // percent of customers who buy one or more drinks per week
    
    float percentCitrus = .58;              // percent of customers who prefer citrus flavored energy drinks
    
    
    // calculates approximate number of customers who buy 1+ drinks/week
    // and who prefer citrus flavored by 
    // multiplying number of customers surveyed by a percentage
    numOneOrMore = numCust * percentOneOrMore;  // calculates # of customers 
    
    numCitrus = numCust * percentCitrus;                // # of customers  
    
    
    // Display inputs to outputs
    cout <<"This program calculates the approximate number of customers \n";
    cout << "that buy one or more energy drinks per week and \n";
    cout << "the approximate number of customers that prefer citrus flavored energy drinks. \n";
    cout << "--------------------------------------------------------\n";
    cout <<"Number of customers surveyed: " << numCust << endl;
    cout << numOneOrMore << " customers drink one or more energy drinks per week.\n";
    cout << numCitrus << " customers prefer citrus flavored energy drinks.\n";
    
    // exit code
    return 0;
}