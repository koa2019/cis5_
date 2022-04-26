/* 
 * File:   main.cpp
 /* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 25, 2022 9:36PM
 * Purpose:  Menu to be used in the Midterm, future homework and the Final
 *           Add System Libraries and Functions as needed.
 */

//System Libraries
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//problem 1 Functions   
void dsd_evenFwd(int);
void oddF(int);
void evenB(int);
void dsd_oddBk(int);
void oddX(int);
void evenX(int);
void asd_OddFwd(int);
void asd_OddBk(int);

//PROBLEM 2 Prototypes
void print(int);

//PROBLEM 3 Function Prototypes 
void convertNums(int, string &); // converts numbers 0-9 for thousands,hundreds, ones place
void convertTens(int, string &); // converts 10-90
void specialTens(int, string &); // converts 11-19


//Execution Begins Here!

int main(int argc, char** argv) {
    //Set a Random number seed here.

    //Declare Main variables here.
    int inN;

    //Loop on each problem
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            default: def(inN);
        }
    } while (inN < 7);

    //Exit Stage Right Here!
    return 0;
}

void Menu() {
    cout << endl;
    cout << "Type 1 to execute Problem 1" << endl;
    cout << "Type 2 to execute Problem 2" << endl;
    cout << "Type 3 to execute Problem 3" << endl;
    cout << "Type 4 to execute Problem 4" << endl;
    cout << "Type 5 to execute Problem 5" << endl;
    cout << "Type 6 to execute Problem 6" << endl;
    cout << "Type anything else to exit." << endl << endl;
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN) {
    cout << endl << "Typing " << inN << " exits the program." << endl;
}

// ***** PROBLEM 1 FUNCTION DEFTIONS  ********

void problem1() {

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

    if ((shape == 'x') && (num != 0)) {

        oddX(x);
        //asd_OddFwd(x);
        //asd_OddBk(x);

    }// even number conditional for x
    else if (num == 0) {
        dsd_evenFwd(x);

        // odd number conditional for x
    } else if (num != 0) {
        dsd_oddBk(x);

    } else {
        cout << "Error in else";
    }

}

void oddX(int x3) {
    int p, z, h;

    // DONT TOUCH
    int d = 5;
    int e = 0;
    for (int j = 1; j <= 5; j++) {
        //for(int j=1; j<=5;j++){
        for (int i = 1; i <= x3; i++) {
            //for(int i=1;i<=x3;i++){
        }
        // empty space before j    
        cout << setw(d) << setfill(' ') << j
                << setw(e) << setfill('*') << ""
                << endl;
        d--;
        e++;
    }
    cout << endl;

    // DONT TOUCH
    int c = 0;
    for (int a = x3; a >= 1; a--) {
        for (int b = 1; b <= x3; b++) {
            //cout<<b;
        }
        cout << setw(c) << setfill(' ') << ""
                << setw(a) << left << setfill(' ') << a
                << endl;
        c++;
    }
    cout << endl;


    // loops for X
    h = 0;
    p = 4;
    z = 1;
    for (int a = x3; a >= 1; a--) {
        //p=5;
        //p--;
        for (int b = 1; b <= x3; b++) {
            //cout<<b;
        }
        //--p;
        cout << setw(h) << setfill(' ') << "" << a
                << setw(p) << z
                << endl;
        //cout<<"p = "<<p<<endl;
        h++;
        p--;
        //--p;
        z++;
        /*
            cout <<setw(c)<< setfill(' ') << ""; 
            cout << setw(4) << left << setfill(' ') << a;
            cout << setw(1) << setfill('!') << a <<endl;
         */
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
}// *****  END OF PROBLEM 1 FUNCTION DEFTIONS  ********


// ******* START OF PROBLEM 2 FUNCTION DEFITIONS *******

void problem2() {
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
        if ((num >= 33 && num <= 47) || (num >= 58 && num <= 126)) {

            cout << static_cast<char> (num) << " ?" << endl;

            // conditional for a blank space    
        } else if (num == 32) {
            cout << "  ?" << endl;

        }// conditional for 0-9 in ASCII
        else if ((num >= 48) && (num <= 57)) {

            int zero = 48;
            num -= zero; // https://www.softwaretestinghelp.com/cpp-character-conversion-functions/
            int digit = num;
            //cout << n2 << " ";

            //print(n2);
            switch (digit) {
                case 0:
                {
                    cout << digit << "" << endl;
                    break;
                }
                case 1:
                {
                    cout << digit << " *" << endl;
                    break;
                }
                case 2:
                {
                    cout << digit << " **" << endl;
                    break;
                }
                case 3:
                {
                    cout << digit << "***" << endl;
                    break;
                }
                case 4:
                {
                    cout << digit << "****" << endl;
                    break;
                }
                case 5:
                {
                    cout << digit << "*****" << endl;
                    break;
                }
                case 6:
                {
                    cout << digit << "******" << endl;
                    break;
                }
                case 7:
                {
                    cout << digit << "*******" << endl;
                    break;
                }
                case 8:
                {
                    cout << digit << "********" << endl;
                    break;
                }
                case 9:
                {
                    cout << digit << "*********" << endl;
                    break;
                }
                default:
                {
                    cout << "You landed in switch default.\n";
                }
            } // closes switch()


            // catches any errors
        } else {
            cout << "Error. in else." << endl;

        }
    }
    cout << endl;
}

void print(int digit) {

    switch (digit) {
        case 0:
        {
            cout << "" << endl;
            break;
        }
        case 1:
        {
            cout << digit << " *" << endl;
            break;
        }
        case 2:
        {
            cout << digit << " **" << endl;
            break;
        }
        case 3:
        {
            cout << "***" << endl;
            break;
        }
        case 4:
        {
            cout << "****" << endl;
            break;
        }
        case 5:
        {
            cout << "*****" << endl;
            break;
        }
        case 6:
        {
            cout << "******" << endl;
            break;
        }
        case 7:
        {
            cout << "*******" << endl;
            break;
        }
        case 8:
        {
            cout << "********" << endl;
            break;
        }
        case 9:
        {
            cout << "*********" << endl;
            break;
        }
        default:
        {
            cout << "You landed in switch default.\n";
        }
    } // closes switch()
}// ******* END OF PROBLEM 2 FUNCTION DEFITIONS *******


// ******* START OF PROBLEM 3 FUNCTION DEFITIONS *******

void problem3() {
    //Declare all Variables Here
    const string thousnd = "Thousand "; // concat to dollar string
    const string hundred = "Hundred "; // concat to dollar string
    const string cents = "and no/100's Dollars"; // concat to end of dollar string

    unsigned short num, // user input between 1-3000
            n1000s, // thousands digit
            mod, // holds modules value
            n100s, // hundreds digit
            n10s, // tens digit
            n1s; // ones digit
    string dollars; // holds string of converted numbers

    // validate user input [1,3000]
    do {
        //Input or initialize values Here
        cout << "Input an integer [1-3000] convert to an English Check value." << endl;
        cin>>num;
    } while ((num < 1) && (num > 3000));

    //Calculate the 1000's, 100's, 10's and 1's
    n1000s = (num / 1000); // calculates single digit that represents thousands place in num
    mod = (num % 1000); // calculates number between [1,999]
    n100s = mod / 100; // calculates single digit that represents hundreds place in num
    n10s = mod % 100; // calculates number between [11-99]. ie 987%900=87
    n1s = mod % 10; // calculates single digit that represents ones place in num

    // cout << n1000s << "\t " << n100s << "\t " << n10s << "\t " << n1s  << endl;

    // calls ref variable function to convert thousands place digit to words
    convertNums(n1000s, dollars);

    // conditional only concats if thousands place is NOT equal zero
    if (n1000s != 0) dollars += thousnd;

    // calls ref variable function to convert hundreds place digit to words
    convertNums(n100s, dollars);

    // conditional only concats if hundreds place is NOT equal zero
    if (n100s != 0) dollars += hundred;

    // conditional checks for numbers [11,19] 
    if (n10s >= 11 && n10s <= 19) {
        specialTens(n10s, dollars); // calls ref variable function to convert thousands place digit to words
    } else {
        n10s /= 10; // calculates single digit that represents tens place in num
        convertTens(n10s, dollars); // calls ref variable function to convert tens place digit to words
        convertNums(n1s, dollars); // calls ref variable function to convert ones place digit to words
    }

    dollars += cents;
    //Output the check value
    cout << dollars << endl;
}
// function converts numbers between 11-19 in tens place

void specialTens(int digit, string &check) {
    switch (digit) {
        case 19:
        {
            check += "Nineteen ";
            break;
        }
        case 18:
        {
            check += "Eighteen ";
            break;
        }
        case 17:
        {
            check += "Seventeen ";
            break;
        }
        case 16:
        {
            check += "Sixteen ";
            break;
        }
        case 15:
        {
            check += "Fifteen ";
            break;
        }
        case 14:
        {
            check += "Fourteen ";
            break;
        }
        case 13:
        {
            check += "Thirteen ";
            break;
        }
        case 12:
        {
            check += "Twelve ";
            break;
        }
        case 11:
        {
            check += "Eleven ";
            break;
        }
        default: cout << "Error in tens switch default.\n";
    }
}
// function converts numbers [10,90] and zero in tens place

void convertTens(int digit, string &check) {
    switch (digit) {
        case 9:
        {
            check += "Ninety ";
            break;
        }
        case 8:
        {
            check += "Eighty ";
            break;
        }
        case 7:
        {
            check += "Seventy ";
            break;
        }
        case 6:
        {
            check += "Sixty ";
            break;
        }
        case 5:
        {
            check += "Fifty ";
            break;
        }
        case 4:
        {
            check += "Forty ";
            break;
        }
        case 3:
        {
            check += "Thirty ";
            break;
        }
        case 2:
        {
            check += "Twenty ";
            break;
        }
        case 1:
        {
            check += "Ten ";
            break;
        }
        case 0:
        {
            break;
        }
        default: cout << "Error in tens switch default.\n";
    }
}
// function for single digits [0,9] for the thousands, hundreds & ones place in check

void convertNums(int digit, string &check) {
    switch (digit) {
        case 9:
        {
            check += "Nine ";
            break;
        }
        case 8:
        {
            check += "Eight ";
            break;
        }
        case 7:
        {
            check += "Seven ";
            break;
        }
        case 6:
        {
            check += "Six ";
            break;
        }
        case 5:
        {
            check += "Five ";
            break;
        }
        case 4:
        {
            check += "Four ";
            break;
        }
        case 3:
        {
            check += "Three ";
            break;
        }
        case 2:
        {
            check += "Two ";
            break;
        }
        case 1:
        {
            check += "One ";
            break;
        }
        case 0:
        {
            break;
        }
        default: cout << "Error in switch default.\n";
    }
} // ******* END OF PROBLEM 3 FUNCTION DEFITIONS *******


// ******* START OF PROBLEM 4 FUNCTION DEFITIONS *******

void problem4() {

}

// ******* END OF PROBLEM 4 FUNCTION DEFITIONS *******


// ******* START OF PROBLEM 5 FUNCTION DEFITIONS *******

void problem5() {

    //Declare all Variables Here
    const int HRS20 = 20;
    const int HRS40 = 40;
    const float RATE1_5 = 1.5;
    const int RATE2 = 2;

    float payRate,
            regPay,
            tmeNHlf,
            dblTme;
    unsigned short hrsWrkd;

    //Input or initialize values Here
    cout << "Paycheck Calculation." << endl;
    cout << "Input payRate in $'s/hour and hours worked" << endl;
    cin >> payRate>>hrsWrkd;
    cout << fixed << setprecision(2);

    //Calculate Paycheck
    float maxRgPy = HRS20*payRate;

    if (hrsWrkd <= HRS20) { //1

        regPay = hrsWrkd*payRate;

        //Output the check
        cout << "$" << regPay << endl;

    } else if (hrsWrkd > HRS20 && hrsWrkd <= HRS40) {//2

        tmeNHlf = (hrsWrkd - HRS20)*(payRate * RATE1_5);
        tmeNHlf += maxRgPy;

        //Output the check
        cout << "$" << tmeNHlf << endl;

    } else if (hrsWrkd > HRS20 && hrsWrkd > HRS40) { //03

        tmeNHlf = HRS20 * (payRate * RATE1_5);
        dblTme = (hrsWrkd - HRS40)*(payRate * RATE2);
        dblTme += maxRgPy + tmeNHlf;

        //Output the check
        cout << "$" << dblTme << endl;

    } else {
        cout << "Invalid Input.\n";
    }

} // ******* END OF PROBLEM 5 FUNCTION DEFITIONS *******


// ******* START OF PROBLEM 6 FUNCTION DEFITIONS *******

void problem6() {

}

// ******* END OF PROBLEM 6 FUNCTION DEFITIONS *******