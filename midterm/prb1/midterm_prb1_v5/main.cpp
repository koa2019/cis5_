/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 9:07 PM
 * Purpose:  Cross one-side or the other
 */

//System Libraries Here
#include <iostream>
#include <iomanip>  // setw()

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void oddX(int);
void evenX(int);
void dsd_evenFwd(int);
void dsd_oddBk(int);
void asd_evenBk(int);
void asd_OddFwd(int);

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape; //f-> forward b->backward x->cross

    //Input or initialize values Here
    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x >> shape;

    //Draw the shape
    unsigned short num;
    num = x % 2;


    // ***  EVEN ***
    if (num == 0) {

        //   EVEN  /FORWARD/ DESCENDING
        if ((shape == 'f') || (shape == 'F')) dsd_evenFwd(x);

            /*   EVEN  \BACK\   DESCENDING    */
        else if ((shape == 'b') || (shape == 'B')) asd_evenBk(x);
        
        //     X EVEN   7     
        else if ((shape == 'x') || (shape == 'X')) evenX(x);
     
    // ***  ODD ***
    } else if (num != 0) {

        //   ODD  /FORWARD/   DESCENDING
        if ((shape == 'f') || (shape == 'F')) asd_OddFwd(x);
           
        /*   ODD   \BACK\   DESCENDING    */
        else if ((shape == 'b') || (shape == 'B')) dsd_oddBk(x);

        //    X ODD 1 & 8
        else if ((shape == 'x') || (shape == 'X')) oddX(x);

    } else cout << "error in else for num\n"; 

    //Exit
    return 0;
}
// *********** FUNCTION DEFITIONS ****************


void oddX(int x) {

    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {

            if (a3 == b2) cout << a2;
            else if (a3 + b2 == x + 1) cout << a3;
            else cout << " ";
        }
        cout << endl;
    }
}

void evenX(int x) {

    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {

            if (a3 == b2) cout << a3;
            else if (a3 + b2 == x + 1) cout << a2;
            else cout << " ";
        }
        cout << endl;
    }
}

// *********************
//    DESCENDING
// *********************

//    ODD  \BACK\  DESCENDING TC2,4,6
void dsd_oddBk(int x) {
    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {
            if (a3 == b2) cout << a2;
            else cout << " ";
        }
        cout << endl;
    }
}

//    EVEN  /FORWARD/   DESCENDING  TC1,3
void dsd_evenFwd(int x) {
    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {
            
            if (a3 + b2 == x + 1) cout << a2;
            else cout << " ";
        }
        cout << endl;
    }
}

// *********************
//    ASCENDING
// *********************

//    EVEN  \BACK\  ASCENDING tc 5
void asd_evenBk(int x){
    for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {
            if (a3 == b2) cout << a3;
            else cout << " ";
        }
        cout << endl;
    }
}

//    ODD   /FORWARD/   ASCENDING TC5
void asd_OddFwd(int x) {
  for (int a2 = x, a3 = 1; a2 >= 1; a2--, a3++) {
        for (int b2 = 1; b2 <= x; b2++) {
            if (a3 + b2 == x + 1) cout << a3;
            else cout << " ";
        }
        cout << endl;
    }
}