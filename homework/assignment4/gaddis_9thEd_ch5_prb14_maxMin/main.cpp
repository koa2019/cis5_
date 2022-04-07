/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 5:21 PM
 * Purpose:  Gaddis 9th Ed - ch5 - prb 13 - Min Max
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    int input,  // user input
        min,    // smallest number in the series of inputs
        max;    // largest number in the series of inputs
   
    cin >> input;
    
    //Initialize max & min to the user's initial input 
    min=max=input;
    
    while (input !=-99){        // validates input is NOT -99
        
         //Map inputs -> outputs
        input<min ? min=input :     // tests for the smallest integer based on the user's inputs
        input>max ?  max=input :   // tests for the smallest integer based on the user's inputs
        input=input;               // else input equals input
        cin >> input;             // read in next input from user
    }
        
    //Display the outputs
    cout << "Smallest number in the series is " << min << endl;
    cout << "Largest  number in the series is " << max;
    
    //Exit stage right or left!
    return 0;
}