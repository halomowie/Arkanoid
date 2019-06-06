//
// Created by Daniel on 01.06.2019.
//

#include "background.h"
#include <iostream>



background::background(sf::RenderWindow &temp): ark(temp) {

    for (int i = 0; i < 4; ++i) {
        wall[i].setSize(sf::Vector2f(600,10));
        wall[i].setFillColor(sf::Color(255,255,255));
    }
    wall[1].rotate(90);
    wall[3].rotate(90);
    wall[0].setPosition(sf::Vector2f(50,50));
    wall[1].setPosition(sf::Vector2f(wall[0].getPosition().x + wall[0].getSize().x + wall[0].getSize().y,
            wall[0].getPosition().y+wall[0].getSize().y));
    wall[2].setPosition(sf::Vector2f(wall[0].getPosition().x,
            wall[0].getPosition().y+wall[0].getSize().y+wall[0].getSize().x));
    wall[3].setPosition(wall[0].getPosition().x,wall[0].getPosition().y + wall[0].getSize().y);
    death.setPosition(wall[0].getPosition().x,wall [0].getPosition().y+ wall[0].getSize().x-wall[0].getSize().y*2);
    death.setFillColor(sf::Color(114, 2, 2));
    death.setSize(sf::Vector2f(wall[0].getSize().x,wall[0].getSize().y*3));


}

sf::Vector2f background::getPosForPlatform() {
    return sf::Vector2f(wall[0].getPosition().x+wall[0].getSize().x/2,
            wall[0].getPosition().y+wall[0].getSize().x-wall[0].getSize().y*4);
}

sf::Vector2f background::getPosForBall() {
    return sf::Vector2f(wall[0].getPosition().x+wall[0].getSize().x/2,
                        wall[0].getPosition().y+wall[0].getSize().x*0.8);
}

sf::Vector2f background::getPosForLevelDraw() {
    return sf::Vector2f(wall[0].getPosition().x+0.1*wall[0].getSize().x,
            wall[0].getPosition().y+wall[0].getSize().x*0.1);
}

sf::Vector2f background::getLevelSize() {
    return sf::Vector2f(wall[0].getSize().x*0.8,wall[0].getSize().x*0.4);
}

void background::draw(sf::RenderWindow &ark) {
    for (int i = 0; i < 4; ++i) {
        ark.draw(wall[i]);
    }
    ark.draw(death);
}
