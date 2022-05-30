/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 5-9-22 11:05 PM
 * Purpose:  Product Table v1
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=7;   

//Function Prototypes
void dsplyIntro2(int);
void printColZero2(int);

// LEHR's functions
void fillTbl2(int [][COLS],int);
void prntTbl2(const int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int ROWS=7;       // LEHR's
    int tblProd[ROWS][COLS]={};// LEHR's
    
    int nRows, nCols;
    
    cout << "\nProblem 2 Product Table\n"
         << "Input number rows and number cols\n";
    cin >> nRows >> nCols;
    
    // call function to display intro message to user
    dsplyIntro2(nCols);
    
    // get product of row*col
    fillTbl2(tblProd,ROWS);  // LEHR's
    
    //Display the outputs
    prntTbl2(tblProd,ROWS);  // LEHR's

    //cout << "\nHit end of prb2 main()\n";
    
    //Exit stage right or left!
    return 0;
}

//   ********** FUNCTION DEFINITIONS  **********

void fillTbl2(int tblProd[][COLS],int ROWS ){    
    
     for(int i=0; i<ROWS; i++){       
        for(int j=0; j<COLS; j++){
            
            // prints sum of row+col
            tblProd[i][j]=(i)*(j);
            //cout << setw(4) << tblProd[i][j];
           //cout << " [" <<i<<"]*[" <<j<< "]=" << tblProd[i][j];
        }
        //cout << endl;
    }
}

// display table contents
void prntTbl2(const int tblProd[][COLS],int ROWS){   // LEHR's
    
    for(int i=1; i<ROWS; i++){
        
        for(int j=0; j<COLS; j++){
            
            if(j==0) printColZero2(i);
           else {
                cout << setw(4) << tblProd[i][j];
                //cout << " [" <<i<<"]*[" <<j<< "]=" << tblProd[i][j];
            }
        }
        cout << endl;
    }    
   // cout << "\nHit prntTbl2()\n";
}

// for ROWS 1 thru 6, prints COL[0] 
void printColZero2(int i){
          
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

// displays intro message to user
void dsplyIntro2(int nCols){
    int blank=4;
    cout << "Think of this as a Product/Muliplication Table" << endl
         << setw(11) << setfill(' ') << " " << setw(14) << right << "C o l u m n s\n"
         << setw(blank+2) << "|" ;
    
    // prints blanks and then 1-6
    for(int j=0;j<nCols;j++){
        cout << setw(blank) << (j+1) << setw(blank) << setfill(' ');
    }
    cout << endl << "----------------------------------" << endl;
}