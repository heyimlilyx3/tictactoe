#pragma once
#include "autoPlayer.h"

class randomPlayer : public autoPlayer {
public:
    int chooseMove(board& gameBoard) override;
};