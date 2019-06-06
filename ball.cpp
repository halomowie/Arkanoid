//
// Created by Daniel on 03.06.2019.
//

#include "ball.h"
#include <iostream>

ball::ball(sf::RenderWindow &ark, background &temp1, paddle &temp2, LevelDraw &temp3):
tlo(temp1), palka(temp2), lvl(temp3) {
    //best pace 2,4,5,10,20,29
    pin.healh=3;
    pin.pace=4;
    pin.tickrate=0;
    pin.velocity.x=1*pin.pace;
    pin.velocity.y=1*pin.pace;
    pin.radious=10;
    pin.blok.setRadius(pin.radious);
    pin.blok.setOrigin(sf::Vector2f(pin.radious,pin.radious));
    pin.blok.setFillColor(sf::Color(6, 191, 3));
    pin.blok.setPosition(sf::Vector2f(tlo.getPosForBall()));

}

void ball::move(sf::RenderWindow &ark, LevelDraw &lvl) {
    if(pin.zegar.getElapsedTime().asMilliseconds()>=pin.tickrate) {
        pin.zegar.restart();

        pin.blok.move(sf::Vector2f(pin.velocity.x, -pin.velocity.y));
        //Kolizja z klockami
        BlockHit();
        //GORNA SCIANA
        if (pin.blok.getGlobalBounds().intersects(tlo.wall[0].getGlobalBounds()))
            pin.velocity.y *= -1;
            //DOLNA SCIANA
        else if (pin.blok.getGlobalBounds().intersects(tlo.wall[2].getGlobalBounds()))
            pin.velocity.y *= -1;
            //LEWA SCIANA
        else if (pin.blok.getGlobalBounds().intersects(tlo.wall[3].getGlobalBounds()))
            pin.velocity.x *= -1;
            //PRAWA SCIANA
        else if (pin.blok.getGlobalBounds().intersects(tlo.wall[1].getGlobalBounds()))
            pin.velocity.x *= -1;
            //PLATFORMA
        else if (pin.blok.getGlobalBounds().intersects(palka.platform.blok.getGlobalBounds()))
            pin.velocity.y *= -1;
            //WYPADA POZA PLATFORME
        else if (pin.blok.getGlobalBounds().intersects(tlo.death.getGlobalBounds())) {
            pin.healh -= 1;
            if(pin.healh>0) {
                pin.blok.setPosition(tlo.getPosForBall());
                pin.velocity.y*=-1;
            }
            else if(pin.healh<=0){
                pin.velocity.x=0;
                pin.velocity.y=0;
                pin.blok.setPosition(sf::Vector2f(-100,-100));
            }

        }
        ark.draw(pin.blok);
    }
}


bool ball::isCollision(sf::CircleShape x, sf::RectangleShape y) {
    return (x.getGlobalBounds().intersects(y.getGlobalBounds()));
}



void ball::BlockHit() {
    std::cout << lvl.block.blok[0][0].getGlobalBounds().width << " " <<
    lvl.block.blok[0][0].getSize().x << std::endl;
    for (int x = 0; x < lvl.getLevelSizeCols(); ++x) {
        for (int y = 0; y < lvl.getLevelSizeRows(); ++y) {
            //Gora i Doł bloku
            if (pin.blok.getPosition().x >= lvl.block.blok[x][y].getPosition().x
                and pin.blok.getPosition().x <= lvl.block.blok[x][y].getPosition().x + lvl.block.blok[x][y].getSize().x
                and pin.blok.getPosition().y - pin.blok.getRadius() <= lvl.block.blok[x][y].getPosition().y + lvl.block.blok[x][y].getSize().y
                and pin.blok.getPosition().y+pin.blok.getRadius()>=lvl.block.blok[x][y].getPosition().y) {
                lvl.pole[x][y] -= 1;
                pin.velocity.y *= -1;
            }
                //Lewo i Prawo bloku
            else if (pin.blok.getPosition().y >= lvl.block.blok[x][y].getPosition().y
                     and pin.blok.getPosition().y <= lvl.block.blok[x][y].getPosition().y + lvl.block.blok[x][y].getSize().y
                     and pin.blok.getPosition().x + pin.blok.getRadius() >= lvl.block.blok[x][y].getPosition().x
                     and pin.blok.getPosition().x - pin.blok.getRadius() <= lvl.block.blok[x][y].getPosition().x + lvl.block.blok[x][y].getSize().x) {
                lvl.pole[x][y] -= 1;
                pin.velocity.x *= -1;
            }

        }
    }
}
