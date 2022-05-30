/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 5, 2022, 10:20 PM
 * Purpose:  assignment 2 - gaddis_9thed_chp3_prb10_temp
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // fixed, setprecision()

using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    float newFhrn,    // new Fahrenheit 
          fahren,     // Fahrenheit temperature
          cel;        // Celsius temperature
        
    //Map inputs -> outputs
    cout << "Temperature Converter\n";
    cout << "Input Degrees Fahrenheit\n";
    cin >> fahren;
    
    newFhrn = fahren-32;    // Fahrenheit given minus 32
    
    cel = ( (float)5 / 9 ) * newFhrn;  // Fahrenheit to Celsius conversion formula
    
    //Display the outputs
    cout << fixed << setprecision(1);
    cout << fahren << " Degrees Fahrenheit = " << cel << " Degrees Centigrade";
    
    //Exit stage right or left!
    return 0;
}