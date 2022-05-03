/* 
 * Author: Danielle Fernandez
 * Created on: 4/30/22 @4:45 PM
 * Purpose:  isPrime
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool isPrime(int);//Determine if the input number is prime.
void primeMsg(int);
void notPrimeMsg(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    bool prime;
    int num;
    
    //Initialize Variables
    cout << "Input a number to test if Prime.\n";
    cin >> num;
    
    //Process/Map inputs to outputs
    prime = isPrime(num);
    
    //Output data
    //cout << num << "is " << prime<<endl;
    if(prime) primeMsg(num);
    else notPrimeMsg(num);
    
    //Exit stage right!
    return 0;
}

bool isPrime(int n){
    
    if(n==1 || n==2 || n==3 || n==5 || n==7) return true;
    
    if(n%2==0) return false;
}

void primeMsg(int n){
    cout << n << " is prime.";
}

void notPrimeMsg(int n){
    cout <<  n << " is not prime.";
}