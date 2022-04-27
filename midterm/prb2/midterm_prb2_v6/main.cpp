/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 4:00 PM
 * Purpose:  Histogram v4 - calls print() 
 * expected input 0000, 5225, 87a9, .1Ab
 * v6 code-e @837pm 4/26
 */

//System Libraries Here
#include <iostream>
#include <cstring>
#include <string>


using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void print(int);

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    const char nRows = 4;
    int num;
    char input[4];


    //Input or initialize values Here
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> input;


    for (int row = 0; row < nRows; row++) {

        num = input[row];
        //cout << "num b4 ifs "<<num << " "<<endl;

        // conditional for special chars, A-Z or a-z or a Period in ASCII
        if ( (num>=33 && num<=47) || (num>=58 && num<=126) ) {
            
            cout << static_cast<char> (num) << " ?" << endl;

            // conditional for a blank space    
        } else if (num==32) {
            cout << "  ?" << endl;

        }// conditional for 0-9 in ASCII
        else if ((num>=48) && (num<=57)) {

            int zero = 48;
            num -= zero; // https://www.softwaretestinghelp.com/cpp-character-conversion-functions/
            int n2 = num;
            cout << n2 << " ";

            print(n2);
           
            // catches any errors
        } else cout << "Error. in else." << endl;
    }

    //Exit
    return 0;
}

// ******************* FUNCTION DEFITIONS  *****************

void print(int digit) {

    switch (digit) {
        case 0:
        {
            cout << ""<<endl;
            break;
        }
        case 1:
        {
            cout << "*"<<endl;
            break;
        }
        case 2:
        {
            cout << "**"<<endl;
            break;
        }
        case 3:
        {
            cout << "***"<<endl;
            break;
        }
        case 4:
        {
            cout << "****"<<endl;
            break;
        }
        case 5:
        {
            cout << "*****"<<endl;
            break;
        }
        case 6:
        {
            cout << "******"<<endl;
            break;
        }
        case 7:
        {
            cout << "*******"<<endl;
            break;
        }
        case 8:
        {
            cout << "********"<<endl;
            break;
        }
        case 9:
        {
            cout << "*********"<<endl;
            break;
        }
        default:
        {
            cout << "You landed in switch default.\n";
        }
    } // closes switch()
}