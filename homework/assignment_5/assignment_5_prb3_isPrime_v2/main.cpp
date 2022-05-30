/* 
 * Author: Danielle Fernandez
 * Created on: 4/30/22 @4:45 PM
 * Purpose:  isPrime v2
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool isPrime(int); //Determine if the input number is prime.
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
    //for(int num=1; num<=100;num++){


    //Process/Map inputs to outputs
    prime = isPrime(num);

    //Output data
    //cout << num << "is " << prime<<endl;
    if (prime) primeMsg(num);
    else notPrimeMsg(num);
    //}
    //Exit stage right!
    return 0;
}

bool isPrime(int n) {

    //if(n==1 || n==2 || n==3 || n==5 || n==7) return true;

    if (n == 0 || n == 1) return false; // 1 & 0 are not prime
    if (n == 2) return true; // 2 is prime

    unsigned int stopPnt = sqrt(n)+1; // sqrt(29)==5.385
    //cout << "stop = " << stopPnt << endl;
    for (int i = 2; i <= stopPnt; i++) { // start at 2 because it's first prime number
        //float mod = n % i;
        if (n % i == 0) {
            //cout << n << " % " << i << " = \tmod == " << mod << endl;
            return false; // return n is NOT prime. Input: 29%2==1==true
        }
        //cout << n << " % " << i << " = \tmod == " << mod << endl;
    }
    return true;
}

void primeMsg(int n) {
    cout << n << " is prime.\n";
}

void notPrimeMsg(int n) {
    cout << n << " is not prime.\n";
}