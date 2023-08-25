/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on May 31, 2022,  12:16 PM
 * Purpose: Project 2. Covers chapters 1-9 in Gaddis. 
 * Version 2:
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand(), EXIT_SUCCESS
#include <fstream>  // ofstream 
#include <cstring>  // string library
//#include <string>
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions


// Function prototypes
void banner(string);      // display game 
void copyAdd(string [],const int,string[],const int,string);
void getName(string &);  // get player 1's name using pass by reference
void hitMiss(int,int);  // hit message for correct guess
void hitMiss(int);      // possible overload () with hitMsg()
void dblMiss();        // try again message
void instruc(string, const int, int =1); // instructions for players
bool isReady(char);   // returns bool value
string pickP2(string [],int);  // randomly picks a number for player 2
void rBanner(int &, bool);      // display the round number
void sBanner(string,string,string,int,int);   // display scoreboard banner
void scoresMsg(int,int,float,float,float);  // displays scores for both players
void upper(string &); // changes string to all uppercase letters


// Program execution begins here
int main(int argc, char** argv) {

    // set random number seed
    srand(static_cast<unsigned int>(time(0)));

    // declare variables
    ifstream     inFile; // for reading an existing file
    ofstream     outFile; // for outputting to a file

    const int    MIN = 1, // minimum number for rand()
                 MAX = 16; // maximum number for rand()
    const int    SIZE7 = 7,  // size for player 2 names array
                 SIZE8 = 8;
    const int    ROWS = 2,
                 COLS = 8;   // number of cols in 2D array
   
    bool         p1_crrt, // player 1 correct
                 p2_crrt, // player 2 correct
                 ready;   // ready to continue playing
    
    char         ans, // answer  
                 ch;
    int          maxGmes = 0, // number of games
                 nGmsLft,     // number of games left       
                 //round = 1, // round
                 p1Guess, // player 1 guess
                 p2Guess, // player 2 guess
                 p1Ship1, // player 1 ship number 1
                 p2Ship1, // player 2 ship number 1
                 p1Win = 0, // number of wins player 1 has
                 p2Win = 0, // number of wins player 2 has
                 ttlGmes = 0,   // sum of both players number of wins
                 ttlRnds = 0;   // sum of total rounds played
    
    float        avg1, // average number of wins for player 1
                 avg2, // average number of wins for player 2
                 avgRnds;   // average rounds it takes to win
    
    string       p1Name = " ", 
                 p2Name = " ";
                
    string p2Names[SIZE7]={"BART", "JANIS", "STEPHANIE", "TING", "VICTOR", "JILLIAN", "JOHN"};
    //string board[ROWS][COLS]={{"A1","A2","A3","A4","A5","A6","A7","A8"}, {"B1","B2","B3","B4","B5","B6","B7","B8"}};
    
    // open an existing file that holds max number of games a user can play
    inFile.open("maxNGms.txt");

    // create a file to output to
    outFile.open("scores.txt");
    
    // read in maximum number of games that can be played from file
    inFile >> maxGmes;
    nGmsLft = maxGmes;  // set numberOfGamesLeft to equal maxGames
   
    // display game's introduction message
    string gameNme = "BATTLE";
    banner(gameNme); 
    
    // ask for player 1's name
   getName(p1Name); 
   
   // get player 2's name from an array of names
   p2Name = pickP2(p2Names,SIZE7);
   cout << setw(12) << p1Name << " vs " << p2Name << "!" << endl;
 
   // create new array to hold player 1 & player 2's names
   string names[SIZE8]={};
   
   // copy contents of one array to another array and add player1's name
   copyAdd(p2Names,SIZE7,names,SIZE8,p1Name);
      
   cout << "\nPress any key to begin. ";
   cin.ignore();
   cin.get();   // pause screen before game starts
  
    do { // game starts here
                
        // sets variables to default starting values
        p1_crrt = p2_crrt = false;
        
        // initial variables to represent the location of each player's ship        
        p1Ship1 = rand()%(MAX-MIN)+MIN;
        p2Ship1 = rand()%(MAX-MIN)+MIN;
        
        cout << "p1Ship1 = " << p1Ship1 << endl
             << "p2Ship1 = " << p2Ship1 << endl;
    /*    
        std::string shpLoc1;
        
        if(p1Ship1>=1 && p1Ship1<=8){
            shpLoc1="A" + std::to_string(p1Ship1);
        }else if(p1Ship1>=9 && p1Ship1<=16){
            
            shpLoc1="B" + std::to_string((p1Ship1-8));           
        } else cout << "error in shipLoc \n";
        
        cout << "ship1 = " << shpLoc1 << endl;      
     */  
        
        // loops until a player correctly guesses opponents ship location
        while((!p1_crrt) && (!p2_crrt)){
            
            rBanner(ttlRnds, false);
            
            //*************** Player 1's Guess ************* 
            //**********************************************
            // display instructions to player 1
            instruc(p1Name, MAX);                
            
            // program generates random number guess
            p1Guess = rand()%(MAX-MIN)+MIN;

            // checks if player1 guess is correct
            if(p1Guess == p2Ship1){

                // increment player 1 number of wins
                p1Win++;
                nGmsLft--;  // decrease number of total games

                // reassign player 1's value for a correct guess
                p1_crrt = true;                             

                // display HIT message for correct guess
                hitMiss(p1Guess, p2Ship1);    
                
            // else conditional when player 1 guess is wrong  
            } else hitMiss(p1Guess); // display MISS message for wrong guess

            // conditional only runs if player 1 misses player 2's ship
            if(!p1_crrt){

                //*************** Player 2's Guess *************
                //**********************************************
                // display instructions to player 2
                instruc(p2Name, MAX);
                
                // program automatically generates a guess for player 2
                p2Guess = rand()%(MAX-MIN)+MIN;

                // conditional checks if guess is correct
                if(p2Guess == p1Ship1){

                    // increment player 2 number of wins
                    p2Win++;
                    nGmsLft--;  // decrease number of total games
                    
                    // reassign player 2's value for a correct guess
                    p2_crrt = true;

                    // display HIT message for correct guess  
                    hitMiss(p2Guess, p1Ship1);
                    
                // else conditional when player 1 guess is wrong  
                } else hitMiss(p2Guess); // display MISS message for wrong guess             
            } // ends if player 1 was wrong conditional

            //round++;
            // if both players guess wrong, then increment round by 1
            // and display message to tell them to continue guessing 
            if((!p1_crrt) && (!p2_crrt)){
                
                // display try again message when both players guess wrong
                dblMiss();
            }
        }// ends while()

        // call function to display both player's scores
        sBanner("SCOREBOARD", p1Name, p2Name, p1Win, p2Win);        

        // calculate total number of games won & number rounds played
        ttlGmes = p1Win+p2Win;
        //ttlRnds += round; // sums the total number of rounds from all games

        // calculates each players percentage of winning
        avg1 = p1Win/static_cast<float>(ttlGmes)*100;
        avg2 = p2Win/static_cast<float>(ttlGmes)*100;
        //avgRnds = static_cast<float>(ttlRnds)/ttlGmes;
        
        // checks maximum number of games has NOT been played
        if(ttlGmes<maxGmes){

            cout << "\nTotal # Games Played = " << ttlGmes << endl;
            cout << nGmsLft << " of " << maxGmes << " max games left.\n";
            //cout << "Total # of rounds played: " << ttlRnds << endl;
            cout << "Play again? ";
            cin >> ans;

            // conditional validates user's input
            ready=isReady(ans);
            
            if(ready){                
                rBanner(ttlRnds, true);
                cout << endl << endl;                
            } else {
                cout << "\nThanks for playing!\n";               
                scoresMsg(ttlGmes, ttlRnds, avg1, avg2, avgRnds);
            }      
        } else { // display end of game results
           
            cout << "Max number of games has been reached.";
            scoresMsg(ttlGmes, ttlRnds, avg1, avg2, avgRnds);

            // reassign ans so it will end the do..while()
            ans = 'n';
        }        
        
      // continue doing all the statements above until 
      // ans does not equal y or Y
    } while((ans=='y')||(ans=='Y'));   

    // write scores and averages to file
    outFile << fixed << showpoint << setprecision(2);
    outFile << "Player 1 wins: " << p1Win << endl
            << "Player 2 wins: " << p2Win << endl
            << ttlGmes << " of " << maxGmes << " max games were played.\n"    
            << "Player 1 won ceil(" << avg1 << ")% = " 
            << ceil(avg1) << endl
            << "Player 2 won ceil(" << avg2 << ")% = " 
            << ceil(avg2) << endl;
        
    // close file being read in
    inFile.close();

    // close scores.txt file
    outFile.close();

    // exit code
    return 0;
}

//*********************************************************************
//******************* FUNCTION DEFINITIONS ****************************
//*********************************************************************

// 


// save player 1 and all of player 2's names to a new array
void copyAdd(string p2Names[],const int SIZE7, string names[], const int SIZE8, string p1Name){
   
   // copy all of player 2's name into a new array 
   for(int i=0;i<SIZE7;i++){
       names[i]=p2Names[i];
   }
   
   // calculate the last index for names[]
   unsigned int last = SIZE8-1;
   
   // add player 1's name to the end of the names[]
   names[last]=p1Name;      
}

// display instructions to player
void instruc(string player, const int MAX, int min){
    
    cout << setw(2) << " " << "Try to guess the location of \n"
         << setw(6) << " " << "your opponent\'s ship." << endl
         << endl << setw(12)<< " " << player  << endl 
         << "Guess a number between " << min << " and " << MAX << endl;
}

// validates user's input
bool isReady(char ans){
    // conditional validates user's input
    if(ans=='y'){                
        return true;
    } else if(ans=='Y'){                
        return true;
    } else return false;            
}

// changes string to all capital letters
void upper(string &name){
    char ch;
    string temp="";
    
    for(int i=0;i<name.length();i++){
        ch = toupper(name[i]);
        temp +=ch;
    }
    name=temp;
}

// get player 1's name
void getName(string &name1){   
    
    cout << "\n Player 1: Enter your name ";
    cin >> name1; 
    cin.ignore();
    
    // call function to convert user input into capital letters
    upper(name1);
}

// randomly picks a name from an array as player 2's name
string pickP2(string p2Names[], int SIZE7){
    
    cout << "\nLocating your opponent online......\n";    
    string name2=p2Names[rand()%(SIZE7)]; 
    //cout << "name2 = " << name2 << endl;
    return name2;
}

// displays each players scores and win average
void scoresMsg(int ttlGmes, int ttlRnds, float avg1, float avg2, float avgRnds){
    
    cout << fixed << showpoint << setprecision(2); 
                cout << "\nAverages for " << ttlGmes << " games \n"
                     //<< "Total # of rounds played: " << ttlRnds << endl
                     << "Player 1 won ceil(" << avg1 << ")% = " 
                     << ceil(avg1) << endl
                     << "Player 2 won ceil(" << avg2 << ")% = " 
                     << ceil(avg2) << endl;
            /*    cout << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                     << ceil(avgRnds) << endl;
             * */
}

// display scoreboard banner
void sBanner(string str, string p1Name, string p2Name, int p1Win, int p2Win){
    
    // Display scoreboard banner       
        for(int k=0; k<=2; k++){
            ((k==0)||(k==2)) ? cout << "********************************\n"
                    : (k==1) ? cout << setw(21) << str << endl
                    : cout << "Error in scoreboard banner.\n";
        }
        cout << setw(4) << " " << p1Name << setw(4) << "vs" << setw(3) << " " 
             << right << p2Name << endl;
        cout << setw(8) << p1Win << setw(16) << p2Win << endl;
}

// banner displays round number
void rBanner(int &ttlRnds, bool isReset){
    
    // declare static variable inside function
    static int r=1;    
    if(isReset) r=1;
    else {
        cout << endl << setw(26) << "********************************" << endl;
        cout << setw(18) << "Round " << r << endl;
        cout << setw(26) << "********************************" << endl;
        r++;
    }          
}

// displays game's name and instructions in a banner
void banner(string str){
    
    // reassign variables value
    str="BATTLESHIP"; 
    
    for(int i=0; i<=2; i++){
            switch(i){  // print a border or string depending on i
                case 0:
                case 2: {
                    for(int j=0; j<32; j++){
                        cout << "*";
                    }
                    cout << endl;
                    break;
                } case 1:{
                    cout << setw(21) << str << endl;
                    break;
                } default: {
                    cout << "Error in game banner.\n";
                    //exit(EXIT_SUCCESS);
                }
            }
        }        
}

// display hit message when player guesses correctly
void hitMiss(int guess, int shipLoc){
    const string HIT = "It\'s a HIT!\n";
    cout << setw(13) << guess << " == " << shipLoc << endl;
    cout << setw(23) << HIT << endl;
}

// display miss message when player makes incorrect guess
void hitMiss(int guess){
    cout << setw(15) << guess << endl;
    cout << setw(23) << "It\'s a MISS!\n";
}

// display try again message when both player's guessed wrong
void dblMiss(){
    cout << endl << "You Both Missed. Try Again..." << endl << endl;
}