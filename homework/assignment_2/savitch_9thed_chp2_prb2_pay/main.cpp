/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on March 6, 2022, 1:10 pM
 * Purpose:  assignment 2 - savitch_9thed_chp2_prb2_pay
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  // fixed, setprecision()
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    
    // Constants
    const float PAYINCR = 0.076f;   // workers won 7.6% pay increase
    
    //Declare Variables
    unsigned short months = 6;     // workers won retroactive pay for 6 months
    
    float oldAnnl,  // previous years annual pay
          newAnnl,  // new annual pay
          retro,    // retroactive pay
          mnthInc,  // monthly increase
          oldMnth,  // previous years monthly pay rate
          newMnth;  // new monthly pay rate
    
    //Initialize or input i.e. set variable values
    newAnnl = retro = oldAnnl = newMnth = 0.00f;

    
    //Map inputs -> outputs
    cout << "Input previous annual salary.\n";
    cin >> oldAnnl;
    
    oldMnth = oldAnnl/12;           // calculate previous years monthly pay. divide prev annual salary by 12 months;
    
    mnthInc = oldMnth * PAYINCR;    // calculate a single months pay increase by muliplying it by 7.6% pay increase

    retro =   mnthInc* months;      // calculate worker's retro pay. Multiply monthfor 6 months
    
    newMnth = oldMnth + mnthInc;    // calculate worker's new monthly pay. Add old monthly pay with monthly increase 
    
    newAnnl = newMnth * 12;         // calculate new annual pay. Multiply new monthly pay by 12
    
    //Display the outputs
    cout << fixed << setprecision(2);
    
    cout << setw(19) << left <<  "Retroactive pay" << setw(3) << "= $" << setw(7) << right << retro << endl;
    
    cout << setw(19) << left << "New annual salary" << setw(3) << "= $" << setw(7) << right << newAnnl << endl; 
    
    cout << setw(19) << left << "New monthly salary" << setw(3) << "= $" << setw(7) << right << newMnth;    

    //Exit stage right or left!
    return 0;
}