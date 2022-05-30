/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 2, 2022,  8:58 PM
 * Purpose: gaddis 9th ed- ch6 - prob 10 - Average v1
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>
using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes
void getAvg(float,float,float,float);

// Program execution begins here
int main(int argc, char** argv) {
    
    // declare variables
    float s1,
          s2,
          s3,
          s4,
          s5;
    
    // initial variables
    cout << "Find the Average of Test Scores"<<endl
         << "by removing the lowest value." << endl;
    cout <<"Input the 5 test scores." << endl;
    cin >> s1 >> s2 >>s3>>s4>>s5;
    
    // map the inputs to the outputs
    //lowest=s1;
    if(s1<s2 && s1<s3 && s1<s4 && s1<s5) getAvg(s2,s3,s4,s5);
        
    //lowest=s2;
    else if(s2<s1 && s2<s3 && s2<s4 && s2<s5) getAvg(s1,s3,s4,s5);
    
    //lowest=s3;
    else if(s3<s1 && s3<s2 && s3<s4 && s3<s5) getAvg(s1,s2,s4,s5);
        
    //lowest=s4;
    else if(s4<s1 && s4<s2 && s4<s3 && s4<s5) getAvg(s1,s2,s3,s5);
        
    //lowest=s5;
    else if(s5<s1 && s5<s2 && s5<s3 && s5<s4) getAvg(s1,s2,s3,s4);
        
    else cout << "Error with inputs.\n";
    
    // exit code
    return 0;
}

void getAvg(float n1, float n2, float n3, float n4){
    float avg=(n1+n2+n3+n4)/4;
     cout << fixed << setprecision(1) << "The average test score = " << avg;
}