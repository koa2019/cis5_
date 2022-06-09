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

void reverse(char [], int);// mine delete laterrrrr
void print(const char [],int );

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80, SIZE2=5;     //More than enough
    char  digits[SIZE]={};    //Character digits or not
    unsigned short unShort=0;//Unsigned short
    short snShort=0;         //Signed short
    //char arr2[SIZE2]={'0','0','0','0','0'};

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
    unsigned short max=65535;
    int numDigt=5;
    int size=strlen(arr);

    // makes sure input is 5 digits long
    if(size>numDigt) return false;
  
    if( (size==5 && arr[0]>'6') || (size==5 && arr[0]>54)) return false;
    
    bool isValid=true;
    
    for(int i=0;i<size;i++){
        
        //cout << "arr["<<i<<"] = "<< arr[i] << endl;
        
        // returns zero if character is not a letter.
        if(isalpha(arr[i])!=0) return false;
        
        // returns zero if character is NOT a number between 0-9
        if(isdigit(arr[i])==0) return false;
    }
    
    //convert char[] to string then to unsigned unShort
    string str = arr;
    int n=stoi(str);
    if(!(n>=0 && n<=max)) return false;
    else {
        unShort=n;
        return true;
    }
}

bool reverse(unsigned short unShort,signed short &snShort){
    
    // signed short 32767
    signed short max=32767;
    int numDigt=5;
    //int size=strlen(arr2);
    
  //  cout<< "\nunShort=" <<unShort << "\n";
   // cout<<"snShort="<<snShort<<endl;
  int leng=0;
  
  leng = unShort/10000>0 ? 5 :
         unShort/1000>0  ? 4 :
         unShort/100>0   ? 3 :
         unShort/10>0    ? 2 : 
         unShort/1>0 ? 1 : 0;
//cout<<"leng="<<leng<<endl;
    int ones=(unShort%10);
    int tens=(unShort%100)/10;
    int tenK=(unShort/10000);
   //cout <<"10k place "<<tenK<<endl;
    
    int rem,reverse=0;
     while(unShort!=0)  {    
     rem=unShort%10;      
     reverse=reverse*10+rem;    
     unShort/=10;    
    }    
     int tenK2=(reverse/10000);
    //cout <<"10k2 place "<<tenK2<<endl;

    int revL=(reverse/100);
    //cout << "reverse="<<reverse<<" revL "<< revL<<endl;
    
   if(revL==3)return false;
    
   if(leng==5 && reverse>32767){
            //cout<<"jjj\n";
            return false;
        }
    if(leng==5 && reverse<=32767) {
             snShort=reverse;
       //    cout<< "hit "<<reverse<<endl;
            return true;
        }
    if(leng==5 && tenK2>=1 && tenK2<=3) {
            snShort=reverse;
            //cout<< "2hit "<<reverse<<endl;
            return true;
        }
        
    if((leng==5) && (ones==0 || tens==0)) {
            snShort=reverse;
            return true;
    }
    
   
    
    //if((reverse/10000)>0) leng=5;
    if((reverse/1000)>0) reverse*=10;
    else if((reverse/100)>0) reverse*=100;
    else if((reverse/10)>0) reverse*=1000;
    else reverse*=10000;
    
    //cout<<"# digits="<<leng<<endl;
    //cout<< "reverse "<<reverse<<endl;
      if(reverse>=-max && reverse>max) {
       // cout<< "2reverse too big "<<reverse<<endl;
        return false;
    } else{
    snShort=reverse;
    return true;
    }
   // cout <<"3 arr2[ ] = ";
   //print(arr2,numDigt);
/*    
    int digNeed=numDigt-size;
    int last=size-1;
    //cout <<"digNeed = "<< digNeed << endl;    
   
    // makes sure snShort 1st index isn't greater than 3
    //cout << "arr2[0]= "<< arr2[0]<<endl;
     // checks 1st index is not less than -4 or over 3
    
    // need for when input 12345 == no conversions
    if(arr2[0]>'3') {
        cout << arr2[0]<<">'3' = " <<endl;
        return false;
    }
 
  
    if((arr2[0]<-3) || (arr2[0]>'3') ){
        //cout << "failing [0] is less than 6\n";
        cout << arr2[0]<<"<-3 = " <<endl;
        return false;
    }
   */  
 /*   
    // causes tc5 to pass but fails tc0,6,7
    if(arr2[0]>3) { 
       //  cout <<arr2[0]<<">3 = " <<endl;
        return false;
    }

*/
    /*
     if(arr2[0]>'3') {
        //cout << "failing [0] is less than 6\n";
        return false;
    }
    
     */
/*
    //convert string to unsigned unShort
    short num=0;
    int value=0;
   
    //cout << "inRange() starting snShort value = " << snShort<<endl;

    // loop through entire array
    for(int i=0;i<numDigt;i++){
    //for(int i=0;i<size;i++){
    
      //  cout << "\nnum = " << arr2[i]<<"-48 = ";
        num=arr2[i]-48;
      // cout << arr2[i]<<endl;
        
     //  cout << snShort<<" = " << snShort <<"*10 = ";
        snShort *=10;
      //  cout << snShort<<endl;
        
     //   cout << snShort<<" = " << snShort <<"+"<<num<< " = ";
        snShort+=num;
     //   cout << snShort<< endl;
    }
    //cout << "2snShort = " << snShort << endl;
   */ 
    // checks if snShort is in range of an unsigned short
    if(snShort>=-max && snShort<=max) return true;
    else return false;

    
}

short subtrct(signed short snShort,int num){
    return snShort-num;
}

void print(const char arr[],int sizeIn){
    //cout << "char [] = ";
  for(int i=0;i<sizeIn;i++){
        cout << arr[i];
    }
    cout << endl;
}
    
  