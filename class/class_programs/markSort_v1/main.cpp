/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 16, 2022,  9:45 AM
 * Purpose: mark lehr's  sort
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
void swap2(int &, int &);
void smallPos(int [], int, int); // finds smallest position with 2 numbers
void markSort(int [], int); 

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
    //swap1(array[0], array[99]);  // swap 1st index with last index
    //swap2(array[1], array[98]);  // swap 2nd index and 2nd last index
    
    //smallPos(array,SIZE,0); // finds smallest and moves it to front
    //smallPos(array,SIZE,1); // finds 2nd smallest and moves it to front
    //smallPos(array,SIZE,2); // finds 3rd smallest and moves it to front
    //smallPos(array,SIZE,3); // finds 4th smallest and moves it to front
    markSort(array,SIZE);
    
    // Display inputs to outputs
    printAry(array,SIZE,perLine);
   
    // exit code
    return 0;
}

// *********** FUNCTION DEFINITIONS ************
// sort small to big
void markSort(int a[], int n){
    
    for(int i=0;i<n-1;i++){ // don't need to sort last position cause it does it in smallPost()
        smallPos(a,n,i);    // swaps every time
    }
}


// find smallest
void smallPos(int a[], int n, int pos){
    for(int i=pos+1; i<n; i++){
        if(a[pos] > a[i]){
            swap(a[pos],a[i]);
        }
    }
}

// gives same results as swap1()
void swap2(int &a , int &b){ // look at truth tabes      
    a=a^b;
    b=a^b;
    a=a^b;
    
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