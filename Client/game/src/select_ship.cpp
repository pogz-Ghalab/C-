/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** selecting the ship
*/

#include "../include/SFML.hpp"
#include "../include/Game.hpp"


bool display_arrow_ship(Game *game)
{
    if (game->look_arrow_position(*game->Ship_1.at(0)->sprite, 310, 300) == true)
        return (true);
    if (game->look_arrow_position(*game->Ship_2.at(0)->sprite, 310, 600) == true)
        return (true);
    if (game->look_arrow_position(*game->Ship_3.at(0)->sprite, 1000, 300) == true)
        return (true);
    if (game->look_arrow_position(*game->Ship_4.at(0)->sprite, 1000, 600) == true)
        return (true);
    return (false);
}

void select_which_player(sf::Event *event, Game *game)
{
    if ((event->mouseButton.button == sf::Mouse::Left) &&
        (event->mouseButton.x > 385) && (event->mouseButton.x < 550) &&
        (event->mouseButton.y > 250) && (event->mouseButton.y < 390))
    {
        *game->MainPlayerSprite = game->Ship_1;
        game->ship_select = 1;
    }
    else if ((event->mouseButton.button == sf::Mouse::Left) &&
             (event->mouseButton.x > 385) && (event->mouseButton.x < 550) &&
             (event->mouseButton.y > 550) && (event->mouseButton.y < 690))
    {
        *game->MainPlayerSprite = game->Ship_2;
        game->ship_select = 2;
    }
    else if ((event->mouseButton.button == sf::Mouse::Left) &&
             (event->mouseButton.x > 1100) && (event->mouseButton.x < 1350) &&
             (event->mouseButton.y > 250) && (event->mouseButton.y < 390))
    {
        *game->MainPlayerSprite = game->Ship_3;
        game->ship_select = 3;
    }
    else if ((event->mouseButton.button == sf::Mouse::Left) &&
             (event->mouseButton.x > 1100) && (event->mouseButton.x < 1350) &&
             (event->mouseButton.y > 550) && (event->mouseButton.y < 690))
    {
        *game->MainPlayerSprite = game->Ship_4;
        game->ship_select = 4;
    }
}

void select_sprite_pos(Game *game)
{
    game->Ship_1.at(0)->SetPositionAndScale(400, 250, 1.5, 1.5);
    game->Ship_2.at(0)->SetPositionAndScale(385, 550, 1.5, 1.5);
    game->Ship_3.at(0)->SetPositionAndScale(1100, 250, 1.5, 1.5);
    game->Ship_4.at(0)->SetPositionAndScale(1100, 550, 1.5, 1.5);
}

void display_button(Game *game, sf::Event event)
{
    game->SelectButton->sprite->setPosition(640, 750);
    game->SelectPressButton->sprite->setPosition(640, 750);
    if (game->SelectPressButton->sprite->getGlobalBounds().contains(sf::Mouse::getPosition(*game->Window->window).x, sf::Mouse::getPosition(*game->Window->window).y))
        game->Window->draw(game->SelectPressButton);
    else
        game->Window->draw(game->SelectButton);
}

void Game::SelectShip()
{
    SFML::Event event;


    while (this->Window->eventloop(&event)){
        if (event.event.type == sf::Event::Closed)
        {
            std::cout << "the game has been closed" << std::endl;
            this->Window->destroy();
        }
        else if ((event.event.mouseButton.button == sf::Mouse::Left) &&
            (event.event.mouseButton.x > 640) && (event.event.mouseButton.x < 945) &&
            (event.event.mouseButton.y > 750) && (event.event.mouseButton.y < 890) && 
            this->ship_select != 0)
        {
            this->state = State::CustomShip;
        }
        select_which_player(&event.event, this);
    }
    this->Window->window->clear(sf::Color::Black);
    select_sprite_pos(this);
    
    this->Window->draw(this->SelectMenuBackground);
    this->Window->draw(this->Ship_1.at(0));
    this->Window->draw(this->Ship_2.at(0));
    this->Window->draw(this->Ship_3.at(0));
    this->Window->draw(this->Ship_4.at(0));
    if(display_arrow_ship(this) == true)
        this->Window->draw(this->ArrowButton);
    display_button(this, event.event);
    
    this->Window->window->display();
}


   
