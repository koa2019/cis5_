/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 6, 9:32 PM
 * Purpose:  Savitch 9th Ed - ch4 - prb 9 - 2 or 3 Max
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //fixed, setprecision()
using namespace std;

//Function Prototypes
void invalid();

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    float num1, // input number 1
          num2, // input number 2
          num3, // input number 3
          max2, // max from 2 parameter function
          max3; // max from 3 parameter function
          
    //Initialize or input i.e. set variable values
    cout << "Enter first number:";
    cin >> num1;
    
    cout << "\n\nEnter Second number:";
    cin >> num2;
    
    cout << "\n\nEnter third number:";
    cin >> num3;
    
    // Map inputs -> outputs
    // conditional checks which of the first two inputs entered by user is the largest
    max2 = num2>num1 ? num2: num1;
    
  /*  
    // conditional checks which of the three inputs entered by user is the largest
    if ((num3>num2 && num2>num1) || (num3>num1 && num1>num2)) {
         max3=num3; 
    } else if ((num2>num1 && num1>num3) || (num2>num3 && num3>num1)) {
        max3=num2;
    } else if  ((num1>num2 && num2>num3) || (num1>num3 && num3>num2)) {
        max3=num1;
    } else invalid();
    
  */ 
  
  max3 = ((num3>num2 && num2>num1) || (num3>num1 && num1>num2)) ? num3 : 
    
  ((num2>num1 && num1>num3) || (num2>num3 && num3>num1)) ? num2 :
   
  ((num1>num2 && num2>num3) || (num1>num3 && num3>num2)) ? num1 : 0;
   
  

    
    //Display the outputs
    cout << fixed << setprecision(1);
    cout << "\n\nLargest number from two parameter function:"
         << endl << max2 << endl<<endl;
    cout << "Largest number from three parameter function:"
         << endl << max3 << endl;

    //Exit stage right or left!
    return 0;
}
void invalid(){
    cout << "Invalid Entry.";
}