/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 4:00 PM
 * Purpose:  Histogram v2 
 * expected input 0000, 5225.
 * Can't handle non-digit inputs like 123a
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
    int d1,
            d2,
            d3,
            d4;
    int num;
    string string1;
    char input[4];


    //Input or initialize values Here
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> input;

    for (int i = 0; i < 4; i++) {

        num = input[i];
        if (num <= 57 && num >= 48) {
            int zero = 48;
            num -= zero;                                                        // https://www.softwaretestinghelp.com/cpp-character-conversion-functions/
            //cout << num << " " << endl;
            print(num);
        } else {
            cout << static_cast<char> (num) << " ?" << endl;
        }
    }
/*
    cout << "num "<<num;
    cout <<"hello";

    d1 = static_cast<int>(num) / 1000;
    d2 = (static_cast<int>(num) / 100) % 10;
    d3 = (static_cast<int>(num) / 10) % 10;
    d4 = static_cast<int>(num) % 10;
    cout << "d1 "<<d1;
    
  
         cout << static_cast<int> (d1) << endl;
         cout << static_cast<int> (d2) << endl;
         cout << static_cast<int> (d3) << endl;
         cout << static_cast<int> (d4) << endl << endl;
     */
/*
    //Histogram Here
    print(d1);
    print(d2);
    print(d3);
    print(d4);
*/
    //Exit
    return 0;
}

void print(int digit) {

    switch (digit) {
        case 0:
        {
            cout << "0 \n";
            break;
        }
        case 1:
        {
            cout << "1 *\n";
            break;
        }
        case 2:
        {
            cout << "2 **\n";
            break;
        }
        case 3:
        {
            cout << "3 ***\n";
            break;
        }
        case 4:
        {
            cout << "4 ****\n";
            break;
        }
        case 5:
        {
            cout << "5 *****\n";
            break;
        }
        case 6:
        {
            cout << "6 ******\n";
            break;
        }
        case 7:
        {
            cout << "7 ******\n";
            break;
        }
        case 8:
        {
            cout << "8 ********\n";
            break;
        }
        case 9:
        {
            cout << "9 *********\n";
            break;
        }
        default:
        {
            cout << "You landed in switch default.\n";
        }
    }
}