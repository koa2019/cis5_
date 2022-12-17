/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June 6, 2022 @12:48 PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 
        321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction *      
        12300 = 00321 = 321 after reversal and no subtraction
 *   
 *      passes tc 1,2,3, 6,7
 *      v4 used input & expected output
        in: 12345   out:no conversion2
        in:43210  out: 235
        v3 bug:  if(arr2[0]>3 return false will pass tc5 but fail tc1,6,7
        tc 4, 7 are the only ones failings
        v6 is using v5 to test off off
        v6 passes tc4!!! still failing tc 7
 *      v7 passes tc 7 by changing how subtract() checks the minimum  and if snShort is not negative. 
        brought in library for short and unsigned short max & min
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <string> //to_string()
#include <limits.h> //SHRT_MIN
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);
void print(const char [],int );

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare all Variables Here
    const int SIZE=80, SIZE2=5;     //More than enough
    char  digits[SIZE]={};    //Character digits or not
    unsigned short unShort=0;//Unsigned short
    short snShort=0;         //Signed short
   
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
   //cout << "\npassed inRange unShort = " << unShort << endl;
     
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        // cout<<snShort<<endl;
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    //cout << "\npassed reverse() snShort = " << snShort << endl;
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

//Output true,unsigned or false
bool  inRange(const char arr[], unsigned short &unShort){
    
    // unShort range [0,65535]
    int max=65535;
    int numDigt=5;
    int size=strlen(arr);

    // loop through the char[]
    for(int i=0;i<size;i++){
        
        // returns zero if character is NOT a number between 0-9
        if(isdigit(arr[i])==0) return false;
        //cout << "arr["<<i<<"] = "<< arr[i] << endl;
    }
    
    //convert char[] to string then to unsigned unShort
    string str = arr;
    int n=stoi(str); // converts string to int
   
    //checks if its in the range of unsigned short [0,65535]
    if(n>USHRT_MAX) return false;
    else{
        unShort=n;
        return true;
    }
}

// reverse unshort and change 
bool reverse(unsigned short unShort,signed short &snShort){
    
    // signed short [-32767,32767]
    int max=32767, min=-32767, numDigt=5;
   
    // reverse order of unShort
    int rem, reverse=0,i=0;
    
    while(i<numDigt){ 
        
        reverse=reverse*10+(unShort%10);    
        unShort/=10; 
        i++;
    }   
    //cout<<"reverse "<<reverse<<endl;
   
   // check if reversed unshort is in range for a signed short
    if(reverse>=SHRT_MIN && reverse<=SHRT_MAX){
        snShort=reverse;
        return true;
        
    } else return false;
}

 //Now subtract if the result is not negative else don't subtract
short subtrct(signed short snShort,int min){
    int result=snShort-min;
    if(snShort>min || result>0)return result;
    else snShort;
   
}

void print(const char arr[],int sizeIn){
    //cout << "char [] = ";
  for(int i=0;i<sizeIn;i++){
        cout << arr[i];
    }
    cout << endl;
}
    
  