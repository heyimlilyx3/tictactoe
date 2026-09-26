#include "singleMovePlayer.h"
#include <cstdlib>

int singleMovePlayer::chooseMove(board& gameBoard){
    vector<int> legalMoves = gameBoard.getOpenSquares();
    for(int move: legalMoves){
        if(checkIfMoveWins(gameBoard, move)){
            return move;
        }
    }

    int movesSize = legalMoves.size();
    return legalMoves[std::rand() % movesSize];
}

bool singleMovePlayer::checkIfMoveWins(board& gameBoard, int move){

    board tempGameBoard = gameBoard;

    tempGameBoard.playMove(true, move);
    if(tempGameBoard.checkIsWon()){
        return true;
    }
    tempGameBoard = gameBoard;
    tempGameBoard.playMove(false, move);
    if(tempGameBoard.checkIsWon()){
        return true;
    }

    return false;
}