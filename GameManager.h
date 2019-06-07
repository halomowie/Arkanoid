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

    sf::Font font;
    sf::Vector2f BoxPos;
    sf::Vector2f BoxSize;
    sf::Clock clickrate;


public:
    GameManager(ball &kula, paddle &palka, LevelDraw &lvl, background &tlo);
    void DrawGamemanager(sf::RenderWindow &ark, sf::Event &event);
    void GameRestart(sf::Event &event);

};


#endif //ARKANOID_GAMEMANAGER_H
