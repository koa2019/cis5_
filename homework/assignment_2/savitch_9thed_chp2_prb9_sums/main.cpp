/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 6, 2022, 4:00 PM
 * Purpose:  assignment 2 - savitch_9thed_chp2_prb9_sums
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   // setw(), setprecision()

using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    int negSum,   // negative int sum
        posSum,   // positive int sum
        totlSum,  // total int sum
        input;   // Int to input 10 times

    //Initialize or input i.e. set variable values
    negSum = posSum = totlSum = 0;

    //Map inputs -> outputs
    cout << "Input 10 numbers, any order, positive or negative" << endl;

    for (int i = 0; i < 10; i++) {

        cin >> input;
       // cin >> input >> input >> input >> input >> input >> input >> input >> input >> input >> input;
        
        negSum += input > 0 ? 0 : input; // ternary operator

        posSum += input > 0 ? input : 0; //another example of ternary operator
    }
    
    // calculate total sum of negative and positive numbers
    totlSum = negSum + posSum;


    //Display the outputs
    cout  << "Negative sum =" << setw(4) << negSum << endl;
    
    cout << setw(14) << left << "Positive sum =" << setw(4) << right << posSum << endl;
    
    cout << setw(9) << left << "Total sum" << setw(5) << right << "=" << setw(4) << totlSum; 
    
    //Exit stage right or left!
    return 0;
}