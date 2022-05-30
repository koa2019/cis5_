/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: 07/17/22 1218 PM
 * Purpose:  Binary Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry7(int [],int);
void prntAry7(int [],int,int);
void selSrt7(int [],int);
bool binSrch7(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry7(array,SIZE);

    //Sorted List
    selSrt7(array,SIZE);
    
    //Display the outputs
    prntAry7(array,SIZE,10);
    
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    cout << endl;
    
    if(binSrch7(array,SIZE,val,indx))
       cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found "<<endl;
    
    //Exit stage right or left!
    return 0;
}
// ************* FUNCTION DEFINITIONS ************

// sort array smallest to biggest
void selSrt7(int arr[], int SIZE){
    
    int lessby1=SIZE-1;  // largest num goes to the end after the first swap, so start loop at 2nd to last position. more efficient
    
    for(int i=0; i<lessby1; i++){  // loop through entire array    
        for(int j=i+1; j<SIZE; j++){  // loop starting at 2nd index arr[1]
        
            if(arr[i] > arr[j]){  // compare the 2 indices next to each other
                swap(arr[i], arr[j]);  // swap their positions
            }
        }
    }
}

// check to see if search value is inside arr. if so return its index position and true. 
bool binSrch7(int arr[], int SIZE, int val, int &index){
    
    for(int j=0; j<SIZE; j++){ // loop through entire array 
        
        if(val==arr[j]){    // check if val were looking for equals any of the array index's value
            index=j;     // assign j's index to ref variable 
            return true; // set flag
        }   
    }
    return false;   // return false if val is not inside array
}

// display array
void prntAry7(int arr[], int SIZE, int cols){
    for(int i=0;i<SIZE;i++){
        cout << setw(3) << arr[i] << " ";
        if(i%cols==(cols-1)) cout << endl;
    }
    cout << endl;
}

// fill array
void fillAry7(int arr[], int SIZE){
    
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%(100+1);
    }
}