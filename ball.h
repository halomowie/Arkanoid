//
// Created by Daniel on 03.06.2019.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "background.h"
#include "paddle.h"
#include "LevelDraw.h"
#include <cmath>
enum gameS{RUNNING,PAUSE};
struct vect{
    float x;
    float y;
};
struct speed2 {
    float x;
    float y;
};
struct speed {
    float x;
    float y;
};

struct kula {
    float xv;
    float yv;
    speed2 pace;
    float radious;
    speed velocity;
    sf::CircleShape blok;
    sf::Clock zegar;
    int tickrate;
    int healh;
    float SPEED;
};
class ball {
    background &tlo;
    paddle &palka;
    LevelDraw &lvl;
    sf::Clock DebounceClock;
    sf::Clock DebounceClockWALL;
    int DebounceBlockHit;
    int DebouncePaddle;
    int DebounceWall;
public:
    gameS Gamestate;
    kula pin;
    vect zwrot;
    ball(sf::RenderWindow &ark, background &tlo, paddle &palka, LevelDraw &lvl);
    void move(sf::RenderWindow &ark, LevelDraw &lvl);
    void BlockHit();
    void CollisionWithPaddle();
    int getBallHealh();
    void BallAngle();
    void CollisionWithWalls();
};


#endif //ARKANOID_BALL_H
