//
// Created by Daniel on 04.06.2019.
//

#include "LevelDraw.h"

LevelDraw::LevelDraw(background &temp1): tlo(temp1) {
    levelsize.width=tlo.getLevelSize().x;
    levelsize.height=tlo.getLevelSize().y;
    levelsize.cols=10;
    levelsize.rows=12;
    block.width=levelsize.width/levelsize.cols;
    block.height=levelsize.height/levelsize.rows;
    //block.blok[levelsize.cols][levelsize.rows];
    //pole[10][12];
    pole= {{3,2,5,5,5,5,5,5,5,5,2,3}, //1
          {3,3,2,5,4,4,4,4,5,2,3,3}, //2
          {3,3,3,2,5,4,4,5,2,3,3,3}, //3
          {3,3,3,3,2,5,5,2,1,1,1,1}, //4
          {1,1,1,1,1,2,2,3,1,0,0,1}, //5
          {1,1,1,1,1,2,2,3,1,0,0,1}, //6
          {3,3,3,3,2,5,5,2,1,1,1,1}, //7
          {3,3,3,2,5,4,4,5,2,3,3,3}, //8
          {3,3,2,5,4,4,4,4,5,2,3,3}, //9
          {3,2,5,5,5,5,5,5,5,5,2,3},};//10;
SaveBoardState();
}

void LevelDraw::drawblock(sf::RenderWindow &ark) {
    for (int x = 0; x < getLevelSizeCols(); ++x) {
        for (int y = 0; y < getLevelSizeRows(); ++y) {
            if(pole[x][y]==0) {
                block.blok[x][y].setPosition(sf::Vector2f(-200,-200));
            }
            else if(pole[x][y]>0){
                block.blok[x][y].setSize(sf::Vector2f(block.width - 2, block.height - 2));
                block.blok[x][y].setPosition(sf::Vector2f((tlo.getPosForLevelDraw().x) + block.width * x,
                                                          (tlo.getPosForLevelDraw().y) + block.height * y));
            }


             if (pole[x][y] == 1) {
                block.blok[x][y].setFillColor(sf::Color(117, 186, 48));
                ark.draw(block.blok[x][y]);
            } else if (pole[x][y] == 2) {
                block.blok[x][y].setFillColor(sf::Color(233, 244, 14));
                ark.draw(block.blok[x][y]);
            } else if (pole[x][y] == 3) {
                block.blok[x][y].setFillColor(sf::Color(252, 136, 27));
                ark.draw(block.blok[x][y]);
            } else if (pole[x][y] == 4) {
                block.blok[x][y].setFillColor(sf::Color(252, 38, 26));
                ark.draw(block.blok[x][y]);
            } else if (pole[x][y] == 5) {
                block.blok[x][y].setFillColor(sf::Color(62, 4, 79));
                ark.draw(block.blok[x][y]);
            }
        }
    }
}



int LevelDraw::getLevelSizeCols() {
    return levelsize.cols;
}

int LevelDraw::getLevelSizeRows() {
    return levelsize.rows;
}


int LevelDraw::getTotalBlockHitValue() {
    int val;
    for (int x = 0; x < getLevelSizeCols(); ++x) {
        for (int y = 0; y < getLevelSizeRows(); ++y) {
            val+=pole[x][y];
        }
    }
    return val;
}

void LevelDraw::SaveBoardState() {
    for (int x = 0; x < getLevelSizeCols() ; ++x) {
        for (int y = 0; y < getLevelSizeRows() ; ++y) {
            poleOriginalState[x][y]=pole[x][y];
        }

    }
}