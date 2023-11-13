/*
** EPITECH PROJECT, 2023
** customize your ship
** File description:
** R-type project
*/

#include "../include/SFML.hpp"
#include "../include/Game.hpp"

void select_ship1_design(Game *game)
{
    if (game->ship_select == 1)
    {
        // start the customize
        if (game->change_ship == 0)
        {
            *game->MainPlayerSprite = game->Ship_1;
            game->slct = 1;
        }
        else if (game->change_ship <= 2)
        {
            *game->MainPlayerSprite = game->ship1_design1;
            game->slct = 2;
        }
        else if (game->change_ship <= 4)
        {
            *game->MainPlayerSprite = game->ship1_design2;
            game->slct = 3;
        }
        else if (game->change_ship <= 6)
        {
            *game->MainPlayerSprite = game->ship1_design3;
            game->slct = 4;
        }
        else if (game->change_ship <= 8)
        {
            *game->MainPlayerSprite = game->ship1_design4;
            game->slct = 5;
        }
    }
    else if (game->ship_select == 2)
    {
        if (game->change_ship == 0)
        {
            *game->MainPlayerSprite = game->Ship_2;
            game->slct = 1;
        }
        else if (game->change_ship <= 2)
        {
            *game->MainPlayerSprite = game->ship2_design1;
            game->slct = 2;
        }
        else if (game->change_ship <= 4)
        {
            *game->MainPlayerSprite = game->ship2_design2;
            game->slct = 3;
        }
        else if (game->change_ship <= 6)
        {
            *game->MainPlayerSprite = game->ship2_design3;
            game->slct = 4;
        }
        else if (game->change_ship <= 8)
        {
            *game->MainPlayerSprite = game->ship2_design4;
            game->slct = 5;
        }
    }
    else if (game->ship_select == 3)
    {
        if (game->change_ship == 0)
        {
            *game->MainPlayerSprite = game->Ship_3;
            game->slct = 1;
        }
        else if (game->change_ship <= 2)
        {
            *game->MainPlayerSprite = game->ship3_design1;
            game->slct = 2;
        }
        else if (game->change_ship <= 4)
        {
            *game->MainPlayerSprite = game->ship3_design2;
            game->slct = 3;
        }
        else if (game->change_ship <= 6)
        {
            *game->MainPlayerSprite = game->ship3_design3;
            game->slct = 4;
        }
        else if (game->change_ship <= 8)
        {
            *game->MainPlayerSprite = game->ship3_design4;
            game->slct = 5;
        }
    }
    else if (game->ship_select == 4)
    {
        if (game->change_ship == 0)
        {
            *game->MainPlayerSprite = game->Ship_4;
            game->slct = 1;
        }
        else if (game->change_ship <= 2)
        {
            *game->MainPlayerSprite = game->ship4_design1;
            game->slct = 2;
        }
        else if (game->change_ship <= 4)
        {
            *game->MainPlayerSprite = game->ship4_design2;
            game->slct = 3;
        }
        else if (game->change_ship <= 6)
        {
            *game->MainPlayerSprite = game->ship4_design3;
            game->slct = 4;
        }
        else if (game->change_ship <= 8)
        {
            *game->MainPlayerSprite = game->ship4_design4;
            game->slct = 5;
        }
    }
}

void display_select(Game *game, sf::Event event)
{
    game->SelectButton->sprite->setPosition(640, 750);
    game->SelectPressButton->sprite->setPosition(640, 750);
    if (game->SelectPressButton->sprite->getGlobalBounds().contains(sf::Mouse::getPosition(*game->Window->window).x, sf::Mouse::getPosition(*game->Window->window).y))
        game->Window->draw(game->SelectPressButton);
    else
        game->Window->draw(game->SelectButton);
}

void Game::CustomShip()
{

    SFML::Event event;

    while (this->Window->eventloop(&event))
    {
        if (event.event.type == sf::Event::Closed)
        {
            std::cout << "the game has been closed from custom ship" << std::endl;
            this->Window->destroy();
        }
        else if ((event.event.mouseButton.button == sf::Mouse::Left) &&
                 (event.event.mouseButton.x > 185) && (event.event.mouseButton.x < 400) &&
                 (event.event.mouseButton.y > 400) && (event.event.mouseButton.y < 600) && (this->change_ship != 0))
        {
            std::cout << "clicking on the left arrow" << std::endl;
            // switch to the design before
            this->change_ship = this->change_ship - 1;
        }
        else if ((event.event.mouseButton.button == sf::Mouse::Left) &&
                 (event.event.mouseButton.x > 1215) && (event.event.mouseButton.x < 1418) &&
                 (event.event.mouseButton.y > 390) && (event.event.mouseButton.y < 590) && (this->change_ship != 8))
        {
            std::cout << "clicking on the right arrow" << std::endl;
            // switch to the design after
            this->change_ship = this->change_ship + 1;
        }
        else if ((event.event.mouseButton.button == sf::Mouse::Left) &&
                 (event.event.mouseButton.x > 5) && (event.event.mouseButton.x < 120) &&
                 (event.event.mouseButton.y > 11) && (event.event.mouseButton.y < 113))
        {
            std::cout << "oh you wana change ur ship" << std::endl;
            this->state = State::SelectShip;
            this->ship_select = 0;
            this->slct = 0;
            this->change_ship = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            this->change_ship = 0;
        }

        else if ((event.event.mouseButton.button == sf::Mouse::Left) &&
                 (event.event.mouseButton.x > 640) && (event.event.mouseButton.x < 945) &&
                 (event.event.mouseButton.y > 750) && (event.event.mouseButton.y < 890) &&
                 (this->slct != 0))
        {
            std::cout << "your entering the lobby" << std::endl;
            this->state = State::Lobby;
        }
        select_ship1_design(this);
    }
    
    this->lobby_music.play();
    this->MainPlayerSprite->at(0)->SetPositionAndScale(590, 400, 3, 3);
    this->MainPlayerSprite->at(this->sights)->sprite->setTextureRect(sf::IntRect(0, 0, 130, 115));
    this->Window->window->clear(sf::Color::Black);
    this->Window->draw(this->desginShip_bg);
    this->Window->draw(this->MainPlayerSprite->at(0));
    display_select(this, event.event);
    this->Window->window->display();
}