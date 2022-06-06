/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June 2, 2022 @10:16 PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 *   
 * passes tc 1,2,3
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
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
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort=0;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    //cout << "unShort " << unShort << endl;
     
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    //cout << "snShort " << snShort << endl;
    
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
    int numDigt=5;
    int size=strlen(arr);
    //cout << "size " << size << endl;
    char arr2[numDigt]={'0','0','0','0','0'};
    
    if(!(size>=1 && size<=numDigt)){
        return false;
    }else {
        //cout << "SIZE = "<< size << endl;
        if(arr[0]>'6')
        return false;
    }
    
    for(int i=0;i<size;i++){
        if(arr[i]>57 || arr[i]<48) return false;
    }
    
    //print(arr2,numDigt);
     for(int i=size-1;i<numDigt;i++){
         int indx=0;
        arr2[i]=arr[indx];
        //cout <<arr2[i]<<endl;
        indx++;
     }
     //print(arr2,numDigt);
     
     //convert string to unsigned unShort
     int num,value;
     num=value=0;
     //cout << "inRange unshort " << unShort<<endl;
     for(int i=0;i<numDigt;i++){
         num=arr2[i]-48;
         //cout << "unshort*=10 = " << unShort<< endl;
         unShort *=10;
         //cout << "unShort+= "<< num  << endl;
         unShort+=num;
         //cout << "unShort "<< unShort<< endl;
     }
    if(unShort>=0 && unShort<=65535) return true;
    else return false;
}

bool  reverse(unsigned short unShort,signed short &snShort){
    // signed shorrt 32767
    snShort=unShort*100;
    if(snShort<=32767){
        
        return true;
    }else return false;
}
void reverse(char a[], int sizeIn){
    
    bool isMin;
    int last=sizeIn-1;
    do{
        isMin=false;
        for(int i=0;i<last;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                isMin=true;
            }
        } 
        last--;
    }while(isMin);
}

short subtrct(signed short snShort,int num){
    return snShort-num;
}

/*int read(char arr[]){ 
   
    char ch;
    int i=0;
    
    while(cin >> ch) {
            arr[i]=ch;
            i++;
    }
    
    return strlen(arr);
}

int read1(char arr[]){ 
   
    string str;
    cin >> str;
    
    for(int i=0;i<str.length();i++){
        arr[i]=str[i];
    }
    return str.length();
}
  */

void print(const char arr[],int sizeIn){
    cout << "char [] = ";
  for(int i=0;i<sizeIn;i++){
        cout << arr[i];
    }
    cout << endl;
}
    
  