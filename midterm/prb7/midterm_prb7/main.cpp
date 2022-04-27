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
// PROBLEM 4 GLOBALS
const float PLANA = 16.99;
const float PLANB = 26.99;
const float PLANC = 36.99;

//problem7 Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

// PROBLEM 1 Function Prototypes 
void oddX(int);
void evenX(int);
void dsd_evenFwd(int);
void dsd_oddBk(int);
void asd_evenBk(int);
void asd_OddFwd(int);

//PROBLEM 3 Function Prototypes 
void convertNums(int, string &); // converts numbers 0-9 for thousands,hundreds, ones place
void convertTens(int, string &); // converts 10-90
void specialTens(int, string &); // converts 11-19

// PROBLEM 4 Function Prototypes
float pkgA(int);
float pkgB(int);
float pkgC(int);
string getBestA(int);
string getBestB(int);
string getBestC(int);
float getSavingsA(int, float);
float getSavingsB(int, float);
float getSavingsC(int, float);

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

// *****************************************************
// ****************** FUNCTION DEFITIONS ***************
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


// *****************************************************
// *************** PROBLEM 1 FUNCTIONs *****************
void problem1() {

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
} // END OF problem1

// ******** problem1 FUNCTIONS *****
//  ODD X
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
// EVEN X
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
//      ASCENDING
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
// *****  END OF PROBLEM 1 FUNCTION DEFTIONS  ********



// *****************************************************
// ************* START OF PROBLEM 2 FUNCTIONS **********
void problem2() {
  
    const char nRows = 4;
    int num;
    char input[4];

    //Input or initialize values Here
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> input;

    for (int row = 0; row < nRows; row++) {

        num = input[row];
       
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
            int digit = num;
            cout << digit << " ";
           
            for(int i=1;i<=digit;i++) {
                cout << "*";
                
            }
            cout <<endl;
            // catches any errors
        } else {
            cout << "Error in else." << endl;
        }
    }
    cout << "MSG 1  PROBLEM 2 BUG NOT DISPLAYING MSG 2...\n";
    cout << endl;
    cout << "MSG 2 PROBLEM 2 SHOULD END & EXIT HERE....\n";
}
// ******* END OF PROBLEM 2 FUNCTION DEFITIONS *******



// *****************************************************
// ************ START OF PROBLEM 3 FUNCTIONS ***********
void problem3() {
   
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
        case 19:{
            check += "Nineteen ";
            break;
        } case 18: {
            check += "Eighteen ";
            break;
        } case 17: {
            check += "Seventeen ";
            break;
        } case 16: {
            check += "Sixteen ";
            break;
        } case 15: {
            check += "Fifteen ";
            break;
        } case 14: {
            check += "Fourteen ";
            break;
        } case 13: {
            check += "Thirteen ";
            break;
        } case 12: {
            check += "Twelve ";
            break;
        } case 11: {
            check += "Eleven ";
            break;
        } default: cout << "Error in tens switch default.\n";
    }
}
// function converts numbers [10,90] and zero in tens place
void convertTens(int digit, string &check) {
    switch (digit) {
        case 9: {
            check += "Ninety ";
            break;
        } case 8: {
            check += "Eighty ";
            break;
        } case 7: {
            check += "Seventy ";
            break;
        } case 6: {
            check += "Sixty ";
            break;
        } case 5: {
            check += "Fifty ";
            break;
        } case 4: {
            check += "Forty ";
            break;
        } case 3: {
            check += "Thirty ";
            break;
        }  case 2: {
            check += "Twenty ";
            break;
        } case 1: {
            check += "Ten ";
            break;
        } case 0: {
            break;
        } default: cout << "Error in tens switch default.\n";
    }
}
// function for single digits [0,9] for the thousands, hundreds & ones place in check
void convertNums(int digit, string &check) {
    switch (digit) {
        case 9: {
            check += "Nine ";
            break;
        } case 8: {
            check += "Eight ";
            break;
        } case 7: {
            check += "Seven ";
            break;
        } case 6: {
            check += "Six ";
            break;
        } case 5: {
            check += "Five ";
            break;
        } case 4: {
            check += "Four ";
            break;
        } case 3: {
            check += "Three ";
            break;
        } case 2: {
            check += "Two ";
            break;
        } case 1: {
            check += "One ";
            break;
        } case 0: {
            break;
        } default: cout << "Error in switch default.\n";
    }
} // ******* END OF PROBLEM 3 FUNCTION DEFITIONS *******


// *****************************************************
// ******* START OF PROBLEM 4 FUNCTION DEFITIONS *******
void problem4() {

    const string A = "A ";
    const string B = "B ";
    const string C = "C ";

    char package;
    unsigned short hours;
    float bill = 0.0f,
            save = 0.0f;
    string cheapst = "";
    //bill_A += PLANA;

    //Input or initialize values Here
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> package>>hours;

    //Basic Charges
    switch (package) {
        case 'a':
        case 'A':
        {
            bill = pkgA(hours);
            cheapst = getBestA(hours);
            save = getSavingsA(hours, bill);
            break;
        }
        case 'b':
        case 'B':
        {
            bill = pkgB(hours);
            cheapst = getBestB(hours);
            save = getSavingsB(hours, bill);
            break;
        }
        case 'c':
        case 'C':
        {
            bill=pkgC(hours);
            cheapst=getBestC(hours);
            save=getSavingsC(hours, bill);
            break;
        }
        default: cout << "Error in switch package default.\n";
    }

    //Output the Charge
    cout << fixed << showpoint << setprecision(2);
    cout << setw(1) << "$" << setw(6) << left << bill;

    //Output the cheapest package and the savings
    cout << setw(2) <<cheapst << setw(1) << "$" << save << endl;
}
//********** PROBLEM 4 FUNCTIONS  *************
//****************** PACKAGE C ****************
string getBestC(int hrs) {

    string bestPlan;
    bestPlan = (hrs>0 && hrs<=10)? "A " :
    ((hrs >=11) && (hrs <=34)) ? "B " :
            (hrs >=35) ? "C " : "";
    return bestPlan;
}

float getSavingsC(int hrs, float cost) {

    float saving;
    if(hrs>0 && hrs<=10) saving=PLANC-PLANA;
    else if ((hrs >=11) && (hrs <=34)) saving = PLANC-PLANB;
    else if (hrs > 34) saving = 0;
    return saving;
}

// 
float pkgC(int hrs) {
    
    float cost;
    if(hrs>=0) cost= PLANC;
    return cost;
}

// ***********************************
//************ PACKAGE B *************
// 
float getSavingsB(int hrs, float cost) {

    float saving;
    if(hrs>0 && hrs<=10) saving=PLANB-PLANA;
    else if ((hrs >=11) && (hrs <= 34)) saving = 0;
    else if (hrs >=35) saving = cost-PLANC;
    return saving;
}

// 
string getBestB(int hrs) {

    string bestPlan;
    bestPlan = (hrs>0 && hrs<=10) ? "A " :
    ((hrs >=11) && (hrs <= 34)) ? "B " :
            (hrs >=35) ? "C " : "";
    return bestPlan;
}

// 
float pkgB(int hrs) {

    float cost;
    if(hrs>0) cost= PLANB;

    if (hrs > 30) {
        cost += (10 * .74);
        cost += ((hrs - 30)*.64);

    } else if (hrs > 20 && hrs < 31) cost += ((hrs - 20)*.74);
    else return cost;

    return cost;
}
// ****************************
// ******** PACKAGE A  ********
string getBestA(int hrs) {

    string bestPlan;
    bestPlan = ((hrs > 0) && (hrs <=20)) ? "A " :
            ((hrs >=21) && (hrs <=32)) ? "B " :
           (hrs >= 33) ? "C " :
            "Error in getBestA() else.\n";
    return bestPlan;
}

float getSavingsA(int hrs, float cost) {

    float saving;
    if ((hrs > 0) && (hrs <=20)) {
        saving = 0;
    } else if ((hrs >=21) && (hrs <=32)) {
        saving =cost- PLANB;
    } else if (hrs >= 33) {
        saving = cost - PLANC;
    } else "Error in getSavingsA() else.\n";

    return saving;
}

float pkgA(int hrs) {

    float cost;
    if(hrs>0) cost = PLANA;

    if (hrs > 20) {
        cost += (10 * .95);
        cost += ((hrs - 20)*.85);

    } else if (hrs > 10 && hrs < 21) cost += ((hrs - 10)*.95);
    else return cost;

    return cost;
}
// ******* END OF PROBLEM 4 FUNCTION DEFITIONS *******


// *****************************************************
// ********* START OF PROBLEM 5 FUNCTIONS **************

void problem5() {

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


// *****************************************************
// ************ START OF PROBLEM 6 FUNCTIONS ***********
void problem6() {

}

// ******* END OF PROBLEM 6 FUNCTION DEFITIONS *******