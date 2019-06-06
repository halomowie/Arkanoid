//
// Created by Daniel on 04.06.2019.
//

#ifndef ARKANOID_LEVELDRAW_H
#define ARKANOID_LEVELDRAW_H

#include <Graphics/RenderWindow.hpp>
#include "background.h"
#include "vector"

struct obj {
    float width;
    float height;
    //sf::RectangleShape blok;
    sf::RectangleShape blok[12][20];
    //std::vector<std::vector<sf::RectangleShape> > blok ;

    int hitpoints;
};
struct LS {
    float width;
    float height;
    int rows;
    int cols;
};

class LevelDraw {

private:
    background &tlo;
    LS levelsize;
public:
    std::vector<std::vector<int> > pole;
    obj block;
    LevelDraw(background &tlo);
    void drawblock(sf::RenderWindow &ark);
    int getLevelSizeCols();
    int getLevelSizeRows();
};


#endif //ARKANOID_LEVELDRAW_H
