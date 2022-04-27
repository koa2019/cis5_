/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 4:00 PM
 * Purpose:  Histogram v4 - calls print() 
 * expected input 0000, 5225, 87a9, .1Ab
 * v7
 */

//System Libraries Here
#include <iostream>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here

int main(int argc, char** argv) {

    int num;
    char input[4];

    //Input or initialize values Here
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> input;

    for (int row = 4; row>0; row--) {

        num = input[row-1];
       
        // conditional for special chars, A-Z or a-z or a Period in ASCII
        if ((num >= 33 && num <= 47) || (num >= 58 && num <= 126)) {

            cout << static_cast<char> (num) << " ?" << endl;

          // conditional for a blank space    
        } else if (num == 32) {
            cout << "  ?" << endl;

          // conditional for 0-9 in ASCII
        } else if ((num >= 48) && (num <= 57)) {

            int zero = 48;
            num -= zero; // https://www.softwaretestinghelp.com/cpp-character-conversion-functions/
            //cout << "num = " << num << endl;
            cout << num << " ";
           
            for(int i=1;i<=num;i++) {
                cout << "*";
            }
            cout <<endl;
            // catches any errors
        } else {
            cout << "Error in else." << endl;
        }
    }
    //Exit
    return 0;
}

// ******************* FUNCTION DEFITIONS  *****************
