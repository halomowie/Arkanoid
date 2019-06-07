//
// Created by Daniel on 01.06.2019.
//

#include "paddle.h"
#include "background.h"
#include <iostream>
paddle::paddle(background &temp2): tlo(temp2) {
    platform.speedPercent = 6;
    platform.heightPercent = 10;
    platform.widthPercent = 120;
    platform.tickrate = 0;
    platform.blok.setSize(sf::Vector2f(platform.widthPercent,platform.heightPercent));
    platform.blok.setOrigin(sf::Vector2f(platform.blok.getSize().x/2,0));
    platform.blok.setPosition(tlo.getPosForPlatform());
    platform.blok.setFillColor(sf::Color(216, 28, 28));

}

void paddle::movepaddle(sf::Event &event, sf::RenderWindow &ark) {
    if (platform.tick.getElapsedTime().asMilliseconds() >= platform.tickrate) {
        platform.tick.restart();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                if(platform.blok.getGlobalBounds().intersects(tlo.wall[3].getGlobalBounds())){

                }
                else {
                    if(tlo.wall[0].getPosition().x>platform.blok.getPosition().x-platform.blok.getSize().x/2-platform.speedPercent){

                    }
                    else {
                        platform.blok.move(-platform.speedPercent, 0);
                    }
                }
            }
            else if(event.key.code == sf::Keyboard::Right){
                if(platform.blok.getGlobalBounds().intersects(tlo.wall[1].getGlobalBounds())){

                }
                else {
                    if(tlo.wall[0].getPosition().x+tlo.wall[0].getSize().x<platform.blok.getPosition().x+platform.blok.getSize().x/2+platform.speedPercent){

                    }
                    else {
                        platform.blok.move(platform.speedPercent, 0);
                    }
                }
            }
        }
    }
}







void paddle::drawpaddle(sf::RenderWindow &temp) {
    temp.draw(platform.blok);

}