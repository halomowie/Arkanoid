//
// Created by Daniel on 04.06.2019.
//

#ifndef ARKANOID_LEVELDRAW_H
#define ARKANOID_LEVELDRAW_H

#include <Graphics/RenderWindow.hpp>
#include "background.h"
#include "ball.h"
struct obj {
    int width;
    int height;
    int hits;
};

class LevelDraw {

private:
    background &tlo;
    ball &kula;
    obj block;
    int pole[20][20][5];
public:
    LevelDraw(background &tlo, ball &kula);
    void drawblock(sf::RenderWindow &ark, background &tlo, ball &kula);
};


#endif //ARKANOID_LEVELDRAW_H
