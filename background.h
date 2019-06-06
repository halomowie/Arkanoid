//
// Created by Daniel on 01.06.2019.
//

#ifndef ARKANOID_BACKGROUND_H
#define ARKANOID_BACKGROUND_H
#include <SFML/Graphics.hpp>


class background {
    sf::RenderWindow &ark;
public:
    sf::RectangleShape death;
    sf::RectangleShape wall[4];
    background();
    background(sf::RenderWindow & ark);
    void draw(sf::RenderWindow & ark);
    sf::Vector2f getPosForPlatform();
    sf::Vector2f getPosForBall();
    sf::Vector2f getPosForLevelDraw();
    sf::Vector2f getLevelSize();

};


#endif //ARKANOID_BACKGROUND_H
