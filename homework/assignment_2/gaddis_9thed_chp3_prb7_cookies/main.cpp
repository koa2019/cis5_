/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 5, 2022, 9:19 PM
 * Purpose:  assignment 2 - gaddis_9thed_chp3_prb7_cookies
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // setprecision()
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int numCookie,  // number of cookies user ate 
        calEatn,     //total number of calories user ate 
        calPerCk, // number of calories in each cookie
        totalCal;   // total number of calories in 1 bag of cookies
    
    //Initialize or input i.e. set variable values
    int CkInbag = 40;       // number of cookies in 1 bag 
    int ttlSrv = 10;    // number of servings in 1 bag of cookies     
    int calInSrv = 300; // number of calories in 1 serving of cookies
    
    // calculate total number of calories in one bag  of cookies 
    // multiply total number of servings by number of calories per serving
    totalCal = ttlSrv * calInSrv;   
    
    // calculate number of calories in one cookie
    // divide total calories in 1 bag of cookies by number of cookies in 1 bag
    calPerCk = totalCal/CkInbag;
    
    //Map inputs -> outputs
    cout << "Calorie Counter\n";
    cout << "How many cookies did you eat?\n";
    cin >> numCookie;
    
    // calculate number of calories user consumed by
    // multiplying number of calories ina serving by number
    calEatn = calPerCk * numCookie;
    
    //Display the outputs
    cout << "You consumed " << calEatn << " calories.";
    
    //Exit stage right or left!
    return 0;
}