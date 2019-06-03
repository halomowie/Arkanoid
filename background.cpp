//
// Created by Daniel on 01.06.2019.
//

#include "background.h"
#include <iostream>



background::background(sf::RenderWindow &temp): ark(temp) {

        Xark = ark.getSize().x;
        Yark = ark.getSize().y;

    rect.setSize(sf::Vector2f(600,600));
    rect.setPosition(sf::Vector2f(100,50));

}

void background::draw(sf::RenderWindow &ark) {


    rect.setFillColor(sf::Color(0,0,0));
    rect.setOutlineColor(sf::Color(255,255,255));
    rect.setOutlineThickness(Xark*0.01);
    ark.draw(rect);





}

float background::getArkposX() {
    float x=rect.getPosition().x;
    return x;
}

float background::getArkposY() {
    float y=rect.getPosition().y;
    return y;
}

float background::getArksizeX() {
    float xS=rect.getSize().x;
    return xS;
}

float background::getArksizeY() {
    float yS=rect.getSize().y;
    return yS;
}

float background::getCenterArkX() {
    return (getArksizeX()/2)+getArkposX();
}