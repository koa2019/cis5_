/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Histogram v1 passes test cases 1-3
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
    cin >> num;
    
    //cout << "input = " << input<<endl;
 
    d1 = num / 1000;
    d2 = (num / 100) % 10;
    d3 = (num / 10) % 10;
    d4 = num % 10;
   /*
        cout << static_cast<int> (d1) << endl;
        cout << static_cast<int> (d2) << endl;
        cout << static_cast<int> (d3) << endl;
        cout << static_cast<int> (d4) << endl << endl;
  */   
     
    //Histogram Here
    print(d1);
    print(d2);
    print(d3);
    print(d4);

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