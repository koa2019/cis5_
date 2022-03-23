/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 8:16 PM
 * Purpose:  Savitch 9th ed - ch3 - prb 3 - Roman Conversion
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    int num,
            n1s,
            n10s,
            n100s,
            n1000s;

    string roman;

    //Map inputs -> outputs
    cout << "Arabic to Roman numeral conversion.\n"
            << "Input the integer to convert.\n";
    cin >> num;

    //Display the outputs
    // calculates the number of 1000's from the number 
    n1000s = (num / 1000);

    // validates input is at least 1000 and less than 3000
    if (n1000s == 0 || n1000s >= 3) {
        cout << num << " is Out of Range!";
        return 0;
    }

    // calculates the number of 1's, 10's, 100's from the number 
    n1s = num % 10;           // 3001%10 = 1
    n10s = (num / 10) % 10;   // (1666/10)= 166.6%10 = 6
    n100s = (num / 100) % 10; // (2440/100)= 24%10 = 0

    //cout << n1000s << " " << n100s << " " << n10s << " " << n1s << endl;

    // conditional for 1000's and its expected output
    switch (n1000s) {
        case 1:
            roman = "M";
            break;
        case 2:
            roman = "MM";
            break;
        default:
            break;
    }
    
    // conditional  for 100's that adds to the roman string
    switch (n100s) {
        case 9:
            roman += "CM";
            break;
        case 8:
            roman += "DCCC";
            break;
        case 7:
            roman += "DCC";
            break;
        case 6:
            roman += "DC";
            break;
        case 5:
            roman += "D";
            break;
        case 4:
            roman += "CD";
            break;
        case 3:
            roman += "CCC";
            break;
        case 2:
            roman += "CC";
            break;
        case 1:
            roman += "C";
            break;
        default:
            break;
    }
    
    // conditional  for 10's that adds to the roman string
    switch (n10s) {
        case 9:
            roman += "XC";
            break;
        case 8:
            roman += "LXXX";
            break;
        case 7:
            roman += "LXX";
            break;
        case 6:
            roman += "LX";
            break;
        case 5:
            roman += "L";
            break;
        case 4:
            roman += "XL";
            break;
        case 3:
            roman += "XXX";
            break;
        case 2:
            roman += "XX";
            break;
        case 1:
            roman += "X";
            break;
        default:
            break;
    }

    // conditional  for 1's that adds to the roman string
    switch (n1s) {
        case 9:
            roman += "IX";
            break;
        case 8:
            roman += "VIII";
            break;
        case 7:
            roman += "VII";
            break;
        case 6:
            roman += "VI";
            break;
        case 5:
            roman += "V";
            break;
        case 4:
            roman += "IV";
            break;
        case 3:
            roman += "III";
            break;
        case 2:
            roman += "II";
            break;
        case 1:
            roman += "I";
            break;
        default:
            break;
    }

    cout << num << " is equal to " << roman;
    
    //Exit stage right or left!
    return 0;
}