/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 24, 2022, 11:44 AM
 * Assignment 6 menu with all 8 problems inside of it
 */

// System Libraries: 
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
#include <fstream>   //File I/O
#include <string.h>    //String Library

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions
const int COLS = 6; //  prb1
const int SEVEN = 7; // prb1
const int COLS7 = 7; // prb2
const float MAXRAND=pow(2,31)-1;// prb4

// Problem 1 Function prototypes
void getInput(int &);
void prb1();
//Function Prototypes
void dsplyIntro();
void printColZero(int);
void fillTbl(int [][SEVEN], int);
void prntTbl(int [][SEVEN], int);

void prb2();
// problem 2 functions
void dsplyIntro2(int);
void printColZero2(int);
void fillTbl2(int [][COLS7], int);
void prntTbl2(const int [][COLS7], int);

void prb3();
//Problem 3 Function Prototypes
void init(int [], int); //Initialize the array
void print(int [], int, int); //Print the array
void revrse(int [], int [], int); //Reverse the array

void prb4();
//Problem 4 Function Prototypes
void  init4(float [],int);//Initialize the array
void  print4(float [],int,int);//Print the array
float avgX4(float [],int);//Calculate the Average
float stdX4(float [],float,int);//Calculate the standard deviation

void prb5();
//Problem 5 Function Prototypes
void print5(const char [], int); 
int compare5(const char[], const char[], char[], int);

void prb6();
//Problem 6 Function Prototypes
void fillAry6(int [],int);
void prntAry6(int [],int,int);
bool linSrch6(int [],int,int,int&);

void prb7();
//Problem 7 Function Prototypes
void fillAry7(int [],int);
void prntAry7(int [],int,int);
void selSrt7(int [],int);
bool binSrch7(int [],int,int,int&);

void prb8();
//Problem 8 Function Prototypes
void fillAry8(int [],int);
void prntAry8(int [],int,int);
void bublSrt8(int [],int);
bool binSrch8(int [],int,int,int&);

// Program execution begins here
int main(int argc, char** argv) {
     //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // declare variables
    char ans;
    int choice;

    // map the inputs to the outputs
    do {
        getInput(choice);
        cout << choice;

        switch (choice) {
            case 1: {
                prb1();
                break;
            } case 2: {
                prb2();
                break;
            } case 3:  {
                prb3();
                break;
            } case 4: {
                prb4();
                break;
            } case 5: {
                prb5();
                break;
            }case 6: {
                prb6();
                break;
            }case 7: {
                prb7();
                break;
            }case 8:{
                prb8();
                break;
            }
            default: cout << "\nError in switch()\n";
        }
        
        cout << endl << "Run menu again? y for yes. \n";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    // exit code
    return 0;
}
//********************************************
// FUNCTION DEFINITIONS

//********************************************
// problem 8
void prb8(){
    
     //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry8(array,SIZE);

    //Sorted List
    bublSrt8(array,SIZE);
    
    //Display the outputs
    prntAry8(array,SIZE,10);
    
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    
    if(binSrch8(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found "<<endl;
    
}
// ************* Problem 8 FUNCTION DEFINITIONS ************
// sort array smallest to biggest
void bublSrt8(int arr[], int SIZE){
    
    bool go;
    int lessby1=SIZE-1;  // largest num goes to the end after the first swap, so start loop at 2nd to last position. more efficient
    
    do {
        go=false;   // set flag
        
        for(int i=0; i<lessby1; i++){  // loop through entire array
    
            if(arr[i] > arr[i+1]){        // compare the 2 indices next to each other
                swap(arr[i], arr[i+1]);  // swap their positions
                go=true;                // reassign flag
            }
        }
    } while(go);
}
// check to see if search value is inside arr. if so return its index position and true. 
bool binSrch8(int arr[], int SIZE, int val, int &index){
    
    for(int j=0; j<SIZE; j++){ // loop through entire array 
        
        if(val==arr[j]){     // check if val were looking for equals any of the array index's value
            index=j;        // assign j's index to ref variable 
            return true;    // set flag
        }   
    }
    return false;   // return false if val is not inside array
}
// display array
void prntAry8(int arr[], int SIZE, int cols){
    cout << endl;
    for(int i=0;i<SIZE;i++){
        cout << setw(3) << arr[i] << " ";
        if(i%cols==(cols-1)) cout << endl;
    }
    cout << endl;
}
// fill array
void fillAry8(int arr[], int SIZE){
    
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%(100+1);
    }
}

//********************************************
// Problem 7 
void prb7(){    
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry7(array,SIZE);

    //Sorted List
    selSrt7(array,SIZE);
    
    //Display the outputs
    prntAry7(array,SIZE,10);
    
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
        
    if(binSrch7(array,SIZE,val,indx))
       cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found "<<endl;
}
// ************* Problem 7 FUNCTION DEFINITIONS ************
// sort array smallest to biggest
void selSrt7(int arr[], int SIZE){
    
    int lessby1=SIZE-1;  // largest num goes to the end after the first swap, so start loop at 2nd to last position. more efficient
    
    for(int i=0; i<lessby1; i++){  // loop through entire array    
        for(int j=i+1; j<SIZE; j++){  // loop starting at 2nd index arr[1]
        
            if(arr[i] > arr[j]){  // compare the 2 indices next to each other
                swap(arr[i], arr[j]);  // swap their positions
            }
        }
    }
}
// check to see if search value is inside arr. if so return its index position and true. 
bool binSrch7(int arr[], int SIZE, int val, int &index){
    
    for(int j=0; j<SIZE; j++){ // loop through entire array 
        
        if(val==arr[j]){    // check if val were looking for equals any of the array index's value
            index=j;     // assign j's index to ref variable 
            return true; // set flag
        }   
    }
    return false;   // return false if val is not inside array
}
// display array
void prntAry7(int arr[], int SIZE, int cols){
    cout << endl;
    for(int i=0;i<SIZE;i++){
        cout << setw(3) << arr[i] << " ";
        if(i%cols==(cols-1)) cout << endl;
    }
    cout << endl;
}
// fill array
void fillAry7(int arr[], int SIZE){
    
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%(100+1);
    }
}

// ************************************************
void prb6(){     
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,
        val;
    
    //Initialize or input i.e. set variable values
    val=50;
    fillAry6(array,SIZE);
    
    //Display the outputs
    prntAry6(array,SIZE,10);
    
    if(linSrch6(array,SIZE,val,indx))
        cout<<endl << val<<" was found at indx = "<<indx<<endl;
    else cout << val << " was NOT found.\n";
    
}
//************* Problem 6 FUNCTION DEFINITIONS **************
// fill array with integers
void fillAry6(int arr[],int SIZE){
    
    int min=1;
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%(100+1)+1;
    }
}
void prntAry6(int arr[], int SIZE, int num){
  
    cout << endl;
    
    for(int i=0; i<SIZE; i++){
        cout << arr[i] << " ";
        
        if(i%num==(num-1)) cout << endl;
    }
    cout << endl;
}
// search for integer
bool linSrch6(int arr[], int SIZE, int val, int &indx){
    
     for(int i=0; i<SIZE;i++){
        if(arr[i]==val){
            indx=i;
            return true;
        } 
     }
    return false;
}
//********************************************
// problem 5
void prb5(){
     //Declare Variables
    const int SIZE = 25;    // set it to max size because I don't know how many #s in file
    ifstream  inFile,       // variable to read in file being read in that already exists
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
    pRight=compare5(fileKey, fileAns, scores, count);
       
    //Display the outputs    
    cout<<endl << "C/W     "; print5(scores, count);   
    cout<<"Percentage Correct = "<<pRight/count*100<<"%"<<endl;

    // close files
    inFile.close();
    inFile2.close();
}
//  ***********Problem 5 FUNCTION DEFINTIONS *************
void print5(const char array[], int count){
    
    for(int i=0;i<count;i++){        
        cout << array[i] << " ";
    }
    cout << endl;
}
// compare 2 arrays and save to a new array
int compare5(const char key[], const char ans[], char scores[], int size){
    
    int correct=0;
   
    for(int i=0;i<size;i++){
        
        if(key[i]==ans[i]){
            scores[i]='C';   
            correct++;
        } else scores[i]='W'; 
    }
    return correct;
}

//********************************************
// problem 4
void prb4(){
    
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init4(test,SIZE);
    
    //Display the outputs
    //int nCols=5;
    //print(test,SIZE,nCols);
    
    float avg=avgX4(test,SIZE);
    cout << fixed << setprecision(7);
    cout<<endl << "The average            = "<< avg << endl;
    cout<<"The standard deviation = "<<stdX4(test,avg, SIZE)<<endl;
}
//  *********** Problem 4 FUNCTION DEFINITIONS *************
// calculates standard deviation
float stdX4(float test[], float avg, int SIZE){
    
    float sum=0;
    float x;
    
    for(int i=0;i<SIZE;i++){
        
        x=pow( (test[i]-avg),2);
        sum+=x;
    }
    return sqrt(sum/(SIZE-1));
}
// calculates the average of all the floats in test array 
float avgX4(float test[], int SIZE){
    
    float avg=0;
    
    for(int i=0;i<SIZE;i++){
        avg+=test[i];
    }
    return avg/SIZE;
}
// read input from user
void  init4(float test[], int SIZE){
   
    for(int i=0;i<SIZE;i++){
        //cin >> test[i];
        test[i]=(i);
    }
}
// print array
void  print4(float test[],int SIZE,int nCols){
    
    for(int i=0;i<20;i++){
            cout << test[i] << " ";
    }
}

//***************************************
// problem 3
void prb3() {

    //Declare Variables
    const int SIZE = 50;
    int length = 10;
    int test[SIZE];
    int reverse[SIZE];

    //Initialize or input i.e. set variable values
    init(test, SIZE);
    cout << endl << "Random Array \n";
    print(test, SIZE, length);

    //Reverse the Values
    revrse(test, reverse, SIZE);

    //Display the outputs
    cout << endl << "Array Reversed \n";
    print(reverse, SIZE, length);
}
//    ******** Problem 3 FUNCTION DEFINITIONS  *********
void init(int test[], int SIZE) {

    for (int i = 0; i < SIZE; i++) {
        //cin >> test[i];
        test[i] = rand() % (100 + 1) + 1;
    }
}
// prints array with 10 integers in each row
void print(int array[], int SIZE, int length) {

    int count = -1;

    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
        count++;

        // adds endl after the 10th int is printed.
        // creates rows with 10 columns
        if ((count % length) == (length - 1)) cout << endl;
    }
}
// reverses the order of 1 array and saves it as a new array 
void revrse(int test[], int reverse[], int SIZE) {

    for (int i = 0, j = SIZE - 1; j >= 0; i++, j--) {
        reverse[i] = test[j];
    }
}

// ***********************************************************
// Problem 2
void prb2() {

    //Declare Variables
    const int ROWS = 7; // LEHR's
    int tblProd[ROWS][COLS7] = {}; // LEHR's

    int nRows, nCols;

    cout << "\nProblem 2 Product Table\n"
            << "Input number rows and number cols\n";
    cin >> nRows >> nCols;

    // call function to display intro message to user
    dsplyIntro2(nCols);

    // get product of row*col
    fillTbl2(tblProd, ROWS);

    //Display the outputs
    prntTbl2(tblProd, ROWS);
}

//   ********** Problem 2 FUNCTION DEFINITIONS  **********
void fillTbl2(int tblProd[][COLS7], int ROWS) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS7; j++) {

            // prints sum of row+col
            tblProd[i][j] = i*j;
            //cout << setw(4) << tblProd[i][j];
            //cout << " [" <<i<<"]*[" <<j<< "]=" << tblProd[i][j];
        }
        //cout << endl;
    }
}
// display table contents
void prntTbl2(const int tblProd[][COLS7], int ROWS) { // LEHR's

    for (int i = 1; i < ROWS; i++) {
        for (int j = 0; j < COLS7; j++) {

            if (j == 0) printColZero2(i);
            else {
                cout << setw(4) << tblProd[i][j];
                //cout << " [" <<i<<"]*[" <<j<< "]=" << tblProd[i][j];
            }
        }
        cout << endl;
    }
}
// for ROWS 1 thru 6, prints COL[0] 
void printColZero2(int i) {

    switch (i) {
        case 1:
        {
            cout << setw(4) << i << setw(2) << "|";
            break;
        }
        case 2:
        {
            cout << setw(1) << "R" << setw(3) << i << setw(2) << "|";
            break;
        }
        case 3:
        {
            cout << setw(1) << "O" << setw(3) << i << setw(2) << "|";
            break;
        }
        case 4:
        {
            cout << setw(1) << "W" << setw(3) << i << setw(2) << "|";
            break;
        }
        case 5:
        {
            cout << setw(1) << "S" << setw(3) << i << setw(2) << "|";
            break;
        }
        default: cout << setw(4) << i << setw(2) << "|";
    }
}
// displays intro message to user
void dsplyIntro2(int nCols) {
    int blank = 4;
    cout << "Think of this as a Product/Muliplication Table" << endl
            << setw(11) << setfill(' ') << " " << setw(14) << right << "C o l u m n s\n"
            << setw(blank + 2) << "|";

    // prints blanks and then 1-6
    for (int j = 0; j < nCols; j++) {
        cout << setw(blank) << (j + 1) << setw(blank) << setfill(' ');
    }
    cout << endl << "----------------------------------" << endl;
}

// ************************************************************
// Problem 1
void prb1() {
    //Declare Variables
    const int ROWS = 6; // LEHR's
    int tablSum[ROWS][COLS]; // LEHR's
    int sum[SEVEN][SEVEN]; // MINE

    //Initialize arrays to zero
    tablSum[0][0] = {0};
    sum[0][0] = {0};

    // call function to display intro message to user
    dsplyIntro();

    // get sums of row+col
    fillTbl(sum, ROWS);

    //Display the outputs
    prntTbl(sum, ROWS);

}
//  *********** Problem 1 FUNCTION DEFINITIONS ************
void fillTbl(int sum[][SEVEN], int ROWS) {

    //cout << "sum " << sum[0][0] << endl;    
    //
    for (int i = 1; i < ROWS + 1; i++) {

        for (int j = 0; j < COLS + 1; j++) {

            // prints sum of row+col
            sum[i][j] = i + j;
            //cout << setw(4) << tablSum[i][j];
            //cout << " [" <<i<<"]+[" << j << "]= " << tablSum[i][j];
        }
        //cout << endl;
    }
}

void prntTbl(int sum[][SEVEN], int ROWS) {

    for (int i = 1; i < ROWS + 1; i++) {
        for (int j = 0; j < COLS + 1; j++) {

            if (j == 0) printColZero(i);
            else {
                cout << setw(4) << sum[i][j];
                //cout << " " <<i<<"+" <<j<< "= " << sum[i][j];
            }
        }
        cout << endl;
    }
}

// for ROWS 1 thru 6, prints COL[0] 
void printColZero(int i) {
    switch (i) {
        case 1:
        {
            cout << setw(4) << i << setw(2) << "|";
            break;
        }
        case 2:
        {
            cout << setw(1) << "R" << setw(3) << i << setw(2) << "|";
            break;
        }
        case 3:
        {
            cout << setw(1) << "O" << setw(3) << i << setw(2) << "|";
            break;
        }
        case 4:
        {
            cout << setw(1) << "W" << setw(3) << i << setw(2) << "|";
            break;
        }
        case 5:
        {
            cout << setw(1) << "S" << setw(3) << i << setw(2) << "|";
            break;
        }
        default: cout << setw(4) << i << setw(2) << "|";
    }
}

// displays intro message to user
void dsplyIntro() {
    
    int blank = 4;
    cout << "\nThink of this as the Sum of Dice Table\n"
            << setw(11) << setfill(' ') << " " << setw(14) << right << "C o l u m n s\n"
            << setw(blank + 2) << "|";

    for (int j = 0; j < COLS; j++) {
        cout << setw(blank) << (j + 1) << setw(blank) << setfill(' ');
    }
    cout << endl << "----------------------------------" << endl;
}

// display instructions and get and return user input
void getInput(int &c) {
    cout << "Assignment 6 Menu\n"
         << "Problem 1 - Sum Table\n"
            << "Problem 2 - Product Table\n"
            << "Problem 3- Reverse Array \n"
            << "Problem 4 - Standard Deviation \n"
            << "Problem 5 - Grading Scantron \n"
            << "Problem 6 -  Linear Search \n"
            << "Problem 7 -  Binary Search with Selection Sort \n"
            << "Problem 8 - Binary Search with Bubble Sort \n"
            << "Which problem would you like to run? \n"
            << "Enter a number 1 through 8. \n";
    cin >> c;
}
