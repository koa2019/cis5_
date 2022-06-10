/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 *  v1 passes tc 0
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
void sort(char [][COLMAX],int,int,const char[],const char[],string &,string &,string &);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int,string &,string &,string &);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    string s0=" ",s1=" ",s2=" ";
    
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
    
   // print(array,rowIn,colIn);
    //cout<<endl;
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with,s0,s1,s2);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn,s0,s1,s2);
    }
    else cout<<"Different sizes.\n";
    
    //Exit
    return 0;
}

//Outputs row and columns detected from input
int read(char arr[][COLMAX],int &row){
    
   //cout<<"rowDet "<<row<<endl;
   
   int colDet=0, colMax=0,rCount=0;
   
   
   while(rCount<row){
      
       cin >> arr[rCount];
       
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

//Sort by row using strcmp();
void sort(char arr[][COLMAX],int row,int col,const char replace[],const char with[],string &s0,string &s1,string &s2){
    
    int last=col-1;
     //cout <<arr[0]<< " "<<arr[1]<< " " << arr[2]<<endl;
     //cout <<arr[0][col-1]<< " "<<arr[1][last]<< " " << arr[2][last]<<endl;
     
    char ary1[COLMAX]={};
    
    //string s0,s1,s2;
     s0=arr[0]; 
        s1=arr[1]; 
        s2=arr[2];
        
/*    
     cout<<"s0 "<<s0<<endl;
    cout<<"s1 "<<s1<<endl;
    cout<<"s2 "<<s2<<endl<<"sorted "<<endl;
*/    
    for(int r=0;r<row;r++){
        
        //first=arr[0];
        //cout<<"arr "<<arr[r]<<endl;
        
       
        //     
       if(s0<s1 && s1<s2) {
           //cout<<"swaping\n";
           swap(s0,s2);
       } 
       if(s0<s2 && s2<s1) {
           //cout<<"swaping\n";
           swap(s0,s2);
       }
   /*    
        if(s1<s0 && s0<s2) {
           //cout<<"swaping\n";
           swap(s1,s0);
       } if(s1<s2 && s2<s0) {
           //cout<<"swaping\n";
           swap(s1,s2);
       }   
       
       if(s2<s1 && s1<s0) {
           //cout<<"swaping\n";
           swap(s2,s1);
       }
         if(s2<s0 && s0<s1) {
           //cout<<"swaping\n";
           swap(s2,s0);
       }
         
   */       
       
       
       
       
       
      
    }
/*    
    cout<<"s0 "<<s0<<endl;
    cout<<"s1 "<<s1<<endl;
    cout<<"s2 "<<s2<<endl;
*/
    
}

//Print the sorted 2-D array
void print(const char arr[][COLMAX],int row,int col,string &s0,string &s1,string &s2){
    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    
/*    
    for(int r=0;r<row;r++){
        //for(int c=0;c>col;c++){
            cout<<arr[r]<<endl;
        //}
    }
*/
}