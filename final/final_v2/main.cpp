/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June 6, 2022 @9:16 AM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 *   
 * passes tc 1,2,3, 6,7
 * v2 used input 321-> 12300->11301
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
bool  inRange(const char [],unsigned short &,char []);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &,char []);//Output true,short or false
short subtrct(signed short,int);

void reverse(char [], int);// mine delete laterrrrr
void print(const char [],int );

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80, SIZE2=5;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort=0;//Unsigned short
    short snShort=0;         //Signed short
    char arr2[SIZE2]={'0','0','0','0','0'};

    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort,arr2)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
   // cout << "\npassed inRange unShort = " << unShort << endl;
     
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort,arr2)){
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
bool  inRange(const char arr[], unsigned short &unShort,char arr2[]){
    // unShort range [0,65535]
    int numDigt=5;
    int size=strlen(arr);
    //cout << "size " << size << endl;
    //cout <<"start arr2 =" <<arr2[0] <<" last = " <<arr2[4]<<endl;

    // makes sure input is 5 digits long
    if(!(size>=1 && size<=numDigt)){
        return false;
    }else {
        //cout << "SIZE = "<< size << endl;
        if(arr[0]>'6')
        return false;
    }
    
    for(int i=0;i<size;i++){
        
        //cout << "arr["<<i<<"] = "<< arr[i] << endl;
        
        // makes sure each index is a number between 0-9
        if(arr[i]>57 || arr[i]<48) {
            //cout << "failing between 0-9 \n";
            return false;
        }
        
        // checks 1st index is not less than 0 or over 6
        if(!(arr[0]<0 ||  arr[0]>6) ){
            //cout << "failing [0] is less than 6\n";
            return false;
        }
    }
    //out <<"1 unsigned short \n";
    //print(arr2,numDigt);
    
    int digNeed=numDigt-size;
    int last=size-1;
   // cout <<"digNeed = "<< digNeed << endl;    
   
    // create new bigger array & save input original arr into it reverse order
    for(int i=0;i<numDigt;i++){        
           
        arr2[i]=arr[last];  
      
        // if necessaray add extra zeros to get ready for unsigned short
        if(digNeed>0){
            //cout <<"hit digneed\n";
            
            for(int j=size;j<numDigt;j++){
                arr2[j]='0';
                //cout <<arr2[j];
            }            
        }
        last--; 
   }

   // cout <<"2 arr2[ ] = ";
   // print(arr2,numDigt);
         
    //convert string to unsigned unShort
    unsigned short num=0;
    int value=0;
   
    //cout << "inRange() starting unShort value = " << unShort<<endl;

    // loop through entire array
    //for(int i=0;i<numDigt;i++){
        for(int i=0;i<size;i++){
    
        //cout << "num = " << arr[i]<<"-48 = ";
        num=arr[i]-48;
       // cout << arr[i]<<endl;
        
       // cout << unShort<<" = " << unShort <<"*10 = ";
        unShort *=10;
        //cout << unShort<<endl;
        
        //cout << unShort<<" = " << unShort <<"+"<<num<< " = ";
        unShort+=num;
        //cout << unShort<< endl;
    }
    //cout << "1unShort = " << unShort << endl;
    
    // checks if unshort is in range of an unsigned short
    if(unShort>=0 && unShort<=65535) return true;
    else return false;
}

bool reverse(unsigned short unShort,signed short &snShort,char arr2[]){
    // signed short 32767
    int numDigt=5;
    int size=strlen(arr2);
    
   // cout <<"3 arr2[ ] = ";
   // print(arr2,numDigt);
    
    int digNeed=numDigt-size;
    int last=size-1;
    // cout <<"digNeed = "<< digNeed << endl;    
   
    //convert string to unsigned unShort
    short num=0;
    int value=0;
   
    //cout << "inRange() starting unShort value = " << unShort<<endl;

    // loop through entire array
    for(int i=0;i<numDigt;i++){
    //for(int i=0;i<size;i++){
    
        //cout << "num = " << arr2[i]<<"-48 = ";
        num=arr2[i]-48;
//       cout << arr2[i]<<endl;
        
  //     cout << snShort<<" = " << snShort <<"*10 = ";
        snShort *=10;
    //    cout << snShort<<endl;
        
      //  cout << snShort<<" = " << snShort <<"+"<<num<< " = ";
        snShort+=num;
        //cout << snShort<< endl;
    }
    //cout << "1snShort = " << snShort << endl;
    
    // checks if snShort is in range of an unsigned short
    if(snShort>=-32767 && snShort<=32767) return true;
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
    
  