#include "randomPlayer.h"
#include <cstdlib>

int randomPlayer::chooseMove(board& gameBoard){
    vector<int> legalMoves = gameBoard.getOpenSquares();

    int movesSize = legalMoves.size();
    return legalMoves[std::rand() % movesSize];
}