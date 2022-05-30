/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 6, 2022, 12:34 AM
 * Purpose:  assignment 2 - savitch_9thed_chp2_prb1_dietCoke
 */

//System Libraries
#include <iostream>  //Input/Output Library

using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float lb2Grms = 453.592;        // 1 lb = 453.592 grams
const float mRatio = 0.14285714285;   // deadly ratio of sugar is 1/7 of the mouse weight in grams
const float cSgrPrct = 0.001f * 350;  // 350g soda has 1/10 of 1% sweetner in it

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    float wLbs,     // dieter's weight in pounds
          wGrms,    // dieter's weight in grams
          hRatio;   // human's amount of sweetner they can consume before it's deadly
    int numCans;    // number of soda cans the dieter can consume
    

    //Map inputs -> outputs
    cout << "Program to calculate the limit of Soda Pop Consumption.\n";
    cout << "Input the desired dieters weight in lbs.\n";
    cin >> wLbs;
    
    wGrms = wLbs * lb2Grms;     // converts pounds to grams
    
    hRatio = wGrms * mRatio;    // gets deadly amount of sugar for human based on 1/7 mouse's ratio
    
    numCans = hRatio / cSgrPrct;  // gets number of soda cans a human can drink without dying
    
    //Display the outputs
    cout << "The maximum number of soda pop cans\n";
    cout << "which can be consumed is " << numCans << " cans";
    
    //Exit stage right or left!
    return 0;
}