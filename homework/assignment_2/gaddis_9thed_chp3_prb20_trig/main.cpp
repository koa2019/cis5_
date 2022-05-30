/* 
 * File:   main.cpp
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 5, 2022, 10:45 PM
 * Purpose:  assignment 2 - gaddis_9thed_chp3_prb20_trig
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cmath>    // M_PI
#include <iomanip>  // fixed, setprecision()
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    float degrees,      // degrees
          dgToRdn,      // degrees to radian conversion
          sine,        // sin trig variable
          cosine,      // cosine trig variable
          tang;       // tangent trig variable
          
    //Map inputs -> outputs
    cout << "Calculate trig functions\n";
    cout << "Input the angle in degrees.\n";
    cin >> degrees;
    
    dgToRdn = degrees*(M_PI/180);   // convert degrees to radians
    sine = sin(dgToRdn);            // gets sin() in radians
    cosine = cos(dgToRdn);          // gets cos() in radians
    tang = tan(dgToRdn);            // gets tan() in radians
    
    //Display the outputs
    cout << fixed << setprecision(4);
    cout << "sin(" << int(degrees) << ") = " << sine << endl;
    cout << "cos(" << int(degrees) << ") = " << cosine << endl;
    cout << "tan(" << int(degrees) << ") = " << fixed << tang;


    //Exit stage right or left!
    return 0;
}