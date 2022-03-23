/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 17, 2022 6:00 PM
 * Purpose:  Gaddis 9th ed. ch4 prb 8 - sort names
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   // string
using namespace std;

// function prototypes
void invalidMsg();
void sort(string, string, string);


//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    string temp1, temp2;    // temporary data types 
    string n1, n2, n3;      // name1, name2, name3
    
    //Program instructions for user
    cout << "Sorting Names\nInput 3 names\n";
    cin >> n1;
    cin >> n2;
    cin >> n3;
    
    //Map inputs -> outputs
    // conditional compares strings and rearranges them in alphabetically order
   if(n1 < n2 && n3 < n1 && n3 < n2){
       
       // sorts variables alphabetically
        temp1 = n1;
        temp2 = n2;
        n1 = n3;
        n2=temp1;
        n3 = temp2;
        sort(n1,n2,n3);
        
    } else if (n2 < n1 && n3 < n1 && n2 < n3){
        
        // sorts variables alphabetically
        temp1 = n1;
        temp2 = n3;
        n1 = n2;
        n2 = temp2;
        n3 = temp1;
        
        sort(n1,n2,n3);
        
    } else if (n3<n1 && n3 < n2 && n2 < n1){
        
        // sorts variables alphabetically
        temp1 = n3;
        n3 = n1;
        n1 = temp1;
           
        sort(n1,n2,n3);
      
      // condition checks for duplicate inputs
    } else if( n1 == n2 || n2 == n3 || n1 == n3){
        
        invalidMsg();
        
    } else if( n2 < n1 && n1 < n3){
        
        cout << "\n\nAlphabetically Order \n";
        cout << n2 << endl << n1 << endl << n3;
                
        
    } else if ( n1<n2 && n2<n3){
        
        cout << "\n\nAlphabetically Order \n";
        cout << n1 << endl << n2 << endl << n3;
        
    } else { cout << "Invalid Input.\n";}

    //Exit stage right or left!
    return 0;
}
// function definitions

// function displays duplicate input error message to user
void invalidMsg(){
      cout << "Please do not enter duplicate names.\n";
}

// function takes 3 strings in and displays them
void sort(string x, string y, string z){
     //Display the outputs
    cout << "\n\nAlphabetically Order \n";
    cout << x << endl
         << y << endl
         << z;
}