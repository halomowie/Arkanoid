//
// Created by Daniel on 03.06.2019.
//

#include "ball.h"
#include <iostream>

ball::ball(background &temp1, paddle &temp2, float xv, float yv): tlo(temp1), palka(temp2) {
    //best pace 2,4,5,10,20,29
    pin.pace=10;
    pin.tickrate=32;
    pin.velocity.x=xv*pin.pace;
    pin.velocity.y=yv*pin.pace;
    pin.radious=10;
    pin.blok.setRadius(pin.radious);
    pin.blok.setOrigin(sf::Vector2f(pin.radious,pin.radious));
    pin.blok.setFillColor(sf::Color(6, 191, 3));
    pin.blok.setPosition(sf::Vector2f(tlo.getCenterArkX(),tlo.getArkposY()+tlo.getArksizeY()*0.8));
}

void ball::move(sf::RenderWindow &ark) {
    if(pin.zegar.getElapsedTime().asMilliseconds()>=pin.tickrate) {
        pin.zegar.restart();
        pin.blok.move(sf::Vector2f(pin.velocity.x, -pin.velocity.y));
        //PRAWA SCIANA
        if (pin.blok.getPosition().x + pin.blok.getRadius() >= tlo.getArkposX() + tlo.getArksizeX())
            pin.velocity.x *= -1;
            //GORNA SCIANA
        else if (pin.blok.getPosition().y - pin.blok.getRadius() <= tlo.getArkposY())
            pin.velocity.y *= -1;
            //LEWA SCIANA
        else if (pin.blok.getPosition().x - pin.blok.getRadius() <= tlo.getArkposX())
            pin.velocity.x *= -1;
            //DOLNA SCIANA
        else if (pin.blok.getPosition().y + pin.blok.getRadius() >= tlo.getArkposY() + tlo.getArksizeY())
            pin.velocity.y *= -1;
            //KOLIZJA PLATFORMA
        else if (pin.blok.getPosition().y + pin.blok.getRadius() >= palka.platform.blok.getPosition().y
                 and pin.blok.getPosition().y - pin.blok.getRadius() <= palka.platform.blok.getPosition().y + palka.platform.blok.getSize().y
                 and pin.blok.getPosition().x >= palka.platform.blok.getPosition().x - palka.platform.blok.getSize().x / 2
                 and pin.blok.getPosition().x <= palka.platform.blok.getPosition().x + palka.platform.blok.getSize().x / 2)
            pin.velocity.y *= -1;


    }
    ark.draw(pin.blok);
//    std::cout << pin.blok.getPosition().x << " " << pin.blok.getPosition().y << " " << pin.blok.getRadius() << std::endl;
}