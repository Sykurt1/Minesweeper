#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML\Graphics.hpp>
#include "MSSFMLView.h"
#include "MSSFMLController.h"
int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "MINESWEEPER");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10,10,EASY);
   // MSBoardTextView view(board);
    MSSFMLView view (board);
    //MSTextController ctrl (board, view);
    MSSFMLController game (view, board);
  //  board.toggleFlag(0,0);
//    board.revealField(1,0);
//    board.revealField(4,5);
//    board.revealField(8,7);
//    board.revealField(4,3);
   // board.revealField(5,2);
    //board.debug_display();
    //ctrl.play();
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        view.draw(window);
//        window.display();
//    }
    game.play(window);


    return 0;
}
