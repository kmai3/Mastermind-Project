/* 
 * File:   main.cpp
 * Author: 
 * Created on June 23, 2020, 8:39 AM
 * Purpose: Template which is to be copied
 */
#include <iostream> //I/O Library
#include <cstdlib>  //Random Function
#include <ctime>  //Time to set the random seed
#include <iomanip> //setw
#include <cmath> // For sqrt and pow functions
#include <String>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int *createb(const int);
bool game(int *, const int);
int *dpboard(const int);
//Execution of Code Begins here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    const int COL=8;
    string useri, work="Yes";
    //Putting something in main is lazy, but is not part of the class
    //Then again technically even functions are lazy because putting everything
    //In classes is and will look better
    cout<<"No Duplicates is disabled by default, do you want to enable duplicates, type Yes"<<endl;
    cout<<"Case Sensitive"<<endl;
    cin>>useri;
    int *test=(useri==work)? dpboard(COL):createb(COL);
    if (game(test, COL)){
        cout<<"Congrats you Beat the game" << endl;
    }else{
        cout<<"You failed better luck next time"<<endl;
    }
    //Clean up the code, close files, deallocate memory, etc...
    //Exit stage right
    return 0;
}
// No Duplicates Board
int *createb(const int COL){ 
    int *board;
    int temp=0;
    string useri;
    string work = "No";
    //Initialize all known variables
        board=new int[COL];
        board[0]=0; // white
        board[1]=1; // Black
        board[2]=2; // Red
        board[3]=3; // Blue
        board[4]=4; // Green
        board[5]=5; // Yellow
        board[6]=6; // Brown
        board[7]=7; // Orange
        //Randomizer, change COL*2 to any number to maximize randomization
        for(int j=0; j<COL*2; j++){
            int swap1=0, swap2=0;
            while(swap1==swap2){
                swap1= rand() % 8;
                swap2= rand() % 8;
            }
            temp=board[swap1];
            board[swap1]=board[swap2];
            board[swap2]=temp;
        }
    //Gives answers, for testing, will help in grading. 
    cout<<"Do you want to enable cheat mode?[See the Answers]"<<endl;
    cout<<"Default Yes, Type No if you want to disable"<< endl;
    cin>>useri;
    cout<<endl;
    if(useri == work){
        return board;
    }
    for(int j=0; j<COL; j++){
        cout<<board[j];
    }
    cout<<endl;
    return board;
}
// Allows duplicate colors boards
int *dpboard(const int COL){
    int *board;
    board=new int[COL];
    for(int i=0; i<COL; i++){
        board[i]= rand () % 8;
    }
    return board;
}
bool game(int *board, const int MAX){
    int rounds=0;
    // this is lazy COL should not be capitalize 
    int COL=MAX+10;
    //Userinput how big the sequence is
    while(COL>MAX){
        cout<<"Input a number smaller than "<<MAX<<endl;
        cout<<"This will be your sequence size"<<endl;
        cin>>COL;
    }
    bool solved=false;
    int useri[COL];
    unsigned short result[COL];
    unsigned short check=0;
    unsigned short blank=0, red=0, white=0;
    string stemp;
    while(rounds<10){
        //Need to declare at 0 to refresh board state
        blank=0, red=0, white=0;
        check=0;
        //Ran 4 times because that is size of a Colm
        for(int i=0; i<COL; i++){
            cout<<"What occupies the spot, Anything that isn't the input is error of course.... Rounds:"<<rounds+1<<" ?"<<endl;
            cout<<"Enter 0 for White"<< endl;
            cout<<"Enter 1 for Black"<< endl;
            cout<<"Enter 2 for Red"<< endl;
            cout<<"Enter 3 for Blue"<< endl;
            cout<<"Enter 4 for Green"<< endl;
            cout<<"Enter 5 for Yellow"<< endl;
            cout<<"Enter 6 for Brown"<< endl;
            cout<<"Enter 7 for Orange"<< endl;
            cin>>useri[i];
        }
        for(int i=0; i<COL; i++){
            for(int j=0; j<COL; j++){
                // 0 is nothing
                // 1 is color existed in sequence
                if((useri[i]==board[j])){
                    result[i]=1;
                    j=COL-1;
                }else{
                    result[i]=0;
                }
            }
            // if color and placement matches changes color to 2
            if(useri[i]==board[i]){
                // 2 is matching color and position
                result[i]=2;
            }
        }
        //checks if player wins
        for(int i=0; i<COL; i++){
            check+=result[i];
        }
        for(int i=0; i<COL; i++){
            if(result[i] == 0){
                blank+=1;
            }
            if(result[i] == 1){
                white+=1;
            }
            if(result[i] == 2){
                red+=1;
            }
        }
        //front end
        cout<<"Round 1: ";
        for(int i=0; i<COL; i++){
            stemp=(useri[i]==0) ? "[White] ": (useri[i]==1) ? "[Black] ": 
                (useri[i]==3) ? "[Red] ": (useri[i]==2) ? "[Blue] ":
                (useri[i]==4) ? "[Green] ": (useri[i]==5) ? "[Yellow] ":
                (useri[i]==6) ? "[Brown] ": (useri[i]==7) ? "[Orange] ": 
                "[Error] ";
            cout<<stemp;
        }
        cout<<"| Blank: "<< blank << " |";
        cout<<"Red: "<< red << " |";
        cout<<"White: " << white;
        cout<<endl;
        if(check==2*COL){ 
            //if you win
            solved=true;
            return solved;
        }
    }
    //Adds round at the end
    rounds+=1;
    return solved;
}