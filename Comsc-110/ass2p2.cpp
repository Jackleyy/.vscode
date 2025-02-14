#include <iostream>
#include <iomanip>
using namespace std;

/*************************************************************************************
Decription: This program is a simple tic tac toe game that prints a board to the console.
It will check if the input is valid, take an inout (1-3) and then draw the board again
for easy tracking of turns. 
If a player wins or a tie occurs after a turn, the game will end and display the winner

Author: Justin Ackley
Class: COMSC-165
Date: 06/21/2024
Status: Complete
 
************************************************************************************/


//prototypes
void p1turn(char[][3]);
void p2turn(char[][3]);
void printBoard(char[][3]);
void checkWin(char);
char checkWinner(char[][3]);


int main(){
    //intializing the board
    char board[3][3] = { {'*', '*', '*'},
                         {'*', '*', '*'},
                         {'*', '*', '*'} };

    char winner = ' ';
    printBoard(board);

    //As long as a tie or win has not occurred, the program will continue
    while (checkWinner(board) == '*') {
        // Player 1's turn
        p1turn(board);
        printBoard(board);
        checkWin(checkWinner(board));

        //checking if player 1 won
        if (checkWinner(board) == 'X'){
            break;
        }

        //Check if a tie occured
        if (checkWinner(board) == ' '){
            break;
        }
        // Player 2's turn
        p2turn(board);
        printBoard(board);
        checkWin(checkWinner(board));
    }


    return 0;
}

void printBoard(char board[][3]){
    //going through the 2d array and printing the contents as well as borders to make a board
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "| " << board[i][j] << " | ";
        }
        cout << "\n";
    }
    cout << "\n" ;
}


//using 2 different functions for each player bc of the recursion in each function
//Asks for input, puts an X at that spot making sure the spot isn't taken
void p1turn(char board[][3]){
    int row, column;

     //Will check if the input is valid. must be an integer and between 1-3
    while (true) {
        cout << "\nWhich row would you like player 1? ";
        cin >> row;
        if (cin.fail() || row < 1 || row > 3) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "\nInvalid input. Row must be an integer between 1 and 3.\n";
            continue; 
        }
        else{
            break;
        }
    }

     //Will check if the input is valid. must be an integer and between 1-3
    while (true) {
        cout << "\nWhich column would you like player 1? ";
        cin >> column;
        if (cin.fail() || column < 1 || column > 3) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "\nInvalid input. Row must be an integer between 1 and 3.\n";
            continue; // retry the loop
        }
        else{
            break;
        }
    }

    //subtracting 1 to match the standard row and column perception
    row -= 1;
    column -= 1;

    //checking if the spot is taken, if it is the program will loop by recursion
    if(board[row][column] == '*'){
        board[row][column] = 'X';
    }
    else{
        cout << "\n\nSpot is already taken, please give another input\n\n";
        p1turn(board);
    }
}

//Asks for input, puts an X at that spot making sure the spot isn't taken
void p2turn(char board[][3]){
    int row, column;

    //Will check if the input is valid. must be an integer and between 1-3
    while (true) {
        cout << "\nWhich row would you like player 2? ";
        cin >> row;
        if (cin.fail() || row < 1 || row > 3) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "\nInvalid input. Row must be an integer between 1 and 3.\n";
            continue; // retry the loop
        }
        else{
            break;
        }
    }
    //Will check if the input is valid. must be an integer and between 1-3
    while (true) {
        cout << "\nWhich column would you like player 2? ";
        cin >> column;
        if (cin.fail() || column < 1 || column > 3) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "\nInvalid input. Row must be an integer between 1 and 3.\n";
            continue; // retry the loop
        }
        else{
            break;
        }
    }


    //subtracting 1 to match the standard row and column perception
    row -= 1;
    column -= 1;

    if(board[row][column] == '*'){
        board[row][column] = 'O';
    }
    else{
        cout << "\n\nSpot is already taken, please give another input\n\n";
        p2turn(board);
    }
}

//will check board for a win or a tie and returns a winner if so
char checkWinner(char board[3][3]) {
    // Check rows
    for(int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != '*')) {
            return board[i][0];
        }
    }

    // Check columns
    for(int j = 0; j < 3; j++) {
        if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] != '*')) {
            return board[0][j];
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != '*')) {
        return board[0][0];
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != '*')) {
        return board[0][2];
    }

    // check if board full. if it is it will return a ' ' for a tie but if its not full, it will return '*' to indicate continue
    for(int i = 0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if(board[i][j] == '*' ){
                return '*';
            }
        }
    }

    return ' ';
    
}

//will check who won and return a message
void checkWin(char winner){
    if(winner == 'X'){
        cout << "\nWinner is player 1!";
    }
    else if(winner == 'O'){
        cout << "\nWinner is player 2!";
    }
    else if(winner == ' '){
        cout << "\nIt's a tie :( ";
    }
}

    