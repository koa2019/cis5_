/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 22, 2022 6:33 PM
 * Purpose:  Gaddis 9th ed - ch4 prb 14 - race
 */
 
//System Libraries
#include <iostream>  //Input/Output Library
#include <cstring>  // string
#include <iomanip>  // setw()
using namespace std;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string n1, n2, n3;          // name1, names2, names3
    unsigned short t1, t2, t3;  // times of each runner
    
    //Map inputs -> outputs
    cout << "Race Ranking Program\n"
        << "Input 3 Runners\n"
        << "Their names, then their times\n";
    cin >> n1 >> t1;
    cin >> n2 >> t2;
    cin >> n3 >> t3;
    
    // conditionals sort runners from fastest to slowest
    if(t1<t2 && t2<t3){
        
        cout << n1 << "\t" << setw(3) << t1 << endl
             << n2 << "\t" << setw(3) << t2 << endl
             << n3 << "\t" << setw(3) << t3;
             
    } else if (t1<t3 && t3<t2){
        
        cout << n1 << "\t" << setw(3) << t1 << endl
             << n3 << "\t" << setw(3) << t3 << endl
             << n2 << "\t" << setw(3) << t2;
             
    } else if (t2<t1 && t1<t3){
        
        cout << n2 << "\t" << setw(3) << t2 << endl
             << n1 << "\t" << setw(3) << t1 << endl
             << n3 << "\t" << setw(3) << t3;
             
    } else if (t2<t3 && t3<t1){
        
        cout << n2 << "\t" << setw(3) << t2 << endl
             << n3 << "\t" << setw(3) << t3 << endl
             << n1 << "\t" << setw(3) << t1;
             
    } else if (t3<t1 && t1<t2){
        
        cout << n3 << "\t" << setw(3) << t3 << endl
             << n1 << "\t" << setw(3) << t1 << endl
             << n2 << "\t" << setw(3) << t2;
             
    }else if (t3<t2 && t2<t1){
        
        cout << n3 << "\t" << setw(3) << t3 << endl
             << n2 << "\t" << setw(3) << t2 << endl
             << n1 << "\t" << setw(3) << t1;
             
    } else { cout << "Oops! Error. "; }
    
    
    //Exit stage right or left!
    return 0;
}