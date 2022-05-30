/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 16, 2022,  10:25 AM
 * Purpose: bubble  sort
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
void bubSort(int [], int); 

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
    bubSort(array,SIZE);
    
    // Display inputs to outputs
    printAry(array,SIZE,perLine);
   
    // exit code
    return 0;
}

// *********** FUNCTION DEFINITIONS ************

// bubble sort small to big
void bubSort(int a[], int n){
    bool swap;
    
    // don't need to sort last position cause it's done during 1st loop's swap function call
    int redList=n-1;    // largest one's go to the bottom on the 1st run. more efficient
    do{
        swap=false;
        for(int i=0; i<redList;i++){
            if(a[i] > a[i+1]) //compares to the one next to it
                swap1(a[i], a[i+1]);
            swap=true;
        }
        redList--;
    }while(swap);
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