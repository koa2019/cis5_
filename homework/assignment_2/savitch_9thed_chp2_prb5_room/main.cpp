/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 6, 2022, 2:00 PM
 * Purpose:  assignment 2 - savitch_9thed_chp2_prb5_room 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   // string
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int max,
                   numPpl;
    int exclude, aval;
                   
    
    //Map inputs -> outputs
    cout << "Input the maximum room capacity and the number of people\n";
    cin >> max >> numPpl;
    
    exclude = numPpl - max;
     
    aval =  max - numPpl;

    //Display the outputs

    if(exclude > 0)  {
      
        cout << "Meeting cannot be held.\n"
             << "Reduce number of people by " 
             << exclude
             << " to avoid fire violation.";
             
    } else {
        
        cout << "Meeting can be held.\n"
             << "Increase number of people by "
             << aval 
             << " will be allowed without violation.";
    }

    //Exit stage right or left!
    return 0;
}