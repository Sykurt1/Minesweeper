#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML\Graphics.hpp>

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H


class MSSFMLController {
    MSSFMLView &view;
    MinesweeperBoard &board;
public:
    MSSFMLController(MSSFMLView &view, MinesweeperBoard &board);
    void play(sf::RenderWindow &window);
};


#endif //SAPER_MSSFMLCONTROLLER_H
