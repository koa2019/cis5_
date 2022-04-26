/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on February , 2022,  M
 * Purpose: template
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>
using namespace std;

// Global Constants
// Physics/Chemistry/Math/Conversions
const float LTR2Gal = 0.264179; // one liter equals 0.264179 gallons

// Function prototypes
void introMsg();
void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q8();
void q9();
void q10();
float getMlsPrGal(int, int); // function for q6() & q7()
void message(string); // function for q7()
float getInfltion(float, float); // function for q8() & q9()
float incrCost(float, float); // functions for q9()
void invalid();

// Program execution begins here
int main(int argc, char** argv) {
   
    // declare variables
    char ans;
    unsigned short choice;

    do {
        // initial variables
        introMsg();
        cin >> choice;

        // map the inputs to the outputs
        switch (choice) {
            case 1:
                q1();
                break;
            case 2:
                q2();
                break;
            case 3:
                q3();
                break;
            case 4:
                q4();
                break;
            case 5:
                q5();
                break;
            case 6:
                q6();
                break;
            case 7:
                q7();
                break;
            case 8:
                q8();
                break;
            case 9:
                q9();
                break;
            case 10:
                q10();
                break;
            default: cout << "Invalid input\n";
        }

        cout << "\nAgain?\n";
        cin >> ans;

    } while (ans == 'Y' || ans == 'y');

    // exit code
    return 0;
}

// ********* FUNCTION DEFINITIONS ********
// intro message
void introMsg() {
    cout << "\nPress 1 for Question 1\n"
            << "Press 2 for Question 2\n"
            << "Press 3 for Question 3\n"
            << "Press 4 for Question 4\n"
            << "Press 5 for Question 5\n"
            << "Press 6 for Question 6\n"
            << "Press 7 for Question 7\n"
            << "Press 8 for Question 8\n"
            << "Press 9 for Question 9\n"
            << "Press 10 for Question 10\n";
}

// Gaddis 9th ed. ch5 prb 1 Sum
void q1() {
    unsigned short num,
            sum = 0;

    //Map inputs -> outputs
    cout << "Question 1 - Sum\n";
    cout << "Enter a number\n";
    cin >> num;

    for (int i = 1; i <= num; i++) {
        sum += i;
    }

    //Display the outputs
    cout << "Sum = " << sum << endl;
}

// Gaddis 9th ed. ch5 prb 7 Pay in Pennies
void q2() {

    //Declare Variables
    const int INCRMNT = 2;
    int nDays;
    double pennies = .01,
            ttlPay = 0.0f;

    //Initialize variable values
    cout << "Question 2 - Pay in Pennies\n";
    cout << "Enter number of days worked.";
    cin >> nDays;

    if ((nDays < 1)) { // user input must be at least 1 day of work

        cout << "Invalid Entry. Number of days CAN NOT be less than 1.\n";

    } else {

        //Map inputs -> outputs
        for (int i = 1; i <= nDays; i++) {

            ttlPay += pennies; // starts by adding minimum of 1 day of pay
            pennies *= INCRMNT; // increaments each day of pay by 2
        }
        cout << fixed << setprecision(2);
        cout << "Pay = $" << ttlPay << endl;
        /*
                int dollars = ttlPay / 100; // gets number of dollars
                ttlPay %= 100; // gets number of pennies within totalpay

                //Display the outputs
                cout << fixed << setprecision(2);
                cout << "Pay = $" << dollars << "." << setw(2) << setfill('0') << right << ttlPay << endl;
         */
    }
}

// Gaddis 9th ed. ch5 prb 13 Min Max
void q3() {

    //Declare Variables
    int input, // user input
            min, // smallest number in the series of inputs
            max; // largest number in the series of inputs

    cout << "Question 3 - Min Max\n";
    cout << "Enter an integer. \n -99 to stop.\n";
    cin >> input;

    //Initialize max & min to the user's initial input 
    min = max = input;

    while (input != -99) { // validates input is NOT -99

        //Map inputs -> outputs
        input < min ? min = input : // tests for the smallest integer based on the user's inputs
                input > max ? max = input : // tests for the smallest integer based on the user's inputs
                input = input; // else input equals input
        cin >> input; // read in next input from user
    }

    //Display the outputs
    cout << "Smallest number in the series is " << min << endl;
    cout << "Largest  number in the series is " << max << endl;
}

// Gaddis 9th ed. ch5 prb 22 rectangle
void q4() {
    
    //Declare Variables
    char letter; // user input. Character that forms the rectangle
    int input, // integer user inputs
            row; // each row of the rectangle

    //Initialize user inputs
    cout << "Question 4.\n"
            << "Enter an integer then a symbol.\n";
    cin >> input >> letter;

    // validates user input is positive integer and less than 16
    if ((input < 16) && (input > 0)) {

        //Map inputs -> outputs
        // loop for number of rows based on number the user inputed
        for (row = 1; row <= input; row++) {

            // loop prints out number of columns in the row based on the number the user inputed
            for (int col = 1; col <= input; col++) {

                //Display the char the user inputed
                cout << letter;
            }

            // on the last row it skips displaying the endl
            if (row == input) continue;
            cout << endl;
        }
    } else cout << "Invalid Entry.\n";
}

// Gaddis 9th ed. ch5 prb 23 Pattern
void q5() {

    //Declare Variables
    const char X = '+';
    int input; // user integer input

    //Initialize input
    cout << "Enter an integer\n";
    cin >> input;

    // first loop displays number of rows dependent on user's input
    for (int row = 1; row <= input; row++) {

        // loop displays X in acesending order
        for (int col = 1; col <= row; col++) {

            cout << X;
        }
        cout << endl << endl;
    }

    // second loop displays number of rows dependent on user's input
    for (int row2 = 1; row2 <= input; row2++) {

        // loop displays X in decesending order
        for (int i = input; i >= row2; i--) {

            cout << X;
        }

        // on the last row it skips displaying the endl
        if (row2 == input)break;
        cout << endl << endl;
    }
}

// Savtich 9th ed. ch4 prb 1 MPG
void q6() {
    
    //Declare Variables
    char ans;
    int ltrsUsd,
            nMiles;
    float mlPrGal;

    do {

        //Initialize or input i.e. set variable values
        cout << "Enter number of liters of gasoline:\n\n";
        cin >> ltrsUsd;
        cout << "Enter number of miles traveled:\n\n";
        cin >> nMiles;

        // call function to calculate miles per gallon traveled
        mlPrGal = getMlsPrGal(nMiles, ltrsUsd);

        //Display the outputs
        cout << fixed << setprecision(2);
        cout << "miles per gallon:\n" << mlPrGal << endl;

        // ask user if they want to run the problem again
        cout << "Again:\n";
        cin >> ans;

        // if ans is true, then display an endl
        if (ans == 'Y' || ans == 'y') cout << endl;

    } while (ans == 'Y' || ans == 'y');
}
// functions for q6() & q7()
// function calculates number of miles traveled per gallon of gas used to travel
float getMlsPrGal(int miles, int ltrsGas) {

    // convert liters to gallons before dividing by number of miles traveled
    return miles / (ltrsGas * LTR2Gal);
}

// Savtich 9th ed. ch4 prb Fuel Efficiency 
void q7() {

    //Declare Variables
    char ans; // holds answer to run program again
    int nLiters, // number of liters of gasoline used
            nMiles; // number of miles traveled
    float mlsPrGal, // car 1 miles per gallon
            mlsPrGal2; // car 2 miles per gallon

    //Map inputs -> outputs
    do {
        // initialize inputs for car 1
        cout << "Car 1\n"
                << "Enter number of liters of gasoline:";
        cin >> nLiters;

        cout << "\nEnter number of miles traveled:";
        cin >> nMiles;

        // call function to calculate miles per gallon traveled
        mlsPrGal = getMlsPrGal(nMiles, nLiters);

        // display outputs
        cout << fixed << setprecision(2);
        cout << "\nmiles per gallon: " << mlsPrGal;

        // initialize inputs for Car 2
        cout << "\n\nCar 2\n"
                << "Enter number of liters of gasoline:";
        cin >> nLiters;

        cout << "\nEnter number of miles traveled:";
        cin >> nMiles;

        // call function to calculate miles per gallon traveled
        mlsPrGal2 = getMlsPrGal(nMiles, nLiters);

        cout << fixed << setprecision(2);
        cout << "\nmiles per gallon: " << mlsPrGal2 << endl << endl;

        // conditional determines which car gets better gas miles
        // and displays a message accordingly
        mlsPrGal > mlsPrGal2 ? message("Car 1") : message("Car 2");

        // ask user if they want to run program again
        cout << "Again:";
        cin >> ans;
        cout << endl;

        // if ans is true, then display an endl
        if (ans == 'Y' || ans == 'y') cout << endl;

    } while (ans == 'Y' || ans == 'y');
}

// functions for q7(). Displays message
void message(string car) {
    cout << car << " is more fuel efficient\n\n";
}

// Savtich 9th ed. ch4 prb 4 Inflation
void q8() {

    //Declare Variables
    char ans; // hold answer to loop again or not
    float curPrce, // current price 
            prvPrce, // previous year-ago price
            infRate; // inflation rate

    do {

        //Initialize inputs
        cout << "Enter current price:";
        cin >> curPrce;

        cout << "\nEnter year-ago price:";
        cin >> prvPrce;

        //Map inputs -> outputs
        infRate = getInfltion(curPrce, prvPrce);

        //Display the outputs
        cout << fixed << setprecision(2);
        cout << "\nInflation rate: " << infRate << "%\n\n";

        cout << "Again:";
        cin >> ans;
        cout << endl;

        // if ans is true, then display an endl
        if (ans == 'Y' || ans == 'y') cout << endl;

    } while (ans == 'Y' || ans == 'y');
}

// function for q8() & q9()
// Function estimates inflation rate as 
// difference in price divide by previous year-ago price
float getInfltion(float current, float prvious) {
    return (current - prvious) / prvious * 100;
}

//Savtich 9th ed. ch4 prb 5 Est Cost
void q9() {

    //Declare Variables
    char ans; // hold answer to loop again or not
    float curPrce, // current price 
            prvPrce, // previous year-ago price
            infRate, // inflation rate
            oneYr, // price in one year
            twoYr; // price in two years

    do {

        //Initialize inputs
        cout << "Enter current price:";
        cin >> curPrce;

        cout << "\nEnter year-ago price:";
        cin >> prvPrce;

        //Map inputs -> outputs
        infRate = getInfltion(curPrce, prvPrce);
        oneYr = incrCost(infRate, curPrce);
        float infRateYr2 = getInfltion(oneYr, curPrce);
        twoYr = incrCost(infRateYr2, oneYr);

        //Display the outputs
        cout << fixed << setprecision(2);
        cout << "\nInflation rate: " << infRate << "%\n\n";

        cout << "Price in one year: $" << oneYr;
        cout << "\nPrice in two year: $" << twoYr << endl;

        cout << "\nAgain:";
        cin >> ans;
        cout << endl;

        // if ans is true, then display an endl
        if (ans == 'Y' || ans == 'y') cout << endl;

    } while (ans == 'Y' || ans == 'y');
}

// functions for q9()
// function estimates increased cost
float incrCost(float iRate, float currnt) {
    float incCost = currnt + ((iRate / 100) * currnt);
    return incCost;
}

// Savtich 9th ed. ch4 prb 9 2 or 3
void q10() {

    //Declare Variables
    float num1, // input number 1
            num2, // input number 2
            num3, // input number 3
            max2, // max from 2 parameter function
            max3; // max from 3 parameter function

    //Initialize or input i.e. set variable values
    cout << "Enter first number:";
    cin >> num1;

    cout << "\n\nEnter Second number:";
    cin >> num2;

    cout << "\n\nEnter third number:";
    cin >> num3;

    // Map inputs -> outputs
    // conditional checks which of the first two inputs entered by user is the largest
    max2 = num2 > num1 ? num2 : num1;

    max3 = ((num3 > num2 && num2 > num1) || (num3 > num1 && num1 > num2)) ? num3 :

            ((num2 > num1 && num1 > num3) || (num2 > num3 && num3 > num1)) ? num2 :

            ((num1 > num2 && num2 > num3) || (num1 > num3 && num3 > num2)) ? num1 : 0;

    //Display the outputs
    cout << fixed << setprecision(1);
    cout << "\n\nLargest number from two parameter function:"
            << endl << max2 << endl << endl;
    cout << "Largest number from three parameter function:"
            << endl << max3 << endl;
}