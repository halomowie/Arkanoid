//
// Created by Daniel on 03.06.2019.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "background.h"
#include "paddle.h"
struct speed {
    float x;
    float y;
};
struct kula {
    float pace;
    float radious;
    speed velocity;
    sf::CircleShape blok;
    sf::Clock zegar;
    int tickrate;
};
class ball {
    background &tlo;
    paddle &palka;
public:
    kula pin;
    ball(background &tlo, paddle &palka, float xv, float yv);
    void move(sf::RenderWindow &ark);
};


#endif //ARKANOID_BALL_H
