#include "MSSFMLController.h"
#include "MSSFMLView.h"
#include <SFML\Graphics.hpp>
MSSFMLController::MSSFMLController(MSSFMLView &view, MinesweeperBoard &board) : view(view), board(board)
{

}

void MSSFMLController::play(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {

                int wiersz = (event.mouseButton.x - view.get_startX()) / view.get_field_w();
                int kolumna = (event.mouseButton.y - view.get_startY()) / view.get_field_h();

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    board.revealField(wiersz, kolumna);
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    board.toggleFlag(wiersz, kolumna);
                }
            }
        }
        window.clear();
        view.draw(window);
        window.display();
    }
}