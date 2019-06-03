//
// Created by Daniel on 01.06.2019.
//

#ifndef ARKANOID_BACKGROUND_H
#define ARKANOID_BACKGROUND_H
#include <SFML/Graphics.hpp>


class background {
    sf::RenderWindow &ark;
    float Xark;
    float Yark;
    sf::RectangleShape rect;
public:
    background();
    background(sf::RenderWindow & ark);
    void draw(sf::RenderWindow & ark);
    float getArkposX();
    float getArkposY();
    float getArksizeX();
    float getArksizeY();
    float getCenterArkX();
};


#endif //ARKANOID_BACKGROUND_H
