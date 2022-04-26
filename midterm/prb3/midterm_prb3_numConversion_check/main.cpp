/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on April 25, 2022,  10:32 AM
 * Purpose: Miterm prb 3 - Convert a number to English check amount
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>
#include <cstring>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void convertNums(int, string &);
void convertTens(int, string &);
void specialTens(int, string &);


//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short num=3456,
            n1000s,
            mod,
            n100s,
            n10s,
            n1s;
    string dollars, 
           thousnd="Thousand ",
           hundred="Hundred ",
           cents = "and no/100's Dollars";

    do {
        //Input or initialize values Here
        cout << "Input an integer [1-3000] convert to an English Check value." << endl;
        cin>>num;
    } while ((num<1) && (num>3000));

   
    //Calculate the 1000's, 100's, 10's and 1's
    n1000s=(num/1000);
    mod=(num%1000);
    n100s=mod/100;
    n10s=mod%100;
    n1s=mod%10;
    
    cout << n1000s << "\t " << n100s << "\t " << n10s << "\t " << n1s  << endl;
    
    //Output the check value
    convertNums(n1000s, dollars);
    dollars +=thousnd;
    convertNums(n100s, dollars);
    dollars +=hundred;
    
    if(n10s>=11 && n10s<=19){
        specialTens(n10s, dollars);
    } else {
        n10s=mod%100/10;
        convertTens(n10s, dollars);
        convertNums(n1s, dollars);
    }    
    
    dollars +=cents;
    cout << dollars << endl;
    
    //Exit
    return 0;
}
// ******* FUNCTION DEFITIONS  ***********

// 
void specialTens(int digit, string &check){        
    switch(digit){
        case 19:{
            check+="Nineteen ";
            break;
        } case 18:{
            check+="Eighteen ";
            break;
        } case 17:{
            check+="Seventeen ";
            break;
        } case 16:{
            check+="Sixteen ";
            break;
        } case 15:{
            check+="Fifteen ";
            break;
        } case 14:{
            check+="Fourteen ";
            break;
        } case 13:{
            check+="Thirteen ";
            break;
        } case 12:{
            check+="Twelve ";
            break;
        } case 11:{
            check+="Eleven ";
            break;
        } default: cout << "Error in tens switch default.\n";
    }
} 

// 
void convertTens(int digit, string &check){        
    switch(digit){
        case 9:{
            check+="Ninety ";
            break;
        } case 8:{
            check+="Eighty ";
            break;
        } case 7:{
            check+="Seventy ";
            break;
        } case 6:{
            check+="Sixty ";
            break;
        } case 5:{
            check+="Fifty ";
            break;
        } case 4:{
            check+="Forty ";
            break;
        } case 3:{
            check+="Thirty ";
            break;
        } case 2:{
            check+="Twenty ";
            break;
        } case 1:{
            check+="Ten ";
            break;
        } default: cout << "Error in tens switch default.\n";
    }
}    

// function for thousands, hundreds place in check
void convertNums(int digit, string &check){        
    switch(digit){
        case 9:{
            check+="Nine ";
            break;
        } case 8:{
            check+="Eight ";
            break;
        } case 7:{
            check+="Seven ";
            break;
        } case 6:{
            check+="Six ";
            break;
        } case 5:{
            check+="Five ";
            break;
        } case 4:{
            check+="Four ";
            break;
        } case 3:{
            check+="Three ";
            break;
        } case 2:{
            check+="Two ";
            break;
        } case 1:{
            check+="One ";
            break;
        } default: cout << "Error in switch default.\n";
    }    
}