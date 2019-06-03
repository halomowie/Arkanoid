#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.h"
#include "paddle.h"
#include "ball.h"
#include <iostream>
int main()
{
    // create the window
    sf::RenderWindow ark(sf::VideoMode(1024, 700, 32), "Arkanoid");
    ark.setVerticalSyncEnabled(true);
    //ark.setFramerateLimit(60);
    background tlo(ark);
    paddle palka(tlo);
    ball kula(tlo,palka,-1,1);
    // run the program as long as the window is open
    while (ark.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (ark.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                ark.close();
        }

        // clear the window with black color
        ark.clear(sf::Color(0,0,0));

        // draw everything here...

        tlo.draw(ark);
        kula.move(ark);
        palka.drawpaddle(ark);
        palka.movepaddle(event,ark);
        // end the current frame
        ark.display();
        //std::cout << ark.getSize().x << " " << ark.getSize().y << std::endl;
    }

    return 0;
}