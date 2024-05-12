#include "MSSFMLView.h"
#include "MinesweeperBoard.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board): board(board)
{
    screen_height = 600;
    screen_width = 800;
    rect_h = 32;
    rect_w = 32;
    r1 = sf::RectangleShape(sf::Vector2f(rect_w,rect_h));
    r1.setFillColor(sf::Color(250, 0, 0));
    r1.setOutlineThickness(2);
    r1.setOutlineColor(sf::Color(250, 150, 100));
    font.loadFromFile("../ARIBL0.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    komunikat.setFont(font);
    komunikat.setCharacterSize(48);
    flag.loadFromFile("../flaga.png");
    bomb.loadFromFile("../bomba.png");
    flag_s.setTexture(flag);
    bomb_s.setTexture(bomb);
    centerX = screen_width / 2;
    centerY = screen_height / 2;
    startX = centerX - ((board.getBoardWidth() - 1) * rect_w + rect_w) / 2;
    startY = centerY - ((board.getBoardHeight() - 1) * rect_h + rect_h) / 2;
}

void MSSFMLView::draw(sf::RenderWindow &window)
{
    for (int x = startX, r = 0; r < board.getBoardWidth(); x += rect_w, r++)
    {
        for (int y = startY, c = 0; c < board.getBoardHeight(); y += rect_h, c++)
        {
            if (board.getFieldInfo(r, c) == '_')
            {
                r1.setPosition(x, y);
                window.draw(r1);
            }
            else if (board.getFieldInfo(r, c) == 'F')
            {
                flag_s.setPosition(x, y);
                window.draw(flag_s);
            }
            else if (board.getFieldInfo(r, c) == ' ')
            {
                window.draw(r1);
            }
            else if (board.getFieldInfo(r, c) == 'x')
            {
                bomb_s.setPosition(x, y);
                window.draw(bomb_s);
            }
            else if (board.getFieldInfo(r,c) >= '1' and board.getFieldInfo(r,c) <= '8' )
            {
                text.setString(board.getFieldInfo(r,c));
                text.setPosition(x, y);
                text.move(rect_w/5,rect_h/10);
                window.draw(text);
            }
            else if (board.getGameState() == FINISHED_WIN)
            {
                komunikat.setString("WYGRANA");
                komunikat.setPosition(centerX, centerY);
                window.draw(komunikat);
            }
            else if (board.getGameState() == FINISHED_LOSS)
            {
                komunikat.setString("PRZEGRALES");
                komunikat.setPosition(0,0);
                window.draw(komunikat);
            }
        }
    }
}
int MSSFMLView::get_field_h() const
{
    return rect_h;
}
int MSSFMLView::get_field_w() const
{
    return rect_w;
}
int MSSFMLView::get_startX() const
{
    return startX;
}
int MSSFMLView::get_startY() const
{
    return startY;
}

