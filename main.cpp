#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.h"
#include "paddle.h"
#include "ball.h"
#include "LevelDraw.h"
#include <iostream>
#include "GameManager.h"
#include <ctime>
int main()
{
    srand( time( NULL ) );
    // create the window
    sf::RenderWindow ark(sf::VideoMode(1100, 700, 32), "Arkanoid");
    ark.setFramerateLimit(60);
    background tlo(ark);
    paddle palka(tlo);
    LevelDraw lvl(tlo);
    ball kula(ark,tlo,palka,lvl);
    GameManager mgr(kula,palka,lvl,tlo);

    // run the program as long as the window is open
    while (ark.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (ark.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                ark.close();
            }
            else if(event.key.code == sf::Keyboard::Escape){
                ark.close();
            }
        }

        // clear the window with black color
        ark.clear(sf::Color(0,0,0));

        // draw everything here...
        tlo.draw(ark);
        kula.move(ark, lvl);
        palka.drawpaddle(ark);
        lvl.drawblock(ark);
        mgr.DrawGamemanager(ark);
        mgr.EventsGamemanager(event);
        palka.movepaddle(event);


//        if (event.type == sf::Event::TextEntered)
//        {
//            if (event.text.unicode<150)
//                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << " " << event.text.unicode << std::endl;
//        }




        // end the current frame
        ark.display();
        //std::cout << ark.getSize().x << " " << ark.getSize().y << std::endl;
    }

    return 0;
}