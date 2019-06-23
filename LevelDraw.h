//
// Created by Daniel on 04.06.2019.
//

#ifndef ARKANOID_LEVELDRAW_H
#define ARKANOID_LEVELDRAW_H

#include <Graphics/RenderWindow.hpp>
#include "background.h"
#include <vector>

struct obj {
    float width;
    float height;
    sf::RectangleShape blok[12][20];
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
    int poleOriginalState[10][12];
    obj block;
    LevelDraw(background &tlo);
    void drawblock(sf::RenderWindow &ark);
    int getLevelSizeCols();
    int getLevelSizeRows();
    int getTotalBlockHitValue();
    void SaveBoardState();
};


#endif //ARKANOID_LEVELDRAW_H
