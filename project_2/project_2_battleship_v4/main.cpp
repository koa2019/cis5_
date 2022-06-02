/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June1, 2022,  3:00 PM
 * Purpose: Project 2. Covers chapters 1-9 in Gaddis. 
 * Version 4: generate player's guess randomly and compare to board[][]
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
void fileSum(int,int,int,int);
void getName(string &);  // get player 1's name using pass by reference

void hitMiss(int,int);  // hit message for correct guess
void hitMiss(int);      // possible overload () with hitMsg()
void dblMiss();        // try again message
void instruc(string, const int, int =1); // instructions for players
bool isReady(char);   // returns bool value
string pickP2(string [],int);  // randomly picks a number for player 2
void print2DArr(const char [][8], const char [][8],
                const char [][8],const char [][8],const int,const int,int,int);
void print(string []);
void rBanner(int &, bool);      // display the round number
void sBanner(string,string,string,int,int);   // display scoreboard banner
void sortSel(string [], int );      // selection sort
void scoresMsg( int, int,int);  // displays number of games played and how many are left minus maxGames
void scoresMsg(int,int,float,float,float);  // displays scores for both players
void showStatic();
void sortBub(string [], int);       // sort names
void swap1(string &, string &);
void upper(string &); // changes string to all uppercase letters


// Program execution begins here
int main(int argc, char** argv) {

    // set random number seed
    srand(static_cast<unsigned int>(time(0)));

    // declare variables
    ifstream     inFile;
    ifstream     inFile1; // for reading an existing file
    ifstream     inFile2;
    ofstream     outFile; // for outputting to a file

    const int    MIN = 1, // minimum number for rand()
                 MAX = 16; // maximum number for rand()
    const int    SIZE7 = 7,  // size for player 2 names array
                 SIZE8 = 8;
    const int    ROWS = 2,
                 COLS = 8;   // number of cols in 2D array
    const int    SIZE17=17;    // choice array size
    
    bool         p1_crrt, // player 1 correct
                 p2_crrt, // player 2 correct
                 ready;   // ready to continue playing
    
    char         ans, // answer  
                 ch,
                 rowIndx = 0,// index for comparing player's guess to their opponent's board
                 colIndx = 0; // index for comparing player's guess to their opponent's board 
    int          maxGmes = 0, // number of games
                 nGmsLft,     // number of games left       
                 round = 0, // round
                 p1Guess, // player 1 guess
                 p2Guess, // player 2 guess
                 p1Ship1, // player 1 ship number 1
                 p2Ship1, // player 2 ship number 1
                 p1Win = 0, // number of wins player 1 has
                 p2Win = 0, // number of wins player 2 has
                 ttlGmes = 0,   // sum of both players number of wins
                 ttlRnds = 0;   // sum of total rounds played
    int          p1GShps,
                 p2GShps;
    int numShp1, numShp2, count1, count2;
    
    float        avg1, // average number of wins for player 1
                 avg2, // average number of wins for player 2
                 avgRnds;   // average rounds it takes to win
    
    string       p1Name = " ", 
                 p2Name = " ";
                
    char         board1[ROWS][COLS]={};
    char         board2[ROWS][COLS]={};
    char         guessP1[ROWS][COLS]={};
    char         guessP2[ROWS][COLS]={};
    
    // will be used to fill each player's guess[][]
    char choices[SIZE17]={'B','B','B','B','B','B','S','B','B','B','S','B','S','B','B','B','S'};
    string p2Names[SIZE7]={"MIKE", "BART", "JANIS", "STEPHANIE", "TING", "VICTOR", "JILLIAN"};
    
    
    
    // ***************************************
    // ****** SET UP GAME STARTS HERE ********
    // ***************************************
    
    
    
    // open an existing file that holds max number of games a user can play
    inFile.open("maxNGms.txt");
    inFile1.open("board1.txt",ios::in);   
    inFile2.open("board2.txt",ios::in);
    outFile.open("scores.txt");  // create a file to output to
   
    // read in maximum number of games that can be played from file
    inFile >> maxGmes;
    nGmsLft = maxGmes;  // set numberOfGamesLeft to equal maxGames
    
    
    // initialize counters to zero      
    numShp1=numShp2=count1=count2=0;

    // read in data from file and initialize each player's game board[][]
    // with a S(ship) or a B(blank)   
    for(int nRows=0; nRows<ROWS; nRows++){
        for(int nCols=0; nCols< COLS ;nCols++){
            
            inFile1 >> board1[nRows][nCols];   
            if(board1[nRows][nCols]=='S') { 
                numShp1++;  // count how many ships player 1 has in their array
            }
            count1++;   // count how many items were read in
            inFile2 >> board2[nRows][nCols];
            if(board2[nRows][nCols]=='S'){
                numShp2++;  // count how many ships player 1 has in their array
            }
            count2++;   // count how many items were read in
        }        
    }     
    
    
    // randomly fill guess[][] until at least one of the player's has 3 ships in their array
    p1GShps=p2GShps=0;  // initialize both players number of ships to zero
    bool minMet;        // minimum number of ships==3

    do{
        minMet=false;   // set flag

        for(int gRow=0; gRow<ROWS; gRow++){
            for(int gCol=0; gCol<COLS; gCol++){

                // automatically set player 1's guess[][] randomly from choices[] 
                guessP1[gRow][gCol]=choices[rand()%SIZE17]; // saves either a 'S' or 'B' 

                // track how many ships player 1's array has
                if(guessP1[gRow][gCol]=='S'){
                    p1GShps++; 
                    //cout <<"p1= " <<  p1GShps << " ";
                    if(p1GShps==3) minMet=true;   // reasign value to flag                       
                }

                // automatically set player 2's guess[][] randomly from choices[] 
                guessP2[gRow][gCol]=choices[rand()%SIZE17]; 

                // track how many ships player 1's array has
                if(guessP2[gRow][gCol]=='S'){
                    p2GShps++; 
                    //cout << "p2= " << p2GShps<< " ";
                    if(p2GShps==3) minMet=true; 
                }
            }        
            //cout << endl;
        }
        //cout << "Total gShips " << setw(8) << right << p1GShps << "\t \t " << p2GShps << "\n";
        //if((p1GShps>3) || (p2GShps>3)){
           // cout << "minimum # ships met. Should exit do while()\n";
            //p1GShps=p2GShps=0;
            //minMet=true;
        //}
    } while(!minMet);       

     // ask for player 1's name
    getName(p1Name); 
    
    do {
    // prompt user    
    cout << endl << p1Name << " your game has successfully loaded. \n"
         << "Press 1 to see a summary of the files that were read.\n"
         << "Press 2 to confirm my game board[][] was read the data in correctly\n"
         << "        and to that the guess[][] were randomly filled.\n"
         << "Press 3 to start your game.\n"
         << "Press 4 to exit.\n";
    cin  >> ch;
    
    switch(ch){
        case '1': fileSum(count1,count2,numShp1,numShp2); break;
        case '2': print2DArr(guessP1, guessP2,board1,board2,ROWS,COLS,p1GShps,p2GShps); break;       
        case '4':  exit(EXIT_SUCCESS); break;
        default: cout << setw(9)<< " " << "Loading.......\n";
    }
    
    if(ch=='1' || ch=='2'){
    
    cout << "Run Menu again?\n";
    cin >> ans;
    } else ans='n';
    
    // continue doing all the statements above until 
    // ans does not equal y or Y
    } while((ans=='y')||(ans=='Y')); 
    
    // display game's introduction message
    string gameNme = "BATTLE";
    banner(gameNme);  
    
    // get player 2's name from an array of names
    p2Name = pickP2(p2Names,SIZE7);
    cout << setw(12) << p1Name << " vs " << p2Name << "!" << endl;

    cout << "\nPress any key to begin. ";
    cin.ignore();
    cin.get();   // pause screen before game starts
        
    //***************************************
    //******** GAME STARTS HERE**************
    //***************************************
    
   
    do { // game starts here
                
        // sets games flag variables to their default starting values
        p1_crrt = p2_crrt = false;     
 
        // loops until a player correctly guesses opponents ship location
        while((!p1_crrt) && (!p2_crrt)){
            
//cout << "round = " << round;
            rBanner(round, false);
            
            //*************** Player 1's Guess ************* 
            //**********************************************
            // display instructions to player 1
            instruc(p1Name, MAX);                
            
            // program generates random number guess
            //p1Guess = rand()%(MAX-MIN)+MIN;

            // checks if player1 guess is correct
            //if(p1Guess == p2Ship1){                 
            if(guessP1[rowIndx][colIndx]==board2[rowIndx][colIndx]){
            
                numShp2--;  // decrease number of ships player 2 has left

                // increment player 1 number of wins                            
                p1Win++;
                
                // display HIT message for correct guess
                hitMiss(p1Guess, p2Ship1);  
                
                if(numShp2==0){
                    
                    nGmsLft--;  // decrease number of total games
                    
                    p1_crrt = true;   // reassign player 1's value for a correct guess                          
                }
                                                                   
              // else conditional when player 1 guess is wrong  
            } else hitMiss(p1Guess); // display MISS message for wrong guess

            // conditional only runs if player 1 misses player 2's ship
            if(!p1_crrt){

                
                //**********************************************
                //*************** Player 2's Guess *************
                //**********************************************                
                
                instruc(p2Name, MAX);  // display instructions to player 2                

                // conditional checks if player 2's guess is correct
                // program automatically generated  guess for player 2                           
                if(guessP2[rowIndx][colIndx]==board1[rowIndx][colIndx]){
                            
                    numShp1--;  // decrement number of ships player 1 has                    
                     
                    p2Win++; //    increment player 2 number of wins
                    
                    // display HIT message for correct guess  
                    hitMiss(p2Guess, p1Ship1);
                    
                    if(numShp1==0){
                    
                        nGmsLft--;  // decrease number of total games

                        p2_crrt = true;   // reassign player 1's value for a correct guess                          
                    }
                    
                  // else conditional when player 2 guess is wrong  
                } else hitMiss(p2Guess); // display MISS message for player 2's wrong guess  
                
            } // ends player 2's turn
            
            
   //cout << "round before ++ = " << round << endl;
    //round++;
    //cout << "round++ = " << round << endl;
            
            
            // if both players guess wrong, then increment round by 1
            // and display message to tell them to continue guessing 
            if((!p1_crrt) && (!p2_crrt)){
                
                // increment index that compare guess[][]to board[][]
                rowIndx++;
                colIndx++;
                
                // display try again message when both players guess wrong
                dblMiss();
            }
        } // ends while(!p1_crrt) && (!p2_crrt)

        // One of the player's has sunk all of their opponents ships, so
        // call function to display both player's scores
        sBanner("SCOREBOARD", p1Name, p2Name, p1Win, p2Win);        
//cout << "ttlrounds = " << ttlRnds << endl;
//cout << "rounds = " << round << endl;
        // calculate total number of games won & number rounds played
        ttlGmes = p1Win+p2Win;
        ttlRnds += round; // sums the total number of rounds from all games
//cout << "ttlRnds+=round = " << ttlRnds << endl;
        // calculates each players percentage of winning
        avg1 = p1Win/static_cast<float>(ttlGmes)*100;
        avg2 = p2Win/static_cast<float>(ttlGmes)*100;
        avgRnds = static_cast<float>(ttlRnds)/ttlGmes;
        
        // checks maximum number of games has NOT been played
        if(ttlGmes<maxGmes){

            scoresMsg(nGmsLft,maxGmes,ttlRnds);
            
            cout << "Play again? ";
            cin >> ans;

            // conditional validates user's input
            ready=isReady(ans);
            
            if(ready){     
//cout << "ready round = " << round << endl;
                rBanner(round, true);
                cout << endl << endl; 
                rowIndx=colIndx=0;  // resets index for guess[][]
            } else {
                cout << "\nThanks for playing!\n";               
                scoresMsg(ttlGmes, ttlRnds, avg1, avg2, avgRnds);   // displays player's averages
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

    
/*    
    // sort names
    // create new array to hold player 1 & player 2's names
   string names[SIZE8]={};
   
   // copy contents of one array to another array and add player1's name
   copyAdd(p2Names,SIZE7,names,SIZE8,p1Name);
   
   // print names array
   cout << "\nThis week's Top Players \n";
   print(names);
   
   // bubble sort names & print sorted array
   sortBub(names,SIZE8);
   cout << "Bubble Sort: Top Player's \n";
   print(names);
   
   // selection sort
   sortSel(names,SIZE8);
    
    // write scores and averages to file
    outFile << fixed << showpoint << setprecision(2);
    outFile << "Player 1 wins: " << p1Win << endl
            << "Player 2 wins: " << p2Win << endl
            << ttlGmes << " of " << maxGmes << " max games were played.\n"    
            << "Player 1 won ceil(" << avg1 << ")% = " 
            << ceil(avg1) << endl
            << "Player 2 won ceil(" << avg2 << ")% = " 
            << ceil(avg2) << endl;
*/    
    
    
    // close files being read in and written to
    inFile.close();
    inFile1.close();
    inFile2.close();    
    outFile.close();   

    // exit code
    return 0;
}


//*********************************************************************
//******************* FUNCTION DEFINITIONS ****************************
//*********************************************************************

// print array
void print(string arr[]){
    //cout << endl;
    for(int i=0;i<8;i++){
        cout << i+1 << ". " << arr[i] << endl;
    }
    cout << endl;
}

// selection sort
void sortSel(string names[], int SIZE8){
    
    string rNames[SIZE8]={"VICTOR", "DANI", "STEPHANIE", "MIKE", "BART", "JANIS", "MICHELLE", "JILLIAN"};   
    
    cout << "\nLast Week's Top Players \n";
    print(rNames);
    
    int    minIndx; 
    string minVal;    
    int last = SIZE8-1; // don't need to go the last index cause we check it by the end of loop's 1st run
    
    for(int start=0; start<last; start++){
        
        minIndx = start; // set smallest index to zero
        minVal=rNames[start]; // set smallest value to array's 1st index
        
        // start loop at array's[1]
        for( int indx=(start+1); indx<SIZE8; indx++){            
        
            // if its neighbor index is smaller than it
            if(rNames[indx] < minVal){ 
                
                // reassign smallest to that array's index and its value
                minVal = rNames[indx];
                minIndx = indx;
            }  
        } // swap their values
        swap1(rNames[minIndx], rNames[start]);
    }
    
    cout << "\nSelection Sort: Last Week's Top Players \n";
    print(rNames);
}

// bubble sort. compare neighboring indices one at a time
void sortBub(string names[], int size){
    
    bool swap;
    int maxElmt=size-1; // (8-1)=7. holds subscript of last element that will be compared to its neighbor
    
    do {
        swap=false; // set flag
        
        // loop 0 thru 7
        for(int i=0;i<maxElmt;i++){
            if(names[i] > names[i+1]){ // "VICTOR" > "JILLIAN" ?
                
                // swap index values
                swap1(names[i],names[(i+1)]);
                
                // reset flag value  
                swap=true;                           
            }
        }       
        maxElmt--; // decrement. biggest value is at last index, so now restart loop to run to one less last index
    } while(swap); // while there's still indices to left to swap
}

// swap indices
void swap1(string &a, string &b){
    
    string temp;
    temp=a;
    a=b;
    b=temp;
}

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
    
    cout << "\nPlayer 1: Enter your name ";
    cin >> name1; 
    cout << endl;
    // call function to convert user input into capital letters
    upper(name1);
}

// randomly picks a name from an array as player 2's name
string pickP2(string p2Names[], int SIZE7){
    
    cout << "\nLocating your opponent online......\n";    
    string name2=p2Names[rand()%(SIZE7)];     
    return name2;
}

// displays each players scores and win average
void scoresMsg(int ttlGmes, int ttlRnds, float avg1, float avg2, float avgRnds){
    
    cout << fixed << showpoint << setprecision(2); 
                cout << "\nAverages for " << ttlGmes << " games \n"
                     << "Total # of rounds played: " << ttlRnds << endl
                     << "Player 1 won ceil(" << avg1 << ")% = " 
                     << ceil(avg1) << endl
                     << "Player 2 won ceil(" << avg2 << ")% = " 
                     << ceil(avg2) << endl
                     << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                     << ceil(avgRnds) << endl;
}

// displays total number of games played and number of games left
void scoresMsg(int nGmsLft, int maxGmes, int ttlRnds){
    
    showStatic(); // show how many games have been played
    cout << nGmsLft << " of " << maxGmes << " max games left.\n";
    cout << "Total # of rounds played: " << ttlRnds << endl;
}

// static variable for games
void showStatic(){
    static int games=1;
    cout << "\nTotal # Games Played = " << games << endl;
    games++;
}

// display scoreboard banner
void sBanner(string str, string p1Name, string p2Name, int p1Win, int p2Win){
    
    // Display scoreboard banner       
        for(int k=0; k<=2; k++){
            ((k==0)||(k==2)) ? cout << "********************************\n"
                    : (k==1) ? cout << setw(21) << str << endl
                    : cout << "Error in scoreboard banner.\n";
        }
        cout << setw(7) << " " << p1Name << setw(4) << "vs" << setw(3) << " " 
             << right << p2Name << endl;
        cout << setw(8) << p1Win << setw(16) << p2Win << endl;
}

// banner displays round number
void rBanner(int  &r, bool isReset){
    
    // declare static variable inside function
    //static int r=1;    
    if(isReset) r=1;
    else {
        cout << endl << setw(26) << "********************************" << endl;
        cout << setw(18) << "Round " << r+1 << endl;
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

// 
void fileSum(int count1, int count2, int numShp1, int numShp2){
   
    // confirm data that was read in is even and contains at least 3 ships
    cout << endl << setw(3)<<" " << "Read in " << setw(6)<< " " << "P1 Board" << setw(5)<< " "<< "P2 Board" << endl;
    cout << "Total # chars " << setw(8) << right << count1 << "\t \t" << count2 << "\n";
    cout << "Total # ships " << setw(8) << right << numShp1 << "\t \t" << numShp2 << "\n\n";
    
}

// 
void print2DArr(const char guessP1[][8], const char guessP2[][8],
                const char board1[][8],const char board2[][8], 
                const int ROWS,const int COLS, int p1GShps, int p2GShps){
 
    // display data from both players guess arrays
    cout << "\nConfirming Guess arrays are random and have at least 3 S in each array\n";
    cout << setw(4) << " " << "P1 Guesses" << "\t \t" << setw(4) << " " << "P2 Guesses\n";
    for(int pRows=0; pRows<ROWS; pRows++){
        for(int pCols=0; pCols<COLS; pCols++){
            cout << guessP1[pRows][pCols] << " ";           
        } 
        cout << "\t";
        for(int pCols=0; pCols<COLS; pCols++){
            cout << guessP2[pRows][pCols] << " ";           
        }   
        cout << endl;
    } 
    cout <<"P1 # Ships : " << p1GShps 
         << setw(10) << " " <<  "P2 # Ships : " << p2GShps << endl<<endl <<endl;
    
    
    // compares player 1's board[][] to player 2's guess[][] and vice versa
    cout << setw(4) << " " << "P1 Guessing P2 Ship " << "\t \t " 
         << setw(4) << " " << "P2 Guessing P1 Ship \n";
    
    for(int pRows=0; pRows<ROWS; pRows++){
        
        cout << "Guess P1  Row:"<< pRows << "  ";
        for(int pCols=0; pCols<COLS; pCols++){
            cout << guessP1[pRows][pCols] << " ";           
        } 
          
        cout << "\t";
        cout << "Guess P2  Row:"<< pRows  << "  ";
        for(int pCols=0; pCols<COLS; pCols++){
            cout << guessP2[pRows][pCols] << " ";           
        } 
        
        cout << endl;
        cout << "Board P2  Row:" << pRows << "  ";
        for(int pCols=0; pCols<COLS; pCols++){
            cout << board2[pRows][pCols] << " ";           
        } 
       
        cout << "\t";
        cout << "Board P1  Row:"<< pRows << "  ";
        for(int pCols=0; pCols<COLS; pCols++){
            cout << board1[pRows][pCols] << " ";           
        }         
        cout << endl << endl;
    }  
}