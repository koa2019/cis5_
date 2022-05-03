/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 9:07 PM
 * Purpose:  Cross one-side or the other
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
void dsd_evenFwd(int);
void oddF(int);
void evenB(int);
void dsd_oddBk(int);
void oddX(int);
void evenX(int);

void asd_OddFwd(int);
void asd_OddBk(int);
//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape; //f-> forward b->backward x->cross

    //Input or initialize values Here
    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x>>shape;

    //Draw the shape
    unsigned short num;
    num = x % 2;






    // ***  EVEN ***
    if (num == 0) {

        // FORWARD /// DESCENDING
        if ((shape == 'f') || (shape == 'F')) dsd_evenFwd(x);

            /*  BACK \\\\\\ DESCENDING    */
        else if ((shape == 'b') || (shape == 'B')) {
            cout << "Even back slash  DESCENDING\n";

            int c = 0;
            for (int a = x; a >= 1; a--) {
                for (int b = 1; b <= x; b++) {
                    //cout<<b;
                }
                cout << setw(c) << setfill(' ') << "";
                cout << setw(a) << left << setfill(' ') << a << endl;
                c++;
            }
        } else if (num == 0) { //     X EVEN   7  

            evenX(x);
        }

        // ***  ODD ***
    } 

    if (num != 0) {

        // FORWARD /// DESCENDING
        if ((shape == 'f') || (shape == 'F')) {
            int d = 0;
            for (int j = x; j >= 1; j--) {
                for (int i = 1; i <= x; i++) {
                }
                cout << setw(j) << setfill(' ') << j;
                cout << setw(d) << setfill(' ') << "" << endl;
                d++;
            }
        }/*  BACK \\\\\\ DESCENDING    */
        else if ((shape == 'b') || (shape == 'B')) dsd_oddBk(x);

            //    X ODD 1 & 8
        else if ((shape == 'x') || (shape == 'X')) oddX(x);

    } 

    //Exit
    return 0;
}
// *********** FUNCTION DEFITIONS ****************

// WORKING ON THIS ONE!

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

// ascending order, x=even and forward slash

void asd_OddFwd(int x1) {
    int d = 5;
    int e = 0;
    for (int j = 1; j <= 5; j++) {
        for (int i = 1; i <= x1; i++) {
        }

        cout << setw(d) << setfill(' ') << j
                << setw(e) << setfill(' ') << "" << endl;
        d--;
        e++;

    }
}

// ascending order, x=even and back slash

void asd_OddBk(int x1) {
    //cout << "Odd Fwd"<<endl;
    int d = 0;
    for (int j = 1; j <= x1; j++) {
        for (int i = 1; i <= x1; i++) {
        }
        cout << setw(j) << setfill(' ') << j;
        cout << setw(d) << setfill(' ') << "" << endl;
        d++;
    }
}

// descending order. x=even and forward slash

void dsd_evenFwd(int x1) {
    //cout << "Even"<<endl;
    int d = 0;
    for (int j = x1; j >= 1; j--) {
        for (int i = 1; i <= x1; i++) {
        }
        cout << setw(j) << setfill(' ') << j;
        cout << setw(d) << setfill(' ') << "" << endl;
        d++;
    }
}

// descending order, x=odd and back slash

void dsd_oddBk(int x2) {
    //cout << "Odd"<<endl;
    int c = 0;
    for (int a = x2; a >= 1; a--) {
        for (int b = 1; b <= x2; b++) {
            //cout<<b;
        }
        cout << setw(c) << setfill(' ') << "";
        cout << setw(a) << left << setfill(' ') << a << endl;
        c++;
    }
}