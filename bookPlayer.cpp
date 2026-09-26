#include "bookPlayer.h"
#include <iostream>
#include <fstream>
using namespace std;

int bookPlayer::chooseMove(board& gameBoard){
    // readMove(gameBoard);

    boardToInt(gameBoard);
    return -1;
}


int bookPlayer::readMove(board& gameBoard){
    ifstream book ("book.txt");
    if(book.is_open()){
        cout << "book is open" << endl;
    }else{
        cout << "book is not open.  Writing moves (I hope)" << endl;
        book.close();
        writeMoves();
    }
    book.close();
}

void bookPlayer::writeMoves(){
    ofstream book ("book.txt");

    // write all possible gamestates to book.txt
    // gamestates written as <bool> X to play, <int> board state, <int> best move
    // examples
    // 0, 55
    // 1, 98
}

int bookPlayer::boardToInt(board& gameBoard){
    //turns board into int base 3 (0 for blank, 1 for X, 2 for O)
    int output = 0;
    int powerOfThree = 1;
    cout << "Printing TempInt: ";
    for(int i = 0; i < 9; i++){
        int tempInt;
        if(gameBoard.boolBoard[0][i]){
            tempInt = 1;
        }else if(gameBoard.boolBoard[1][i]){
            tempInt = 2;
        }else{
            tempInt = 0;
        }
        cout << tempInt << ", ";

        output += ((powerOfThree)*tempInt);
        powerOfThree *= 3;
    }
    cout << "==> " << output << endl;

    return output;
}

vector<vector<bool>> bookPlayer::intToBoard(int input){
    vector<vector<bool>> output(2, vector<bool>(9, false));

    for(int i = 0; i < 9; i++){
        int squareValue = input % 3;
        input /= 3;

        if(squareValue == 1){
            output[0][i] = true;
        }else if(squareValue == 2){
            output[1][i] = true;
        }
    }

    return output;
}