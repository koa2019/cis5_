/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 27, 2022 1:00 PM
 * Purpose:  Infinite Series v1
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int factora1(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float x,fx;
    int nterms, fact;
    
    //Input or initialize values Here
    cout<<"Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+......."<<endl;
    cout<<"Input x and the number of terms, output f(x)"<<endl;
    cin>> x >> nterms;
    
    //Calculate Sequence sum here
    float sum=0.0f;
    for(int terms=1, count=1; terms<=nterms;terms++){
        
        //cout << endl << " LOOP "<<terms<<endl;
        fact=factora1(count);   // sends in odd numbers 1,3,5...
        //cout << count <<"! = " << fact << endl;
        
        float power = (pow(x,count));
        //cout << "pow_x_nterms = " << pow_x_nterms << endl;
        
        fx = power/fact;
        //cout << "fx = 1/" << fact << " = " << fx << endl;
        
        if(fx!=1) fx *=-1;
        //cout << "fx *-1 = " << fx << endl;
        
        sum += fx;
        count +=2;  // expected 1,3,5
        //cout << "sum inside = "<< sum <<endl;          
    }
    //cout << " outside fx = " << fx << endl;        
    //cout << "sum += "<< sum << endl;
    
    //Output the result here
    cout << fixed << setprecision(6)<< "sum outside = " << sum << endl;
    
    //Exit
    return 0;
}   
//   ************ FUNCTION DEFITIONS ***********

// !n==!3==(1*2*3).  recursive function if n>1. 
int factora1(int n){
    //Base Condition
    if(n<=1)return 1;
    //Recursive Call
    return factora1(n-1)*n; // ie n=3, then (3-1)*3==2*3--> return 6
}
