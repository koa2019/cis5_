/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 10:16 PM
 * Purpose:  Savitch 9th ed - ch3 - prac prb 4 - compatible signs
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   // string
using namespace std;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    string s1,       // sign 1
           s2,       // sign 2 
           element;  // element - Earth, Water, Fire

    //Map inputs -> outputs
    cout << "Horoscope Program which examines compatible signs.\n"
         << "Input 2 signs.\n";
    cin >> s1 >> s2;
    
    //Display the outputs
    // Signs that share the same element are compatible 
    if( (s1=="Virgo" || s1=="Taurus" || s1=="Capricorn") && (s2=="Virgo" || s2=="Taurus" || s2=="Capricorn" )){
        
        element = "Earth";
        
        cout << s1 << " and " << s2 << " are compatible " << element << " signs.";
        
    } else if ( (s1=="Gemini" || s1=="Libra" || s1=="Aquarius") && (s2=="Gemini" || s2=="Libra" || s2=="Aquarius" )){
        
        element = "Fire";
        
        cout << s1 << " and " << s2 << " are compatible " << element << " signs.";
        
    } else if ( (s1=="Cancer" || s1=="Scorpio" || s1=="Pisces") && (s2=="Cancer" || s2=="Scorpio" || s2=="Pisces" )){
        
        element = "Water";
        
        cout << s1 << " and " << s2 << " are compatible " << element << " signs.";
        
    } else {  cout << s1 << " and " << s2 << " are not compatible signs."; }


    //Exit stage right or left!
    return 0;
}