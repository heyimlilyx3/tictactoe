#pragma once
#include "board.h"

class autoPlayer{
public:
    virtual ~autoPlayer() = default;
    virtual int chooseMove(board& gameBoard) = 0;
};
