/* 
 * Author: Danielle Fernandez
 * Created on: 5/2/22 1:41 PM
 * Purpose:  Collatz Sepuence with output of sequence v1
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int collatz(int); //3n+1 sequence

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    int n;

    //Initialize Variables
    cout << "Collatz Conjecture Test" << endl;
    cout << "Input a sequence start" << endl;
    cin>>n;

    // call the function
    unsigned int nSteps = collatz(n);
    
    //for(int i=1;i<=nSteps;i++){
        //cout << n << ", ";
    //}
    
     //Output data
    cout << "Sequence start of " << n << " cycles to 1 in "
         << nSteps << " steps";

    //Exit stage right!
    return 0;
}
/* function runs collatz sequence until x==1 and
   returns the number of steps it took   */
int collatz(int x) {

    int steps=1;
    
    cout << x << ", ";
    
    do {
       
        if (x % 2 == 0) { // if x is even, then divide by 2
            x /= 2;
            cout << x ;
        } else {            // if x is odd, then multiply by 3 and add 1 
            x = (3 * x) + 1;
            cout << x ;
        }
        steps++;
        (x!=1) ? cout << ", " : cout << endl;
        
    } while (x != 1);
    
    return steps;
}