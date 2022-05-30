/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: May 9, 2022 @ 11:01  AM 
 * Purpose: Dice Table Sum v3 
 * uses double array and calls prntTbl() in main()
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;   // LEHR's
const int SEVEN=7;  // MINE

//Function Prototypes
void dsplyIntro();
void printColZero(int);

void fillTbl(int [][COLS],int); // LEHR VERSION
void fillTbl(int [][SEVEN],int); // MY VERSION

void prntTbl(const int [][COLS],int);   //LEHR
void prntTbl(int [][SEVEN], int);  // MY VERSION


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    const int ROWS=6;       // LEHR's
    int tablSum[ROWS][COLS];// LEHR's
    int sum[SEVEN][SEVEN];  // MINE
   
   //Initialize arrays to zero
    tablSum[0][0]={0};      
    sum[0][0]={0};
    
    // call function to display intro message to user
    dsplyIntro();
    
    // get sums of row+col
    fillTbl(sum,ROWS);   
    //fillTbl(tablSum,ROWS);  // LEHR   VERSION
       

    //Display the outputs
    prntTbl(sum, ROWS);
    //prntTbl(tablSum,ROWS); // LEHR VERSION

    
    //Exit stage right or left!
    return 0;
}

//  *********** FUNCTION DEFINITIONS ************

// LEHR VERSION
void fillTbl(int tablSum[][COLS], int ROWS){  

    
	   
}

//  MY VERSION
void fillTbl(int sum[][SEVEN], int ROWS){

    //cout << "sum " << sum[0][0] << endl;
    
    //
    for(int i=1; i<ROWS+1; i++){
       
        for(int j=0; j<COLS+1; j++){
            
            // prints sum of row+col
            sum[i][j]=i+j;
            //cout << setw(4) << tablSum[i][j];
            //cout << " [" <<i<<"]+[" << j << "]= " << tablSum[i][j];
        }
        //cout << endl;
    }
}

// MY VERSION
void prntTbl(int sum[][SEVEN],int ROWS){
    
   for(int i=1; i<ROWS+1; i++){
        for(int j=0; j<COLS+1; j++){
            
             if(j==0) printColZero(i);
            else {
                cout << setw(4) << sum[i][j];
                //cout << " " <<i<<"+" <<j<< "= " << sum[i][j];
            }
        }
        cout << endl;
    }
}

//  LEHR VERSION
void prntTbl(const int tablSum[][COLS],int ROWS){

	
}

// for ROWS 1 thru 6, prints COL[0] 
void printColZero(int i){
          
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
void dsplyIntro(){
    int blank=4;
    cout << "Think of this as the Sum of Dice Table\n"
         << setw(11) << setfill(' ') << " " << setw(14) << right << "C o l u m n s\n"
         << setw(blank+2) << "|" ;
         
    for(int j=0;j<COLS;j++){
        cout << setw(blank) << (j+1) << setw(blank) << setfill(' ');
    }
    cout << endl << "----------------------------------" << endl;
}