//
// Created by Daniel on 06.06.2019.
//

#include "GameManager.h"

GameManager::GameManager(ball &kulatemp, paddle &palkatemp, LevelDraw &lvltemp, background &tlotemp):
tlo(tlotemp), palka(palkatemp), lvl(lvltemp), kula(kulatemp)  {
    font.loadFromFile("resources/Pixeled.ttf");
    text.TextLives.setFont(font);
    text.Lives.setFont(font);
    text.TextBlockhits.setFont(font);
    text.Blockhits.setFont(font);

    text.TextLives.setString("LIVES ");
    text.TextLives.setFillColor(sf::Color(255,255,255));
    text.TextLives.setPosition(sf::Vector2f(tlo.getPosforGameState()));
    text.TextLives.setCharacterSize(40);

    text.Lives.setCharacterSize(40);
    text.Lives.setPosition(text.TextLives.getPosition().x+text.TextLives.getGlobalBounds().width,text.TextLives.getPosition().y);
    text.Lives.setFillColor(sf::Color(216, 28, 28));

    text.TextBlockhits.setString("BLOCKS LEFT ");
    text.TextBlockhits.setCharacterSize(40);
    text.TextBlockhits.setFillColor(sf::Color(255,255,255));
    text.TextBlockhits.setPosition(sf::Vector2f(text.TextLives.getPosition().x,text.TextLives.getPosition().y+text.TextLives.getGlobalBounds().height*2));

    text.Blockhits.setFillColor(sf::Color(216, 28, 28));
    text.Blockhits.setPosition(sf::Vector2f(text.TextBlockhits.getPosition().x+text.TextBlockhits.getGlobalBounds().width,
            text.TextBlockhits.getPosition().y));
    text.Blockhits.setCharacterSize(40);

    text.GameEnd.setFont(font);
    text.GameEnd.setFillColor(sf::Color(255,255,255));
    text.GameEnd.setCharacterSize(35);



}

void GameManager::DrawGamemanager(sf::RenderWindow &ark, sf::Event &event) {


    text.Lives.setFillColor(sf::Color(216, 28, 28));
    text.Blockhits.setFillColor(sf::Color(216, 28, 28));

    std::string HP = std::to_string(kula.getBallHealh());
    std::string BL = std::to_string(lvl.getTotalBlockHitValue());

    text.Blockhits.setString(BL);
    text.Lives.setString(HP);


    ark.draw(text.TextLives);
    ark.draw(text.Lives);
    ark.draw(text.TextBlockhits);
    ark.draw(text.Blockhits);
    ark.draw(text.GameEnd);

    //LOSE STATEMENT
    if (kula.pin.healh <= 0) {
        text.GameEnd.setString("LOSE! CLICK DOWN TO RESTART");
        text.GameEnd.setPosition(
                tlo.wall[0].getPosition().x + tlo.wall[0].getSize().x / 2 - text.GameEnd.getGlobalBounds().width / 2,
                tlo.wall[0].getPosition().y + tlo.wall[0].getSize().y + tlo.wall[0].getSize().x / 2 -
                text.GameEnd.getGlobalBounds().height / 2);

        kula.pin.velocity.x=0;
        kula.pin.velocity.y=0;
        kula.pin.blok.setPosition(tlo.getPosForBall());

        GameRestart(event);
    }
    else if (lvl.getTotalBlockHitValue() == 0) {
        text.GameEnd.setString("WIN! CLICK DOWN TO RESTART");
        text.GameEnd.setPosition(
                tlo.wall[0].getPosition().x + tlo.wall[0].getSize().x / 2 -
                text.GameEnd.getGlobalBounds().width / 2,
                tlo.wall[0].getPosition().y + tlo.wall[0].getSize().y + tlo.wall[0].getSize().x / 2 -
                text.GameEnd.getGlobalBounds().height / 2);

        kula.pin.velocity.x=0;
        kula.pin.velocity.y=0;
        kula.pin.blok.setPosition(tlo.getPosForBall());


        GameRestart(event);

    }
    else if (kula.pin.healh >0){
        text.GameEnd.setString(" ");
    }

    }




void GameManager::GameRestart(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Down) {
            std::cout << "TEST" << std::endl;

            for (int x = 0; x < lvl.getLevelSizeCols(); ++x) {
                for (int y = 0; y < lvl.getLevelSizeRows(); ++y) {
                    lvl.pole[x][y] = lvl.poleOriginalState[x][y];
                }

            }

            kula.pin.velocity.x=kula.pin.pace;
            kula.pin.velocity.y=kula.pin.pace;
            kula.pin.healh = 3;
            kula.pin.blok.setPosition(tlo.getPosForBall());
            palka.platform.blok.setPosition(tlo.getPosForPlatform());
            if (kula.pin.velocity.y > 0) {

            } else if (kula.pin.velocity.y < 0) {
                kula.pin.velocity.y *= -1;
            }


        }
    }
}


