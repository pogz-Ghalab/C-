/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** show the help option
*/

#include "../include/SFML.hpp"
#include "../include/Game.hpp"

void Game::HelpMe()
{
    SFML::Event event;
    while (this->Window->eventloop(&event)){
        if ((event.event.mouseButton.button == sf::Mouse::Left) &&
        (event.event.mouseButton.x > 65) && (event.event.mouseButton.x < 207) &&
        (event.event.mouseButton.y > 45) && (event.event.mouseButton.y < 190)){
            this->state = State::MainMenu;
        }

    }  

    this->Window->draw(this->HelpBackground);
    this->Window->window->display();
}