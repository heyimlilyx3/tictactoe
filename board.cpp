#include "board.h"
#include <iostream>

using namespace std;

// bool isWonByX;

board::board() : boolBoard(2, vector<bool>(9, false)) {}

void board::playMove(bool isX, int where){
    if(where < 0 || where > 8){
        cout << "Error: Invalid move, must be 0-9" << endl;
    }else if(boolBoard[0][where] || boolBoard[1][where]){
        cout << "Error: Cannot make move, location " << where << " already occupied" << endl;
    }else if(isX){
        boolBoard[0][where] = true;
    }else{
        boolBoard[1][where] = true;
    }


}

bool board::checkIsWon(){
    for(int i = 0; i < 2; i++){
        vector<bool> b = boolBoard[i];

        if( b[0] && b[1] && b[2] || //check rows
            b[3] && b[4] && b[5] ||
            b[6] && b[7] && b[8] ||

            b[0] && b[3] && b[6] || //check columns
            b[1] && b[4] && b[7] ||
            b[2] && b[5] && b[8] || 

            b[0] && b[4] && b[8] || //check diags
            b[2] && b[4] && b[6]
        ){
            if(i == 0){
                isWonByX = true;
            }else{
                isWonByO = true;
            }
            return true;
        }
    }
    return false;
}

vector<int> board::getOpenSquares(){
    vector<int> output;
    for(int i = 0; i < 9; i++){
        if(!boolBoard[0][i] && !boolBoard[1][i]){
            output.push_back(i);
        }
    }
    return output;
}

void board::printSquare(int i){
    vector<bool> boardX = boolBoard[0];
    vector<bool> boardO = boolBoard[1];

    if(boardX[i]){
        cout << "X";
    }else if(boardO[i]){
        cout << "O";
    }else{
        cout << " ";
    }
}

void board::printBoard() {
    vector<bool> boardX = boolBoard[0];
    vector<bool> boardO = boolBoard[1];
    // cout << "Printing Board:" << endl;
    for(int i = 0; i < 3; i++){
        //print position 0
        printSquare(0+(i*3));
        cout << " | ";
        printSquare(1+(i*3));
        cout << " | ";
        printSquare(2+(i*3));
        if(i<2)
            cout << "\n_________\n";
    }

    // cout << "boolBoard[0][0]: " << boolBoard[0][0];

    cout << endl << endl;

    // cout << "X | O | X" << endl;
    // cout << "_________" << endl;
    // cout << "O |   | X" << endl;
    // cout << "_________" << endl;
    // cout << "X | O | O" << endl;
    // cout << endl;
}