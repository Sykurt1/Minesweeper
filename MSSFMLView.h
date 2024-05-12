#ifndef MINESWEEPER_MSSFMLVIEW_H
#define MINESWEEPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML\Graphics.hpp>

class MSSFMLView{
    MinesweeperBoard &board;
    int screen_width, screen_height;
    int rect_w, rect_h;
    sf::RectangleShape r1;
    sf::Texture flag, bomb;
    sf::Sprite flag_s, bomb_s;
    sf::Font font;
    sf::Text text, komunikat;
    int startX, centerX, startY, centerY;
public:
    explicit MSSFMLView(MinesweeperBoard &board);
    void draw(sf::RenderWindow &window);
    int get_field_w() const;
    int get_field_h()const;
    int get_startX() const;
    int get_startY() const;
};


#endif //MINESWEEPER_MSSFMLVIEW_H
