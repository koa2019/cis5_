/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 9:07 PM
 * Purpose:  Cross one-side or the other v6
 * working in code-e 4.26 @10:51 PM
 */

//System Libraries Here
#include <iostream>
#include <iomanip>  // setw()
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void oddsLoop(int, char);
void evensLoop(int, char);

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x,
                   num;
    char shape; //f-> forward b->backward x->cross

    //Input or initialize values Here
    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x >> shape;

    //Draw the shape  num;
    num = x % 2;

    // ***  EVEN ***
    if (num == 0) {

        evensLoop(x, shape);
     
    // ***  ODD ***
    } else if (num != 0) {
        
        oddsLoop(x, shape);

    } else cout << "error in else for num\n"; 

    //Exit
    return 0;
}

// *********** FUNCTION DEFITIONS ****************

// renders shape when x is an odd number
void oddsLoop(int x, char shape){
    
    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {

            switch(shape)
            {
                /*    X ODD 1, 8   */
                case 'x':
                case 'X': {
                    if (a3 == b2) cout << a2;
                    else if (a3 + b2 == x + 1) cout << a3;
                    else cout << " ";
                    break;
                }
                /*   ODD   \BACK\   DESCENDING  4 OR 5, 2 4 6  */
                case 'b':
                case 'B': {
                    if (a3 == b2) cout << a2;
                    else cout << " ";
                    break;
                }
                /*   ODD  /FORWARD/   ASCENDING  4 5?   */
                case 'f':
                case 'F': {
                    if (a3 + b2 == x + 1) cout << a3;
                    else cout << " ";
                    break;
                }
                default: cout << "Error in oddLoop() default.\n";
            } // closes switch()
        } // closes col for()
        cout << endl;
    } // closes row for()
} // closes void()

// renders shape when x is an even number
void evensLoop(int x, char shape){
    
    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {
            switch(shape)
            {
                /*   X  EVEN 7  */
                case 'x':
                case 'X': {
                    if (a3 == b2) cout << a3;
                    else if (a3 + b2 == x + 1) cout << a2;
                    else cout << " ";
                    break;
                }
                /*    EVEN  \BACK\  ASCENDING 4 OR 5    */
                case 'b':
                case 'B': {
                    if (a3 == b2) cout << a3;
                    else cout << " ";
                    break;
                }
                /*   EVEN  /FORWARD/   DESCENDING  1,3     */
                case 'f':
                case 'F': {
                    if (a3 + b2 == x + 1) cout << a2;
                    else cout << " ";
                    break;
                }
                default: cout << "Error in oddLoop() default.\n";
            } // closes switch()
        } // closes col for()
        cout << endl;
    } // closes row for()
} // closes void()
