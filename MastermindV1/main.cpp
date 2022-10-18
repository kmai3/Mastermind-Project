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
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution of Code Begins here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    const int ROW=1, COL=8;
    //Declare all variables for this function
    int board[ROW][COL];
    int temp=0;
    //Initialize all known variables
    for(int i=0; i<ROW; i++){
        board[i][0]=0; // white
        board[i][1]=1; // Black
        board[i][2]=2; // Red
        board[i][3]=3; // Blue
        board[i][4]=4; // Green
        board[i][5]=5; // Yellow
        board[i][6]=6; // Brown
        board[i][7]=7; // Orange
        for(int j=0; j<COL*2; j++){
            int swap1=0, swap2=0;
            while(swap1==swap2){
                swap1= rand() % 8;
                swap2= rand() % 8;
            }
            temp=board[i][swap1];
            board[i][swap1]=board[i][swap2];
            board[i][swap2]=temp;
        }
        
    }
    
    //Testing the board generator
    for(int i=0; i<ROW; i++){
      for(int j=0; j<COL; j++){
          cout<<board[i][j];
      }
      cout<<endl;
    }
    //Display the Inputs/Outputs
    
    //Clean up the code, close files, deallocate memory, etc...
    //Exit stage right
    return 0;
}