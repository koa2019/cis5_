/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
   v1 passes tc 0
 * v2 passes tc 1
 * v3 gets rid of strings and compares as char [][]
 * v4 got rid of strings passes 0 1
 * v5 still testing. fails everything
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
void swap1(char [],char []);//mine

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX]={{'M','a','r','k'},{'M','a','r','c'},{'M','a','r','y'}} ;      //Bigger than necessary 
    int colIn=4,colDet=4,rowIn=3,rowDet=3;//Row, Col input and detected
    char replace[COLMAX]={'c','k','y'},with[COLMAX]={'z','y','x'};//New sort order
         //a[COLMAX]={}, b[COLMAX]={};
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
    
    //cout<<replace<<endl<<with<<endl<<rowIn<<endl<<colIn<<endl;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
   // colDet=read(array,rowDet);
    
    colIn=colDet>colIn ? colDet : colIn;
    
    //print(array,rowIn,colIn);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        
       
        sort(array,rowIn,colIn,replace,with);
       
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    else cout<<"Different sizes.\n";
    
    //Exit
    return 0;
}

void sort(char array[][COLMAX],int rowSize,int colSize,const char replace[],const char with[]){
    
    //cout<<endl;
    int maxEle;
    int last=rowSize-1;
    char ch[1]={'$'}, w[1]={'#'},temp[1]={};
   
    //how you reference one character in a single char array
   //cout<< "ch "<<ch[0]<<endl;
    
   
    //last is size of row minus 1, so last index in array.
    // loops up to the 2nd index which is [1]. range is [(rowSize-1),1]    
    //for(maxEle=last; maxEle>0;maxEle--){
        
        for(int row=0;row<rowSize;row++){ // starts at [0,lastIndx]
            for(int col=0;col<colSize;col++){
                
                // reassign character value to 1st element in array[][]
                ch[0]=array[row][col];
                
                //how you reference one character in a single char array
                //cout<< "ch "<<ch[0]<<endl;
                
                // check each character in array against the replace[]
                if(ch[0]==replace[0]){
                //if(strcmp(array[row],array[row+1])<0) // if its larger, then swap
                    
                    cout<< "ch[] "<<ch[0]<<" == rpl[] "<<replace[0]<<endl;
                    w[0]=with[0];
                    cout<<"w[0] "<<w[0]<<endl;                    
                    
                    //swap1(ch[0],w[0]);
                    //swap(array[row],array[row+1]);   
                    temp[0]=ch[0];
                    ch[0]=w[0];
                    w[0]=temp[0]; 
                    cout<<"new ch[0] "<<ch[0]<<endl;
                
                // check each character in array against the replace[]
                } else if(ch[0]==replace[1]){
                //if(strcmp(array[row],array[row+1])<0) // if its larger, then swap
               
                    cout<< "ch[] "<<ch[0]<<" == rpl[] "<<replace[1]<<endl;
                    w[0]=with[1];
                    cout<<"w[0] "<<w[1]<<endl;
                    
                    //swap1(ch[0],w[0]);
                    //swap(array[row],array[row+1]); 
                    temp[0]=ch[0];
                    ch[0]=w[0];
                    w[0]=temp[0]; 
                    cout<<"new ch[0] "<<ch[0]<<endl;
                    
                }  else if(ch[0]==replace[2]){
                //if(strcmp(array[row],array[row+1])<0) // if its larger, then swap
               
                    cout<< "ch[] "<<ch[0]<<" == rpl[] "<<replace[2]<<endl;
                    w[0]=with[2];
                    cout<<"w[0] "<<w[0]<<endl;
                    
                    //swap1(ch[0],w[0]);
                    //swap(array[row],array[row+1]);   
                    temp[0]=ch[0];
                    ch[0]=w[0];
                    w[0]=temp[0]; 
                    cout<<"new ch[0] "<<ch[0]<<endl<<endl;
                    
                } else cout<<"";
            }
        }
    //}
    
}

// swap
void swap1(char a[],char b[]){    
    char temp[1]={};    
    temp[0]=a[0];
    a[0]=b[0];
    b[0]=temp[0]; 
}

int strcmp(char a[],char b[],char replace[],char with[]){
    
    cout<<"hit strcmp";
    
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