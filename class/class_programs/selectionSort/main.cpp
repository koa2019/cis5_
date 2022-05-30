/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 16, 2022  10:39 AM
 * Purpose: select sort
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes
void fillAry(int [], int);
void printAry(int [], int, int);
void swap1(int &, int &);
void selSort(int [], int); 

// Program execution begins here
int main(int argc, char** argv) {
    
    // set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // declare variables
    const int SIZE=100;
    int array[SIZE];
    int perLine;
    
    // initial variables
    fillAry(array,SIZE);
    perLine=10;
    printAry(array,SIZE,perLine);
     
    // map the inputs to the outputs   
    selSort(array,SIZE);
    
    // Display inputs to outputs
    printAry(array,SIZE,perLine);
   
    // exit code
    return 0;
}

// *********** FUNCTION DEFINITIONS ************
// selection sort looks for smallest and then swaps
void selSort(int a[], int n){
    
    int redList=n-1; // don't need to sort last position cause it does during the 1st loop iteration
    
    for(int i=0;i<redList;i++){ 
        int indx=i;
        for(int j=i+1; j<n;j++){    // compare 
            if(a[indx] > a[j]){     // smallest to biggest
                
                indx=j; //remember index
            }
        }
        swap1(a[i], a[indx]);   // swap at the end 
    }
}

// swap for minimum
void swap1(int &a , int &b){    
    int temp=a;
    a=b;
    b=temp;
    
}

// display array
void printAry(int a[], int n, int cols){
    
    cout<< endl;    
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
        if(i%cols==(cols-1)) cout << endl;
    }
}

// fill array
void fillAry(int a[], int n){
    
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10; // [10,99]       
    }
}