/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: 05/16/22 @ 10:42 AM 
 * Purpose: Compare the answer sheet to the key
 *          and grade
 * v2: added print() and displayed all 3 arrays with it
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File I/O
#include <string.h>    //String Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void print(const string &); // LEHR's
void print(const char [], int); 

void read(const char [], string &);

int compare(const string &, const string &, string &); // LEHR's
int compare(const char[], const char[], char[], int);


int main(int argc, char** argv) {//Execution Begins Here!
    //Set the random number seed

    //Declare Variables
    const int SIZE = 25;    // set it to max size because I don't know how many #s in file
    ifstream  inFile, // variable to read in file being read in that already exists
              inFile2;
   
    string    key,
              answers,
              score;
    char      fileKey[SIZE]="key.txt",
              fileAns[SIZE]="answer.txt",
              scores[SIZE]; // array for student's number of correct and wrong answers
    float     pRight;

    //Initialize or input i.e. set variable values
    //read(fileKey,key);     
    //read(fileAns,answers);
    
    // open files that already exists
    inFile.open("key.txt");
    inFile2.open("answer.txt");

    // count number of integers in array 
    int count=0;    
    while (count<SIZE && inFile >> fileKey[count]) {       
        count++;
    }

    int count2 = 0;
    while (count2<SIZE && inFile2 >> fileAns[count2]) {
        count2++;
    }    
  
    //Score the exam
    //pRight=compare(key,answers,score);
    pRight=compare(fileKey, fileAns, scores, count);
       
    //Display the outputs
    // cout<<"Key     "; print(key);
    cout<<"Key     "; print(fileKey,count);
    // cout<<"Answers "; print(answers);
    cout<<"Answers "; print(fileAns,count);
    // cout<<"C/W     "; print(score);
    cout<<"C/W     "; print(scores, count);
    // cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;
    cout<<"Percentage Correct = "<<pRight/count*100<<"%"<<endl;

    // close files
    inFile.close();
    inFile2.close();
    
    //Exit stage right or left!
    return 0;
}

//  *********** FUNCTION DEFINTIONS *************
void print(const char array[], int count){
    
    for(int i=0;i<count;i++){        
        cout << array[i] << " ";
    }
    cout << endl;
}
// compare 2 arrays and save to a new array
int compare(const char key[], const char ans[], char scores[], int size){
    
    int correct=0;
   
    for(int i=0;i<size;i++){
        
        if(key[i]==ans[i]){
            scores[i]='C';   
            correct++;
        } else scores[i]='W'; 
    }
    return correct;
}

// read in file data
void read(const char array[], string &str) {
    
    //inFile.open(array);
    
}