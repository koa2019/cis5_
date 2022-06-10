/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June 6, 2022 @12:48 PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 
        321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      
        12300 = 00321 = 321 after reversal and no subtraction
 *   
 * passes tc 1,2,3, 6,7
 * v4 used input & expected output
      in: 12345   out:no conversion2
      in:43210  out: 235
      
     v3 bug:  if(arr2[0]>3 return false will pass tc5 but fail tc1,6,7
      tc 4, 7 are the only ones failings
      v6 is using v5 to test off off
      v6 passes tc4!!! still failing tc 7.
 * 
 *   // PASSES TC 7 BUT fails 5 & 6 
    if(leng==2){
        // PASSES TC 7 BUT fails 5 & 6
        if(reverse<=max){        
            snShort=reverse;
            return true;
        }
    }
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <string> //to_string()
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

    
    for(int i=0;i<size;i++){
        
        // returns zero if character is NOT a number between 0-9
        if(isdigit(arr[i])==0) return false;
        //cout << "arr["<<i<<"] = "<< arr[i] << endl;
    }
    
    //convert char[] to string then to unsigned unShort
    string str = arr;
    int n=stoi(str); // converts string to int
   
    //checks if its in the range of unsigned short [0,65535]
    if(n<0 || n>max) return false;
    else{
        unShort=n;
        return true;
    }
}

bool reverse(unsigned short unShort,signed short &snShort){
    
    // signed short [-32767,32767]
    int max=32767, min=-32767, numDigt=5,
        n10000s,n1000s,n100s,n10s,n1s;
    //int size=strlen(arr2);
    
    //  cout<< "\n unShort=" <<unShort << "\n";
    // cout<<"snShort="<<snShort<<endl;
    int leng=0;
    // get length
    leng = unShort/10000>0 ? 5 : 
           unShort/1000>0  ? 4 :
           unShort/100>0   ? 3 :
           unShort/10>0    ? 2 : 
           unShort/1>0 ? 1 : 0;
    //cout<<"leng="<<leng<<endl;
    
    n10000s=unShort/10000; // strips 10000
    n1000s=unShort/1000;    //Strip 1000's
    n100s=unShort%1000/100; //Stripped the 100's place
    n10s=unShort%100/10;    //Stripped the 10's place
    n1s=unShort%10;         //Stripped the 1's place
   
   
    
    // reverse order of unShort
    int rem, reverse=0;
    
    while(unShort!=0)  {    
        rem=unShort%10;      
        reverse=reverse*10+rem;    
        unShort/=10;   
    }    
    //cout<<"reverse "<<reverse<<endl;
    
    // if unshort was 5 digits long and checks if its in range for a signed short
    if(leng==numDigt){
        if(reverse>max || reverse<min) return false;
        else {
            snShort=reverse;
            return true;
        }
    }  
     
    // if orginal number was 5 digits & zero was last digit, then stop it from adding zeros    
    if(leng==numDigt && reverse<=max) {
        snShort=reverse;
        return true;
    }

    if((leng==5) &&  (n1s==0 && n10s==0)) {
            snShort=reverse;
        return true;
    }
/*
    if(leng==2){
        // PASSES TC 7 BUT fails 5 & 6
        if(reverse<=max){ 
            cout<<"hit\n";
            snShort=reverse;
            return true;
        }
    }
*/
    n10000s=reverse/10000; // strips 10000
    n1000s=reverse/1000;    //Strip 1000's
    n100s=reverse%1000/100; //Stripped the 100's place
    n10s=reverse%100/10;    //Stripped the 10's place
    n1s=reverse%10;         //Stripped the 1's place
    
    //cout<< n10000s<<" "<<n1000s<<" "<<n100s<<" "<<n10s<<" "<<n1s<<endl;
  
    //if((reverse/10000)>0) leng=5;
    if((reverse/1000)>0) reverse*=10;
    else if((reverse/100)>0) reverse*=100;
    else if((reverse/10)>0) reverse*=1000;
    else reverse*=10000;
    
   
    
    int diff=max-reverse;
    //cout<< "reverse with zeros "<<reverse<<endl;
    
/*  
    if(diff<0) {// breaks tc 5. 
        cout<<"hit neg diff\n";
        snShort=reverse;
        return true; 
    } 
*/
   
    if(reverse>=(-1*max) && reverse<=max){
         snShort=reverse;
         return true;
    }
    else if(reverse<(-1*max) || reverse>max) {
        snShort=reverse;
        return false;
    } else {
        snShort=reverse;
        return true;
    }
    
}

 //Now subtract if the result is not negative else don't subtract
short subtrct(signed short snShort,int num){
    
    short result=snShort-num;
    
    //if result is positive, then return subtraction 
    if(!(result<=0)) return result;
    else return snShort;
}

void print(const char arr[],int sizeIn){
    //cout << "char [] = ";
  for(int i=0;i<sizeIn;i++){
        cout << arr[i];
    }
    cout << endl;
}
    
  