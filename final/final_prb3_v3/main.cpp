/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
   v1 passes tc 0
 * v2 passes tc 1
 * v3 gets rid of strings and compares as char [][]
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);
void print(const char [][COLMAX],int,int);

//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    // cout<<endl<<replace<<endl<<endl;
    cout<<"With the following characters"<<endl;
    cin>>with;
    //   cout<<endl<<with<<endl<<endl;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //cout<<replace<<endl<<with<<endl<<rowIn<<endl<<colIn<<endl;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    colIn=colDet>colIn ? colDet : colIn;
    
    //print(array,rowIn,colIn);
   
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        
        sort(array,rowIn,colIn,replace,with);
        //sort(array,rowIn,colIn,replace,with,s0,s1,s2);
        cout<<"The Sorted Array"<<endl;
        //print(array,rowIn,colIn,s0,s1,s2);
        print(array,rowIn,colIn);
    }
    else cout<<"Different sizes.\n";
    
    //Exit
    return 0;
}

void sort(char array[][COLMAX],int rowIn,int colIn,const char replace[],const char with[]){
    
    int maxEle, row;
   int last=rowIn-1;
   
    // start at the last indx in array to the 2nd indx. starts at[last,1]
    for(maxEle=last; maxEle>0;maxEle--){
        
        for(row=0;row<maxEle;row++){ // starts at [0,last]
            
            if(strcmp(array[row],array[row+1])<0) // if its larger, then swap
                swap(array[row],array[row+1]);
        }
    }
}

//Print the sorted 2-D array
void print(const char arr[][COLMAX],int row,int col){
   
    for(int r=0;r<row;r++){
        cout<<arr[r]<<endl;
    }
}

//Outputs row and columns detected from input
int read(char arr[][COLMAX],int &row){
    
   //cout<<"rowDet "<<row<<endl;
   
   int colDet=0, colMax=0,rCount=0;
   
   
   while( cin>>arr[rCount]){
      
       //cin >> arr[rCount];
       
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