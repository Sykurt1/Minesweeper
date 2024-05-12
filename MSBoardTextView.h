#ifndef MINESWEEPER_MSBOARDTEXTVIEW_H
#define MINESWEEPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"
class MSBoardTextView{
    MinesweeperBoard& board;
    int width, height;
public:
    MSBoardTextView(MinesweeperBoard& board);
    void display() const;
};


#endif //MINESWEEPER_MSBOARDTEXTVIEW_H
