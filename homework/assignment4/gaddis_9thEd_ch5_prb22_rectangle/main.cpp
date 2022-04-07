/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 6:30 PM
 * Purpose:  Gaddis 9th Ed - ch5 - prb 22 - Rectangle
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    char letter; // user input. Character that forms the rectangle
    int input, // integer user inputs
        row; // each row of the rectangle

    //Initialize user inputs
    cin >> input >> letter;

    // validates user input is positive integer and less than 16
    if (!(input > 0) && (input < 16)) {

        cout << "Invalid Entry.\n";
        return 0;
    }

    //Map inputs -> outputs
    // loop for number of rows based on number the user inputed
    for (row = 1; row <= input; row++) {

        // loop prints out number of columns in the row based on the number the user inputed
        for (int col = 1; col <= input; col++) {

            //Display the char the user inputed
            cout << letter;

        } // end of col loop

        // on the last row it skips displaying the endl
        if (row == input) continue;
        cout << endl;

    } // end of row loop

    //Exit stage right or left!
    return 0;
}