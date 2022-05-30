/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 2, 2022,  10:00 PM
 * Purpose: gaddis 9th ed- ch6 - prob 9 - Present Value v1
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // pow()
using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes
float psntVal(float, float, int, float &);
void dsplyMsg(float);
void getInputs(float &, int&, float &);

// Program execution begins here
int main(int argc, char** argv) {
    
    // declare variables
    float pv,   // present value $ e, or the amount that you need to deposit today
          fv,   // future value $ that you want in the account
          rate; // annual interest rate
    int nYrs;   // number of years that you plan to let the money sit in the account.   
    
    // initial variables
    getInputs(fv, nYrs, rate);
    
    // map the inputs to the outputs
   psntVal(fv, rate, nYrs, pv);
    
    // exit code
    return 0;
}
// ********  FUNCTION DEFINITIONS   ************

// calculates present value. p=f/(1+r)^n
float psntVal(float f, float r, int n, float &pv){
    
    r/=100;
    pv=f/(pow((r+1),n));
    
    // Display inputs to outputs
    dsplyMsg(pv);
}

// display present value 
void dsplyMsg(float p){
cout << fixed << setprecision(2) << "The Present Value = $" << p;
}

// get ser inputs 
void getInputs(float &fv, int &nYrs, float &rate){
    
    cout << "This is a Present Value Computation\n"
         << "Input the Future Value in Dollars\n";
    cin >> fv;
    
    cout << "Input the Number of Years\n";
    cin >> nYrs;
    
    cout << "Input the Interest Rate %/yr\n";
    cin >> rate;
}