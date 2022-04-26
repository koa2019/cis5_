/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 9:07 PM
 * Purpose:  Cross one-side or the other 
 * Version 1: solves even forward lash /. Test case 1 & 3
 * expected input 4 f
 */

//System Libraries Here
#include <iostream>
#include <iomanip>  // setw()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape;       //f-> forward b->backward x->cross
    
    //Input or initialize values Here
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin>>x>>shape;
    
    //Draw the shape
    unsigned short num;
    num=x%2;
    
    // conditional for when x is an even number
    if(num==0){
        //cout << "Even"<<endl;
       int d=0;
        for(int j=x; j>=1;j--){        
           
            for(int i=1;i<=x;i++){               
            }           
        cout << setw(j) << setfill('.') << j;        
        cout <<setw(d)<< setfill('.') << "" << endl;
        d++;             
        }
    // conditional for when x is an odd number
    } else if(num !=0) {
        cout << "Odd"<<endl;
        
        for(int j=x; j>=1;j--){
            int i;
            for(i=1;i<=x;i++){
                
            }
        cout << setw(x) << setfill(' ') << j << setfill('!') <<endl;
        }
    } else {
        cout <<"Error in else";
    }         
    
    //Exit
    return 0;
}