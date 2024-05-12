#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard& board) : board(board)
{
    width = board.getBoardWidth();
    height = board.getBoardHeight();
}

void MSBoardTextView::display() const
{
    std::cout<<" ";
    for(int w = 0; w < height; w++){
        std::cout<<"  "<<w;
    }
    std::cout<<std::endl;
    for(int kolumna = 0; kolumna < width; kolumna++) {
        std::cout<<kolumna<<" ";
        for (int wiersz = 0; wiersz < height; wiersz++) {
            std::cout <<"["<<board.getFieldInfo(kolumna,wiersz)<<"]";
        }
        std::cout << std::endl;
    }
}
