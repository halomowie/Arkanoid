//
// Created by Daniel on 06.06.2019.
//

#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &arktemp, ball &kulatemp, paddle &palkatemp, LevelDraw &lvltemp, background &tlotemp):
ark(arktemp), tlo(tlotemp), palka(palkatemp), lvl(lvltemp), kula(kulatemp)  {
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
    text.GameEnd.setCharacterSize(80);
    text.GameEnd.setPosition(600,400);



}
void GameManager::EndScreen(sf::RenderWindow &ark) {

}

void GameManager::DrawGamemanager(sf::RenderWindow &ark) {


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

    if(kula.getBallHealh()==0){
        text.GameEnd.setString("LOSE");
    }
    else if(lvl.getTotalBlockHitValue()==0){
        text.GameEnd.setString("WIN");
    }
}

