/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 5, 2022, 10:45 PM
 * Purpose:  assignment 2 - paycheck
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // fixed, setprecision()

using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float rate,      // pay rate dollars per hour
          hrs,       // hours worked
          normPay,   // paycheck in dollars
          ovrPay,    // paycheck in dollars
          ovrtime,   // overtime
          dblTime;   // overtime is double the rate
        
   
    //Map inputs -> outputs
    cout << "This program calculates the gross paycheck.\n";
    cout << "Input the pay rate in $'s/hr and the number of hours.\n";
    cin >> rate >> hrs;
    
    normPay = rate * hrs;           // paycheck for 40 hrs or less worked
    
    ovrPay = rate * 40;             // overtime pay for 40 hrs worked
    
    dblTime = (hrs-40)*(rate * 2);  // double time - if hours worked is more than 40 hrs
    
    ovrtime = ovrPay + dblTime;     // overtime equals the sum of overtime pay and double time
    
    hrs <= 40 ? normPay : ovrtime;  // conditional checks if user gets normal pay or overtime
    
    
    //Display the outputs
    
    // conditional displays message depending on number of hours worked is less than or equal to 40 hours or not
    hrs <= 40 ? cout << "Paycheck = $" << setw(7) << fixed << setprecision(2) << normPay : 
        cout << "Paycheck = $" << setw(7) << fixed << setprecision(2) << ovrtime;
    
    
    //Exit stage right or left!
    return 0;
}