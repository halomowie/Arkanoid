//
// Created by Daniel on 01.06.2019.
//

#ifndef ARKANOID_PADDLE_H
#define ARKANOID_PADDLE_H

#include "background.h"
struct padd {
    float heightPercent;
    float widthPercent;
    float speedPercent;
    sf::RectangleShape blok;
    sf::Clock tick;
    int tickrate;
};


class paddle {

    background &tlo;
public:
    padd platform;
    paddle(background &tlo);
    void movepaddle(sf::Event &event);
    void drawpaddle(sf::RenderWindow &temp);
};


#endif //ARKANOID_PADDLE_H
