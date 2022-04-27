/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: April 22, 2022 10:42 PM
 * Purpose:  Cross one-side or the other 
 * Version 3
 */

//System Libraries Here
#include <iostream>
#include <iomanip>  // setw()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here
void dsd_evenFwd(int);
void oddF(int);
void evenB(int);
void dsd_oddBk(int);
void oddX(int);
void evenX(int);

void asd_OddFwd(int);
void asd_OddBk(int);
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
    
    if((shape=='x') && (num!=0)){
        
        oddX(x);
        //asd_OddFwd(x);
       //asd_OddBk(x);
        
    }// even number conditional for x
    else if(num==0){
        dsd_evenFwd(x);
        
    // odd number conditional for x
    } else if(num !=0) {
       dsd_oddBk(x);
        
    } else {
        cout <<"Error in else";
    }

    //Exit
    return 0;
}
// *********** FUNCTION DEFITIONS ****************

// WORKING ON THIS ONE!
void oddX(int x3){
    int p,z,h;
     
    // DONT TOUCH
     int d=5;
       int e=0;
        for(int j=1; j<=5;j++){
        //for(int j=1; j<=5;j++){
            for(int i=1;i<=x3;i++){
            //for(int i=1;i<=x3;i++){
            }
        // empty space before j    
         cout <<setw(d) << setfill(' ') << j 
              << setw(e) << setfill('*') << ""  
              << endl;
       d--;
       e++;
        }
        cout<<endl;
        
    // DONT TOUCH
    int c=0;
    for(int a=x3; a>=1;a--){
        for(int b=1; b<=x3;b++){
            //cout<<b;
        }
    cout <<setw(c) << setfill(' ') << "" 
         << setw(a) << left << setfill(' ') << a 
         <<endl;
    c++;
    }
    cout <<endl;
    
    
     // loops for X
     h=0;
     p=4;
     z=1;
    for(int a=x3; a>=1;a--){
         //p=5;
          //p--;
        for(int b=1; b<=x3;b++){
            //cout<<b;
        }
        //--p;
    cout << setw(h) << setfill(' ') << "" << a 
         << setw(p) << z
         << endl;
         //cout<<"p = "<<p<<endl;
         h++;
         p--;
        //--p;
         z++;
/*
    cout <<setw(c)<< setfill(' ') << ""; 
    cout << setw(4) << left << setfill(' ') << a;
    cout << setw(1) << setfill('!') << a <<endl;
*/
    }
    
}


// ascending order, x=even and forward slash
void asd_OddFwd(int x1){
       int d=5;
       int e=0;
        for(int j=1; j<=5;j++){
            for(int i=1;i<=x1;i++){
            }
            
         cout <<setw(d)<< setfill(' ') << j 
         << setw(e) << setfill(' ') << ""  << endl;
       d--;
       e++;
        
        }
}

// ascending order, x=even and back slash
void asd_OddBk(int x1){
    //cout << "Odd Fwd"<<endl;
       int d=0;
        for(int j=1; j<=x1;j++){
            for(int i=1;i<=x1;i++){
            }
        cout << setw(j) << setfill(' ') << j;
        cout <<setw(d)<< setfill(' ') << "" << endl;
        d++;
        }
}

// descending order. x=even and forward slash
void dsd_evenFwd(int x1){
    //cout << "Even"<<endl;
       int d=0;
        for(int j=x1; j>=1;j--){
            for(int i=1;i<=x1;i++){
            }
        cout << setw(j) << setfill(' ') << j;
        cout <<setw(d)<< setfill(' ') << "" << endl;
        d++;
        }
}

// descending order, x=odd and back slash
void dsd_oddBk(int x2){
     //cout << "Odd"<<endl;
    int c=0;
    for(int a=x2; a>=1;a--){
        for(int b=1; b<=x2;b++){
            //cout<<b;
        }
    cout <<setw(c)<< setfill(' ') << ""; 
    cout << setw(a) << left << setfill(' ') << a <<endl;
    c++;
    }
}