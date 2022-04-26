/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 10:42 PM
 * Purpose:  Cross one-side or the other 
 * Version 2: solves odd back slash \. Test case 2 & 6
 * expected input 5 b
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
        //cout << "Odd"<<endl;
        
        int c=0;
        for(int a=x; a>=1;a--){
            for(int b=1; b<=x;b++){
                //cout<<b;
            }
          cout <<setw(c)<< setfill('.') << "";
          //cout <<c<<endl;
        cout << setw(a) << left << setfill('.') << a <<endl;
        c++;
        }
        
    } else {
        cout <<"Error in else";
    }         
    
    //Exit
    return 0;
}