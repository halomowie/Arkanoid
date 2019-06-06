//
// Created by Daniel on 03.06.2019.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "background.h"
#include "paddle.h"
#include "LevelDraw.h"
struct speed {
    float x;
    float y;
};

struct kula {
    float xv;
    float yv;
    float pace;
    float radious;
    speed velocity;
    sf::CircleShape blok;
    sf::Clock zegar;
    int tickrate;
    int healh;
};
class ball {
    background &tlo;
    paddle &palka;
    LevelDraw &lvl;
public:
    kula pin;
    ball(sf::RenderWindow &ark, background &tlo, paddle &palka, LevelDraw &lvl);
    void move(sf::RenderWindow &ark, LevelDraw &lvl);
    bool isCollision(sf::CircleShape x, sf::RectangleShape y);
    void BlockHit();
};


#endif //ARKANOID_BALL_H
