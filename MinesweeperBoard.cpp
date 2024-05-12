#include "MinesweeperBoard.h"
#include <iostream>
#include <ctime>
#include <cmath>

MinesweeperBoard::MinesweeperBoard(){
    // tu definiujemy konstruktor
    width = 10;
    height = 10;
    state = RUNNING;
    board[width][height] = {};
    for (int kolumna = 0; kolumna < width ; kolumna++)
    {
        for (int wiersz = 0; wiersz < height ; wiersz++)
        {
            board[kolumna][wiersz].hasMine = false;
            board[kolumna][wiersz].hasFlag = false;
            board[kolumna][wiersz].isRevealed = false;
        }
    }
   // board[0][0].hasMine = true;
   // board[0][2].hasFlag = true;
   // board[0][2].hasMine = true;
    //board[1][0].isRevealed = true;

}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
        srand(time(nullptr));
        this->width = width;
        this->height = height;
        state = RUNNING;
        board[width][height] = {};
        field = width*height;
        first_move = true;
        //czyszczenie planszy
    for (int kolumna = 0; kolumna < width ; kolumna++)
    {
        for (int wiersz = 0; wiersz < height ; wiersz++)
        {
            board[kolumna][wiersz].hasMine = false;
            board[kolumna][wiersz].hasFlag = false;
            board[kolumna][wiersz].isRevealed = false;
        }
    }
        //warunki poziomow trudnosci                            //EASY MODE
        if (int count = 0; mode == EASY)
        {
            while (count < ceil(field/10))
            {
                int szer;
                int wys;
                szer = rand() % width;
                wys = rand() % height;
                if(board[szer][wys].hasMine != 0)
                    continue;
                board[szer][wys].hasMine = true;
                count++;
            }
        }
                                                                //NORMAL MODE
    if (int count = 0; mode == NORMAL)
    {
            while (count < ceil(((field/100)*20)))
            {
                int szer;
                int wys;
                szer = rand() % width;
                wys = rand() % height;
                if(board[szer][wys].hasMine != 0)
                    continue;
                board[szer][wys].hasMine = true;
                count++;
        }
    }
                                                                //HARD MODE
    if (int count = 0; mode == HARD)
    {
        while (count < ceil(((field/100)*30)))
        {
            int szer;
            int wys;
            szer = rand() % width;
            wys = rand() % height;
            if(board[szer][wys].hasMine != 0)
                continue;
            board[szer][wys].hasMine = true;
            count++;
        }
    }
                                                                //DEBUG MODE
    if (mode == DEBUG)
    {
        for(int kolumna = 0; kolumna < width; kolumna+=2)
            board[kolumna][0].hasMine = true;
        for(int wiersz = 0; wiersz < height; wiersz++)
            board[0][wiersz].hasMine = true;
        if (width > height){
            for(int przekatna = 1; przekatna < height; przekatna++)
                board[przekatna][przekatna].hasMine = true;
        }
        else{
            for (int przekatna = 1; przekatna < width; przekatna++)
                board[przekatna][przekatna].hasMine = true;
        }
    }
}
int MinesweeperBoard::getBoardWidth() const {
    return width;
}
int MinesweeperBoard::getBoardHeight() const {
    return height;
}
int MinesweeperBoard::getMineCount() const {
    int n_of_mines = 0;
    for (int kolumna = 0; kolumna < height ; kolumna++) {
        for (int wiersz = 0; wiersz < width; wiersz++)
        {
           if(board[kolumna][wiersz].hasMine == 1)
               n_of_mines++;
        }
    }
    return n_of_mines;
}
int MinesweeperBoard::countMines(int kolumna, int wiersz) const {
    int m_around = 0;
    if (board[kolumna][wiersz].isRevealed == 0 || kolumna < 0 || kolumna >= height || wiersz < 0 || wiersz >=  width)
        return -1;
    else if (board[kolumna][wiersz].isRevealed == 1)
    {
        if (board[kolumna][wiersz - 1].hasMine == 1 && (wiersz - 1) >= 0)
            m_around++;
        if (board[kolumna][wiersz + 1].hasMine == 1 && (wiersz + 1) < width)
            m_around++;
        if (board[kolumna - 1][wiersz].hasMine == 1 && (kolumna - 1) >= 0)
            m_around++;
        if (board[kolumna + 1][wiersz].hasMine == 1 && (kolumna + 1 ) < height)
            m_around++;
        if (board[kolumna - 1][wiersz - 1].hasMine == 1 && (kolumna - 1) >= 0 && (wiersz - 1) >= 0)
            m_around++;
        if (board[kolumna -1 ][wiersz + 1].hasMine == 1 && (kolumna - 1) >= 0 && (wiersz + 1) < width)
            m_around++;
        if (board[kolumna + 1][wiersz - 1].hasMine == 1 && (kolumna + 1) < height && (wiersz - 1) >= 0)
            m_around++;
        if (board[kolumna + 1][wiersz + 1].hasMine == 1 && (kolumna + 1) < height && (wiersz + 1) < width)
            m_around++;
    }
        return m_around;
}
bool MinesweeperBoard::hasFlag(int kolumna, int wiersz) const {
    if (kolumna < 0 || kolumna >= height || wiersz < 0 || wiersz >= width)
        return false;
    else if (board[kolumna][wiersz].hasFlag == 0 || board[kolumna][wiersz].isRevealed == 1)
        return false;
    else if (board[kolumna][wiersz].hasFlag == 1)
        return true;
    return false;
}
void MinesweeperBoard::toggleFlag(int kolumna, int wiersz) {

    if (kolumna < 0 || kolumna >= height || wiersz < 0 || wiersz >= width || state != RUNNING || board[kolumna][wiersz].isRevealed == 1)
        ;
    else if (board[kolumna][wiersz].hasFlag == 1 and state == RUNNING)
        board[kolumna][wiersz].hasFlag = false;
    else if (board[kolumna][wiersz].hasFlag == 0)
        board[kolumna][wiersz].hasFlag = true;

}
void MinesweeperBoard::revealField(int kolumna, int wiersz){

    if (board[kolumna][wiersz].isRevealed == 1 || board[kolumna][wiersz].hasFlag == 1 || kolumna < 0 || kolumna >= height || wiersz < 0 || wiersz >= width || state != RUNNING)
        ;
    else if (board[kolumna][wiersz].isRevealed == 0 && board[kolumna][wiersz].hasMine == 0)
    {
        board[kolumna][wiersz].isRevealed = true;
        first_move = false;
    }
    else if (board[kolumna][wiersz].isRevealed == 0 && board[kolumna][wiersz].hasMine == 1 && first_move == 1)
    {
        int count = 0;
        board[kolumna][wiersz].hasMine = false;
        board[kolumna][wiersz].isRevealed = true;
        while (count <= 1)
        {
            int szer;
            int wys;
            szer = rand() % width;
            wys = rand() % height;
            if (board[wys][szer].hasMine == 1)
                continue;
            board[wys][szer].hasMine = true;
            count++;
        }
        first_move = false;
    }
    else if (board[kolumna][wiersz].isRevealed == 0 && board[kolumna][wiersz].hasMine == 1 && first_move == 0)
    {
        board[kolumna][wiersz].isRevealed = true;
        state = FINISHED_LOSS;
    }
}

bool MinesweeperBoard::isRevealed(int kolumna, int wiersz) const
{
    if(board[kolumna][wiersz].isRevealed == 1)
        return true;
    else
        return false;
}
GameState MinesweeperBoard::getGameState() const
{
    int loss = 0;
    int unrevealed = 0;
    for (int wiersz = 0; wiersz < height; wiersz++)
    {
        for (int kolumna = 0; kolumna < width; kolumna++)
        {
            if (board[kolumna][wiersz].isRevealed == 0)
                unrevealed++;
            else if (board[kolumna][wiersz].isRevealed == 1 && board[kolumna][wiersz].hasMine == 1)
                loss = 1;
        }

    }
    if(getMineCount() == unrevealed)
        return FINISHED_WIN;
    else if (loss == 1)
        return FINISHED_LOSS;

    return RUNNING;

}
char MinesweeperBoard::getFieldInfo(int kolumna, int wiersz) const
{
    if (kolumna < 0 || kolumna > height || wiersz < 0 || wiersz >= width)
        return '#';
    else if (board[kolumna][wiersz].isRevealed == 0 && board[kolumna][wiersz].hasFlag == 1)
        return 'F';
    else if (board[kolumna][wiersz].isRevealed == 0 && board[kolumna][wiersz].hasFlag == 0)
        return '_';
    else if (board[kolumna][wiersz].isRevealed == 1 && board[kolumna][wiersz].hasMine == 1)
        return 'x';
    else if (board[kolumna][wiersz].isRevealed == 1 && countMines(kolumna, wiersz) == 0)
        return ' ';

    return (countMines(kolumna, wiersz) + 48);
}

//funkcja do sprawdzania poprawnosci wykonywanych zadan
void MinesweeperBoard::debug_display() const{
    for(int w = 0; w < width; w++){
        std::cout<<"    "<<w;
    }
    std::cout<<std::endl;
    for(int i = 0; i < height; i++) {
        std::cout<<i<<" ";
        for (int j = 0; j < width; j++) {

            if (board[i][j].hasMine == 0) {
                std::cout << "[.";
            } else
                std::cout << "[M";

            if (board[i][j].isRevealed == 0) {
                std::cout << ".";
            } else
                std::cout << "o";

            if (board[i][j].hasFlag == 0) {
                std::cout << ".]";
            } else
                std::cout << "f]";
        }
        std::cout << std::endl;
    }
    std::cout<<"Szerokosc planszy: "<<getBoardWidth()<<std::endl; //dziala
    std::cout<<"Wysokosc planszy: "<<getBoardHeight()<<std::endl;  //dziala
    std::cout<<"Liczba min: "<<getMineCount()<<std::endl;  //dziala
    std::cout<<"miny wokol pola 1, 0: "<<countMines(1,0)<<std::endl; //dziala
    std::cout<<"Czy odkryte 1, 0: "<<isRevealed(1,0)<<std::endl; //dziala
    std::cout<<"Is this field flagged? "<<hasFlag(0, 0)<<std::endl;
    std::cout<<"Current game state: "<<getGameState()<<std::endl;
    std::cout<<"this field info: "<<getFieldInfo(2,3)<<std::endl;


}

