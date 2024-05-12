#ifndef MINESWEEPER_MINESWEEPERBOARD_H
#define MINESWEEPER_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{

    Field board[100][100];
    int width;                 // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy
    GameState state;          // stan gry
    bool first_move;            // boolean do warunkowania pierwszego ruchu
    int field;
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);

    void debug_display() const;                 //used
    int getBoardWidth() const;                  //used
    int getBoardHeight() const;                 //used
    int getMineCount() const;                   //used
    int countMines(int row, int col) const;     //used
    bool hasFlag(int row, int col) const;       //used
    void toggleFlag(int row, int col);          //used
    void revealField(int row, int col);         //used
    bool isRevealed(int row, int col) const;    //used
    GameState getGameState() const;             //used
    char getFieldInfo(int row, int col) const;  //used
};



#endif //MINESWEEPER_MINESWEEPERBOARD_H
