//
// Created by Daniel on 01.06.2019.
//

#include "paddle.h"
#include "background.h"
#include <iostream>
paddle::paddle(background &temp2): tlo(temp2) {
    platform.speedPercent = 15;
    platform.heightPercent = 12;
    platform.widthPercent = 120;
    platform.tickrate = 20;
    platform.blok.setSize(sf::Vector2f(platform.widthPercent,platform.heightPercent));
    platform.blok.setOrigin(sf::Vector2f(platform.blok.getSize().x/2,0));
    platform.blok.setPosition(sf::Vector2f(tlo.getCenterArkX(), tlo.getArkposY()+tlo.getArksizeY()- platform.heightPercent*6));
}

void paddle::movepaddle(sf::Event &event, sf::RenderWindow &ark) {
    if (platform.tick.getElapsedTime().asMilliseconds() >= platform.tickrate) {
        if (event.type == sf::Event::KeyPressed) {
            platform.tick.restart();
            if (event.key.code == sf::Keyboard::Right) {
                if (platform.blok.getPosition().x + platform.blok.getSize().x / 2 <
                    tlo.getArkposX() + tlo.getArksizeX())
                    platform.blok.move(platform.speedPercent, 0);
                ark.draw((platform.blok));
            } else if (event.key.code == sf::Keyboard::Left) {
                if (platform.blok.getPosition().x - platform.blok.getSize().x / 2 > tlo.getArkposX())
                    platform.blok.move(-platform.speedPercent, 0);
                ark.draw(platform.blok);
            }

        }
    }
}





void paddle::drawpaddle(sf::RenderWindow &temp) {
    platform.blok.setFillColor(sf::Color(216, 28, 28));
    temp.draw(platform.blok);

    //std::cout << platform.blok.getPosition().x << " " << platform.blok.getPosition().y << std::endl;
    //std::cout << platform.blok.getLocalBounds().height << " " << platform.blok.getLocalBounds().width << std::endl;
    //std::cout << platform.blok.getPosition().x << " " << platform.blok.getPosition().y << std::endl;
    //std::cout << platform.blok.getSize().x << std::endl;
    //std::cout << tlo.getArkposX() << " " << tlo.getArksizeX()+tlo.getArkposX() << std::endl;

}