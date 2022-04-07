/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 6, 8:22 PM
 * Purpose:  Savitch 9th Ed - ch4 - prb 2 - Fuel Eff
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // fixed, setprecision()
#include <cstring>  // string
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float LTR2Gal = 0.264179; // one liter equals 0.264179 gallons

//Function Prototypes
float getMlsPrGal(int, int);
void message(string);

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    char ans;       // holds answer to run program again
    int nLiters,    // number of liters of gasoline used
        nMiles; // number of miles traveled
    float mlsPrGal, // car 1 miles per gallon
          mlsPrGal2;  // car 2 miles per gallon

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

    //Exit stage right or left!
    return 0;
}

// function calculates number of miles traveled per gallon of gas used to travel
float getMlsPrGal(int miles, int ltrsGas) {

    // convert liters to gallons before dividing by number of miles traveled
    return miles / (ltrsGas * LTR2Gal);
}
// function displays message
void message(string car) {
    cout << car << " is more fuel efficient\n\n";
}