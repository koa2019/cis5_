/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: 5/12/22 12:00 PM 
 * Purpose: Standard deviation
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float MAXRAND=pow(2,31)-1;

//Function Prototypes
void  init4(float [],int);//Initialize the array
void  print4(float [],int,int);//Print the array
float avgX4(float [],int);//Calculate the Average
float stdX4(float [],float,int);//Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init4(test,SIZE);
    
    //Display the outputs
    //int nCols=5;
    //print(test,SIZE,nCols);
    
    float avg=avgX4(test,SIZE);
    cout << fixed << setprecision(7);
    cout<<"The average            = "<< avg << endl;
    cout<<"The standard deviation = "<<stdX4(test,avg, SIZE)<<endl;

    //Exit stage right or left!
    return 0;
}

//  *********** FUNCTION DEFINITIONS *************

// calculates standard deviation
float stdX4(float test[], float avg, int SIZE){
    
    float sum=0;
    float x;
    
    for(int i=0;i<SIZE;i++){
        
        x=pow( (test[i]-avg),2);
        sum+=x;
    }
    return sqrt(sum/(SIZE-1));
}

// calculates the average of all the floats in test array 
float avgX4(float test[], int SIZE){
    
    float avg=0;
    
    for(int i=0;i<SIZE;i++){
        avg+=test[i];
    }
    return avg/SIZE;
}

// read input from user
void  init4(float test[], int SIZE){
   
    for(int i=0;i<SIZE;i++){
        //cin >> test[i];
        test[i]=(i);
    }
}

// print array
void  print4(float test[],int SIZE,int nCols){
    
    for(int i=0;i<20;i++){
            cout << test[i] << " ";
    }
}