/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: May 5, 2022 @ 12:01  PM 
 * Purpose: Dice Table Sum v1
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;

//Function Prototypes
void dsplyIntro();
void printSum(const int, const int);
void printColZero(const int, const int, int);

void fillTbl(int [][COLS],int);
void prntTbl(const int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int ROWS=6;
    int tablSum[ROWS][COLS];
    
    dsplyIntro();
    
    //Initialize or input i.e. set variable values
    //fillTbl(tablSum,ROWS);
    printSum(ROWS,COLS);
    
    //Display the outputs
    //prntTbl(tablSum,ROWS);

    //Exit stage right or left!
    return 0;
}

//  *********** FUNCTION DEFINITIONS ************

// for ROWS 1 thru 6, prints COL[0] 
void printColZero(const int ROWS, const int COLS, int i){
            
    switch(i){
        case 1: {
            cout << setw(4) << i << setw(2) << "|";
            break;
        } case 2: {
            cout << setw(1) << "R" << setw(3) << i << setw(2) << "|" ;
            break;
        } case 3: {
            cout << setw(1) << "O" << setw(3) << i << setw(2) << "|" ;
            break;
        } case 4: {
            cout << setw(1) << "W" << setw(3) << i << setw(2) << "|" ;
            break;
        } case 5: {
            cout << setw(1) << "S" << setw(3) << i << setw(2) << "|" ;
            break;
        } default: cout << setw(4) << i << setw(2) << "|" ;
    }
}

// calculates the sum by adding ROWS[i] and COLS[j]
void printSum(const int ROWS, const int COLS){
    
    for(int i=1; i<ROWS+1; i++){
        
        for(int j=0; j<COLS+1; j++){
            
            if(j==0) printColZero(ROWS,COLS, i);
            else {
            
            // prints sum of row+col
            int rowSum=i+j;
            cout << setw(4) << rowSum;
            }
        }
        cout << endl;
    }
}
void fillTbl(int [][COLS],int){
    
    
}

void prntTbl(const int [][COLS],int){
    
}

// displays programs introduction
void dsplyIntro(){
    cout << "Think of this as the Sum of Dice Table\n"
         << setw(11) << setfill(' ') << " " << setw(14) << right << "C o l u m n s\n"
         << setw(6) << "|" << "   1   2   3   4   5   6" << endl
         << "----------------------------------" << endl;
}