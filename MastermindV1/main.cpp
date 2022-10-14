/* 
 * File:   main.cpp
 * Author: 
 * Created on June 23, 2020, 8:39 AM
 * Purpose: Template which is to be copied
 */
maximum gold el dorado
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
    const int ROW=10, COL=4, COLOR=1;
    //Declare all variables for this function
    int board[ROW][COL];
    int temp=0;
    //Initialize all known variables
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            board[i][j]=rand() % 8;
        }
        for(int j=0; j<COL; j++){
            while(board[i][j]==board[i][1]){
                board[i][1]=
            }
        }
    }
    //Process Inputs to Outputs -> Mapping Process 
    
    //Display the Inputs/Outputs
    
    //Clean up the code, close files, deallocate memory, etc...
    //Exit stage right
    return 0;
}