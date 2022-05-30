/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 5, 2022, 9:00 PM
 * Purpose:  assignment 2 - gaddis-9thed-chp3-prb3-average
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // setprecision()
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    float n1,n2,n3,n4,n5,   // number 1 through 5
          total,      // sum of all the numbers together
          avg;        // average of all the numbers
    
    //Initialize or input i.e. set variable values
    int count = 5;      // amount of number to divide by to find the average


    //Map inputs -> outputs
    cout << "Input 5 numbers to average.\n";
    
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    
    total = n1+n2+n3+n4+n5;     // sum of all the inputs
    
    avg = total/count;              // total divided by the number of inputs
    
    //Display the outputs
    cout << "The average = " << setprecision(1) <<fixed << avg;
    
    //Exit stage right or left!
    return 0;
}