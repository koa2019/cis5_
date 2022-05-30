/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: 07/17/22 12:43 PM
 * Purpose:  Binary Search wtih Bubble
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
void fillAry8(int [],int);
void prntAry8(int [],int,int);
void bublSrt8(int [],int);
bool binSrch8(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry8(array,SIZE);

    //Sorted List
    bublSrt8(array,SIZE);
    
    //Display the outputs
    prntAry8(array,SIZE,10);
    
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    
    if(binSrch8(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found "<<endl;
    
    //Exit stage right or left!
    return 0;
}
// ************* FUNCTION DEFINITIONS ************

// sort array smallest to biggest
void bublSrt8(int arr[], int SIZE){
    
    bool go;
    int lessby1=SIZE-1;  // largest num goes to the end after the first swap, so start loop at 2nd to last position. more efficient
    
    do {
        go=false;   // set flag
        
        for(int i=0; i<lessby1; i++){  // loop through entire array
    
            if(arr[i] > arr[i+1]){        // compare the 2 indices next to each other
                swap(arr[i], arr[i+1]);  // swap their positions
                go=true;                // reassign flag
            }
        }
    } while(go);
}

// check to see if search value is inside arr. if so return its index position and true. 
bool binSrch8(int arr[], int SIZE, int val, int &index){
    
    for(int j=0; j<SIZE; j++){ // loop through entire array 
        
        if(val==arr[j]){     // check if val were looking for equals any of the array index's value
            index=j;        // assign j's index to ref variable 
            return true;    // set flag
        }   
    }
    return false;   // return false if val is not inside array
}

// display array
void prntAry8(int arr[], int SIZE, int cols){
    cout << endl;
    for(int i=0;i<SIZE;i++){
        cout << setw(3) << arr[i] << " ";
        if(i%cols==(cols-1)) cout << endl;
    }
    cout << endl;
}

// fill array
void fillAry8(int arr[], int SIZE){
    
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%(100+1);
    }
}