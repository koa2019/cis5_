/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 5:46 PM
 * Purpose:  Gaddis 9th ed - ch4 prb11 - books
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   // setw()
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned short nBks,    // number of books purchased
                   points;  // number of points earned
                   
    
    //Map inputs -> outputs
    cout << "Book Worm Points\n"
         << "Input the number of books purchased this month.\n";
    cin >> nBks;
    
    // condition checks number of books purchased and then assigns a value to points
    points = nBks==0? 0:
            nBks==1? 5:
            nBks==2? 15:
            nBks==3? 30: 60;
    
    //Display the outputs
    cout << setw(16) << left << "Books purchased" << setw(3) << "=" << nBks
         << "\nPoints earned   = " << points;
         
    //Exit stage right or left!
    return 0;
}