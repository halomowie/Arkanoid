//
// Created by Daniel on 06.06.2019.
//

#ifndef ARKANOID_GAMEMANAGER_H
#define ARKANOID_GAMEMANAGER_H

#include "ball.h"
#include "LevelDraw.h"
#include "paddle.h"
#include "background.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
struct word {
    sf::Text TextLives;
    sf::Text Lives;
    sf::Text TextBlockhits;
    sf::Text Blockhits;
    sf::Text GameEnd;
};
class GameManager {
    word text;
    ball &kula;
    paddle &palka;
    LevelDraw &lvl;
    background &tlo;
    sf::RenderWindow &ark;
    sf::Font font;


public:
    GameManager(sf::RenderWindow &ark, ball &kula, paddle &palka, LevelDraw &lvl, background &tlo);
    void DrawGamemanager(sf::RenderWindow &ark);
    void EndScreen(sf::RenderWindow &ark);


};


#endif //ARKANOID_GAMEMANAGER_H
