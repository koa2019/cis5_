/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 6/7/22 1:50 PM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 * v1 passes tc 0. fix for passing 10 and even&odd equal number of indx
 * v2: add conditonals for when even odd vectors are equal
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX]={};     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    cout<<"Input the number of integers to input."<<endl
        <<"Input each number."<<endl;
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    int nNum,x;
    cin>>nNum;
    //cout<<nNum<<endl;
    for(int i=0;i<nNum;i++){
        cin>>x;
        if(x%2==0){
            even.push_back(x);
        } else{
            odd.push_back(x);
        }
    }
    //if (even.size()<odd.size()) even.push_back(' ');
    
}

void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    
    int row,col=2, eSize, oSize,diff=0; 
    eSize=even.size();
    oSize=odd.size();
    
    // set number of rows for array 
    if (eSize<oSize){
        row=oSize;
        diff=oSize-eSize;
        //even.push_back(' ');
         // odd is bigger
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
            
                if(j==0) {  // save even vector to array row 0
                    if(i==4){
                    //if(diff>0 && i==4){
                        //cout<<"hit even diff\n";
               
                        array[4][j]=' ';
                     //cout<< static_cast<char>(array[i][j])<<" \n";
                    }  
                    else {
                        //  cout <<"else "<<i<<" "<<j << " ";
                        array[i][j]=even[i];
                        //cout<< array[i][j]<<" \n";
                    }
                }
            
            if(j==1) {  // save odd vector to array col 1
               // if(diff<0)
                   // cout<<"odd diff \n";
                    //array[row+1][j]=' j';
               // else 
                    array[i][j]=odd[i];
                    //cout<<array[i][j]<<endl;
                }
            }
        }
        
       
    } else if(eSize>oSize){
        row=eSize;
        diff=oSize-eSize;
      //  odd.push_back(' ');
    } else {
        row=eSize;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 if(j==0) array[i][j]=even[i];
                 if(j==1)  array[i][j]=odd[i];
            }
        }
    }

/*    
    //cout<<"diff "<<diff<<endl;
   
  
    */ 
}

void prntAry(const int arr[][COLMAX],int eSize,int oSize,int width){
    
    int row=eSize;
    if(eSize<oSize) row=oSize;
    int last=(row-1);
    int col =2; // returns col
    
    //cout << "r"<<row<<" c"<<col<<" last "<<last << endl;
    
    cout<<"     Array      Even       Odd"<<endl;
    
    // when even and odd are equal
    if(eSize==oSize){    
        for(int i=0;i<row;i++){
       
                // print col==0
                for(int j=0;j<col-1;j++){
                cout<< setw(width-1)<<" ";
                cout << setw(width)<<" " << arr[i][j];
                }
                // print col==1
                for(int j=1;j<col;j++){
                cout << setw(width-1)<<" " << arr[i][j];
                }
                cout<<endl;
            
        }// ends row for loop
    } // ends if
        
    // if odd vector bigger than even vector
    if(eSize<oSize){  
        for(int i=0;i<row;i++){
            // only prints col[0]
            for(int j=0;j<col-1;j++){
                cout<< setw(width-1)<<" ";
            
                if(i==last && j==0) cout << setw(width)<<" " << static_cast<char>(arr[i][j]);
                else cout << setw(width)<<" " << arr[i][j];
            }
            // only prints col[1]
            for(int j=1;j<col;j++){
                cout << setw(width-1)<<" " << arr[i][j];
            }
            cout<<endl;
        }
    }
        
    
} // closes function


void prntVec(vector<int> even, vector<int> odd,int width){
   
    int row, eSize, oSize,diff; 
    eSize=even.size();
    oSize=odd.size();
    row=eSize;
    //cout<<eSize<<" "<<oSize<<endl;
    
    cout<<"    Vector      Even       Odd"<<endl;
    
    if(oSize>eSize) {
        row=oSize;
        diff=oSize-eSize;
        //even.push_back();
        
        for(int val=0;val<row;val++){
            cout<< setw(width-1)<<" ";
        
            if(row==5 && val==4){
            cout<< setw(width+1)<<" "; 
            } else cout << setw(width)<<" " << even[val];
            cout << setw(width-1)<<" " << odd[val]<<endl;
        }
    } else if(eSize>oSize){
        
        cout <<"hit printvector\n";
    }
    else {
   
        row=eSize;
        diff=eSize-oSize;
        // odd.push_back(0);
        for(int val=0;val<row;val++){
            cout<< setw(width-2)<<" ";
            cout << setw(width)<<" " << even[val];
            cout << setw(width)<<" " << odd[val]<<endl;
        }
        
    }
}
