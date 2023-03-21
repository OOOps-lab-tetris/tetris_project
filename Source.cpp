#include<iostream>
#include "Game.h";
#include "tetris.h"

int main()
{
    srand(time(0));

    sf::Clock clock;

    tetris game;


    while (game.game_on())
    {
        float time = clock.getElapsedTime().asSeconds();
        game.update_timer(time);
        clock.restart();
       // std::cout << time <<std:: endl;
        //timer += time;
        //Event e
        game.tet_event();
        //// <- Move -> ///
        game.tet_move();
        //////Rotate//////
        game.tet_rotate();
        ///////Tick//////
        game.tet_timer();
        ///////check lines//////////
        game.tet_check();

        game.tet_scal();

        /////////draw//////////
        game.tet_draw();
      
    }

    return 0;
}
