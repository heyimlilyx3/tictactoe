#pragma once
#include "autoPlayer.h"

class singleMovePlayer : public autoPlayer {
public:
    int chooseMove(board& gameBoard) override;
private:
    bool checkIfMoveWins(board&gameBoard, int move);
};