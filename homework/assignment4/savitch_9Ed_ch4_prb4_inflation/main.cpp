/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 6, 8:53 PM
 * Purpose:  Savitch 9th Ed - ch4 - prb 4 - Inflation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   // fixed, setprecision()
using namespace std;

//Function Prototypes
float getInfltion(float, float);

//Execution Begins Here!
int main(int argc, char** argv) {

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

    //Exit stage right or left!
    return 0;
}

// Function estimates inflation rate as 
// difference in price divide by previous year-ago price
float getInfltion(float current, float prvious) {
    return (current - prvious) / prvious * 100;
}