/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on: 05/16/22 @ 10:42 AM 
 * Purpose: Compare the answer sheet to the key
 *          and grade v1 
 * does not use function to read in data from files
 * does use function with array arguments to compare 2 arrays
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File I/O
#include <string.h>    //String Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
//const ifstream  inFile, // variable to read in file being read in that already exists
                //inFile2;
//Function Prototypes
void print(const string &);
void read(const char [], string &);
int compare(const string &, const string &, string &);

int compare(const char[], const char[], char[]);
//Execution Begins Here!

int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    const int SIZE = 25;
    ifstream  inFile, // variable to read in file being read in that already exists
              inFile2;
    ofstream  outFile; // variable to write to file
    string    key,
              answers,
              score;
    char      fileKey[SIZE]="key.txt",
              fileAns[SIZE]="answer.txt",
              scores[SIZE];    // array for student's number of correct and wrong answers
    float     pRight;

    //Initialize or input i.e. set variable values
    //read(fileKey,key);     
    //read(fileAns,answers);
    
    // open files that already exists
    inFile.open("key.txt");
    inFile2.open("answer.txt");

    // count number of integers in array 
    int count=0;
    while (inFile >> fileKey[count]) {
        //cout << "hit\n";
        count++;
    }

    int count2 = 0;
    while (inFile2 >> fileAns[count2]) {
        count2++;
    }    
    
    // display both arrays contents
    if (count==count2) {        
        
        cout <<"Key        ";
        // display data read in from inFile 
        for (int val = 0; val<count; val++) {
            cout << fileKey[val] << " ";            
        }
        cout << endl;
        cout << "Answer key ";
        for (int val2=0; val2<count; val2++) {           
            cout << fileAns[val2] << " ";
        }
        cout << endl;
    }     

    //Score the exam
    //pRight=compare(key,answers,score);
    pRight=compare(fileKey,fileAns,scores);
    //cout << "pRight " << pRight << endl;
    cout<<"Percentage Correct = "<<pRight/count*100<<"%"<<endl;
    
    //Display the outputs
    // cout<<"Key     ";print(key);
    // cout<<"Answers ";print(answers);
    // cout<<"C/W     ";print(score);
    // cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;

    inFile.close();
    inFile2.close();
    //Exit stage right or left!
    return 0;
}

//  *********** FUNCTION DEFINTIONS *************

// compare 2 arrays and save to a new array
int compare(const char key[], const char ans[], char scores[]){
    int correct=0;
    int size=20;
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