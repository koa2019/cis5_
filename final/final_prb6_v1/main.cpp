/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 6/6/22 2:40 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
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
}

void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]){
    int sumCol, sumRow, ttl=0;
    
    //copy orginal array to new array
     for(int i=0;i<row+1;i++){
         sumRow=0;
         
        for(int c=0;c<col+1;c++){
           
            augAry[i][c]=array[i][c];
            sumRow+=augAry[i][c];
            ttl+=augAry[i][c];
            if(c==2)augAry[i][c]=sumRow;
         
            if(i==2 && c==2)augAry[2][c]=ttl;
        }
     }
     
    ttl=0;
    //calculate sum of each row       
    for(int c=0;c<col+1;c++){
        sumCol=0;
        
        for(int i=0;i<row+1;i++){
           
            sumCol+=augAry[i][c];
            if(i==2 && c==0) augAry[i][c]=sumCol;
               
            if(i==2 && c==1)augAry[i][c]=sumCol;
          //  cout <<" r= "<<i <<" c= "<< c;
        }
       // cout<< " sumCol= " << sumCol<<endl;
    }
}

void print(const int array[][COLMAX],int row,int col,int ten){
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            cout <<setw(ten)<<array[i][j];
            
        }
        cout<<endl;
    }
}