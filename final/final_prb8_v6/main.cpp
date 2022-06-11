/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
   v1 passes tc 0
 * v2 passes tc 1
 * v3 gets rid of strings and compares as char [][]
 * v4 works & still passes tc 0,1
 * v5 still testing. fails everything,but got
 *   logic of what code needs to do, but it needs the ascii[] to reference
 *     changed swap from reference variables to char[] with strcpy() instead
 * v6: creates ascii and creates new augmented asciii array. switches back
 *      and forth from char[] to string. reads data in from a file to
 *      mimic code-e
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
#include <fstream>
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(fstream &,char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);
void print(const char [][COLMAX],int,int);
void prntAsci(char []); //mine
void swap(char [],char []);
//int strcmp(char a[],char b[],char replace[],char with[]){
int compare(char [][COLMAX],int,int,char [],char [],const char [],const char []);//Replace sort order
void getAscii(char [],char [],const char [],const char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare all Variables Here
    fstream inFile;
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX]={};      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX]={},with[COLMAX]={},//New sort order
         asci[COLMAX]={}, augA[COLMAX]={};
    
    inFile.open("chars.txt");
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    //cin>>replace;    
    // cout<<endl<<replace<<endl<<endl;
    cout<<"With the following characters"<<endl;
    //cin>>with;   
    //   cout<<endl<<with<<endl<<endl;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    //cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    //cin>>colIn;
    
    inFile>>replace;
    inFile>>with;
    inFile>>rowIn;
    inFile>>colIn;
    //cout<<replace<<endl<<with<<endl<<rowIn<<endl<<colIn<<endl;
   
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(inFile,array,rowDet);
    
    colIn=colDet>colIn ? colDet : colIn;
    
    getAscii(asci,augA,replace,with);
    
    print(array,rowIn,colIn);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){        
       
        sort(array,rowIn,colIn,replace,with);       
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    else cout<<"Different sizes.\n";
    
    inFile.close();
    
    //Exit
    return 0;
}

//
int compare(char array[][COLMAX],int rowIn,int colIn, char asci[],char augA[],const char replace[],const char with[]){
    

}

//
void sort(char array[][COLMAX],int rowSize,int colSize,const char replace[],const char with[]){
    
    int maxEle;
    int last=rowSize-1;
    char ch[1]={'$'}, w[1]={'#'},temp[1]={};
   
    //how you reference one character in a single char array
   //cout<< "ch "<<ch[0]<<endl;
   
    
    for(int row=0;row<rowSize;row++){ // starts at [0,lastIndx]
            for(int col=0;col<colSize;col++){
            
                // reassign character value to 1st element in array[][]
                ch[0]=array[row][col];
                
                //how you reference one character in a single char array
                cout<< "ch= "<<ch[0]<<endl;
                
                if(strcmp(array[row],array[row+1])<0) // if its larger, then swap
                swap(array[row],array[row+1]);
        }
    }
    
    
}

// 
void getAscii(char asci[],char augA[],const char replace[],const char with[]){    
    
    char temp[COLMAX]={};
    int zero=48,z=122,range,rplIndx=0,wthIndx=0;
    string aStr, newA;
    
    range=(z-zero)+1;// augmented Ascii range= number zero to lowercase 'z'
    
    // initialize char [] with ascii values from '0'==48 to 'z'==122
    for(int i=0,cnt=48;i<range;i++,cnt++){
        asci[i]=cnt;
        //cout<<asci[i];
    }
    
    //initialize aug array with asci values
    strcpy(augA,asci);    
    //cout<<endl<<"OG ";
    //prntAsci(augA,range);
    
    // char[] to strings
    aStr=asci;
    newA=augA;
    
    //loop [48,122]
    for(int indx=0;indx<strlen(with);indx++){
        
        // reassign string value each time, so rplInx references the latest version of augA[]
        newA=augA;
        rplIndx=newA.find(replace[indx]);   // return index of search value
        wthIndx=newA.find(with[indx]);        
        cout<<"rplIndx  "<<rplIndx<<endl;
        cout<<"wthIndx  "<<wthIndx<<endl;           
        swap(augA[rplIndx],augA[wthIndx]);  // swap array indices within the same array
        //prntAsci(augA);   //print char[]     
    }      
    //cout<<endl<<"New ";
    prntAsci(augA);   //print char[]    
}

// swap
void swap(char a[],char b[]){    
    char temp[]={};    
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

//Print the sorted 2-D array
void print(const char arr[][COLMAX],int row,int col){   
    for(int r=0;r<row;r++){
        cout<<arr[r]<<endl;
    }
}

// print ascii runs from values [48,122]
void prntAsci(char arr[]){
    
    int size=strlen(arr); 
    //cout<<"size"<<size<<endl;
    
    for(int r=0;r<size;r++){
        cout<<arr[r];
    }
    cout<<endl;
}

//Outputs row and columns detected from input
int read(fstream &inFile,char arr[][COLMAX],int &row){
    
   //cout<<"rowDet "<<row<<endl;
   
   int colDet=0, colMax=0,rCount=0;
   
   while( inFile>>arr[rCount]){
   //while( cin>>arr[rCount]){
      
       //cout << arr[rCount]<<endl;
       int size=strlen(arr[rCount]);
       //cout << arr[rCount]<<" strlen["<<rCount<<"] "<<size<<endl;
       
       colMax = size>colMax ? size : colMax;
       rCount++;
   }
   
   //cout <<arr[0]<< " "<<arr[1]<< " " << arr[2]<<endl;
   //cout<<"colMax "<<colMax<<endl;
   colDet=colMax;
   return colDet;
}