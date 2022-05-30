/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 5/10/22 12:30 PM
 * Purpose:  Reverse the Array
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int [], int);//Reverse the array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50;
    int length=10;
    int test[SIZE];
    int reverse[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    cout << endl << "Random Array \n";
    print(test,SIZE, length);
    
    //Reverse the Values
    revrse(test,reverse,SIZE);
    
    //Display the outputs
    cout << endl << "Array Reversed \n";
    print(reverse,SIZE,length);

    //Exit stage right or left!
    return 0;
}

//    ******** FUNCTION DEFINITIONS  *********
void init(int test[], int SIZE){
    
    for(int i=0;i<SIZE;i++){
        //cin >> test[i];
        test[i]= rand()%(100+1)+1;
    }
}

// prints array with 10 integers in each row
void print(int array[],int SIZE, int length){
    
    int count=-1;
    
    for(int i=0;i<SIZE;i++){
        cout << array[i] << " ";
        count++;
        
        // adds endl after the 10th int is printed.
        // creates rows with 10 columns
        if((count%length)==(length-1)) cout << endl;
    }
}

// reverses the order of 1 array and saves it as a new array 
void  revrse(int test[],int reverse[], int SIZE){
    
    for(int i=0, j=SIZE-1;j>=0;i++,j--){
        reverse[i]=test[j];
    }
}