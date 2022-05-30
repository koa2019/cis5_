/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February 21, 2022, 7:23 PM
 * Purpose: savitch - 10th ed - ch1 - prob 1 - Sum & Product
 */

// System Libraries: 
#include <iostream>
using namespace std;

// Program execution begins here
int main(int argc, char** argv) {
    
    // declare variables
    float num1, num2;
    
    // map the inputs to the outputs
    cout << "This program asks for two numbers and \n";
    cout << "then displays their sum and product \n\n";
    
    cout << "Enter your first number and then press Enter ";
    cin >> num1;
    
    cout << "Enter your second number and then press Enter ";
    cin >> num2;
    
    // adds user's 2 numbers
    float sum = num1 + num2;
    
    // multiplies the user's 2 numbers
    float product = num1 * num2;
    
    // Display inputs to outputs
    cout<<"The sum of " << num1 << " + "<< num2 << " = " << sum<<endl;
    cout<<"The product of " << num1 << " x "<< num2 << " = " << product<<endl;
    
    // exit code
    return 0;
}