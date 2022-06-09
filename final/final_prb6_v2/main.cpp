/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 6/8/22 10 AM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
   
   V2:
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    //int array[ROW][COLMAX]={{1,2,3},{3,4,5}};  //if skipping cin Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    cout << "Input a table and output the Augment row,col and total sums." <<endl
         << "First input the number of rows and cols. <20 for each" << endl;
  
    cout <<"Now input the table."<< endl;
        
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX],int &row,int &col){

   cin >> row >> col;
   
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
           cin>>array[i][j];
       }
   } 
  // row=2;  // for testing purposes. when u dont want to cin everytime
  // col=3;   
}

// augAry is 1 col and row bigger for the sums
void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]){
    
   // cout<<"\n row"<<row <<"\n c"<<col<<endl;
    int sumCol, sumRow, ttl=0;
    
    // loop through 
     for(int i=0;i<row+1;i++){
         
         sumRow=0;
         
        for(int c=0;c<col+1;c++){
           
            //copy original array to new array
            augAry[i][c]=array[i][c];
           // cout <<  augAry[i][c] <<endl;            
            
            sumRow+=array[i][c];
            //cout <<endl << "sumR["<<i<<"]["<<c<<"] " << sumRow <<endl;
            
            ttl+=augAry[i][c];
            //cout <<endl << "ttl["<<i<<"]["<<c<<"] " << ttl <<endl;
            
            // saves the row's sum to the last index in array
            if(c==col){ augAry[i][c]=sumRow;}
           
            // saves the last row's sum 
            if(i==row && c==col)augAry[i][c]=ttl;
            
        }
        //cout << "\n sumR=" << sumRow <<endl;
     }
     
    //calculate each column's sum       
    ttl=0;
    
    // outer loop is columns instead of rows
    for(int c=0;c<col;c++){
        
        sumCol=0;
        
        for(int i=0;i<row;i++){
           
            sumCol+=array[i][c];
            //cout<< "sumCol= "<<sumCol<<endl;            
           
            // saves each column's sum to the last row of array
            augAry[row][c]=sumCol;
            
            //if(i==2 && c==1)augAry[i][c]=sumCol;
           //  cout <<" r= "<<i <<" c= "<< c;
        }
        //cout<< "\n sumCol= " << sumCol<<endl;
    }               
}

// arguments passing row=row+1  col=col+1
void print(const int array[][COLMAX],int row,int col,int ten){
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){            
            cout <<setw(ten)<<array[i][j];            
        }
        cout<<endl;
    }
}