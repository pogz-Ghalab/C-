/*
** EPITECH PROJECT, 2023
** R-Type project
** File description:
** game over
*/

#include "../include/SFML.hpp"
#include "../include/Game.hpp"


void Game::GameOver()
{
    //Client *cli = this->client;
    SFML::Event event;
    
    while (this->Window->eventloop(&event))
    {
        if ((event.event.mouseButton.button == sf::Mouse::Left) &&
            (event.event.mouseButton.x > 485) && (event.event.mouseButton.x < 760) &&
            (event.event.mouseButton.y > 590) && (event.event.mouseButton.y < 660))
        {
            std::cout << "suppose to go to menue" << std::endl;
            this->state = 0;
        }
        else if ((event.event.mouseButton.button == sf::Mouse::Left) &&
                 (event.event.mouseButton.x > 850) && (event.event.mouseButton.x < 1105) &&
                 (event.event.mouseButton.y > 590) && (event.event.mouseButton.y < 660))
        {
            std::cout << "the game has ended, thank you for playing" << std::endl;
            this->Window->destroy();
            exit(0);
        }
        // quit function
    }
    this->Window->window->clear(sf::Color::Black);
    this->Window->draw(this->GameOverBackground);

    this->lobby_music.pause();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        this->lobby_music.stop();
        this->gameover_music.play();
    }

    this->Window->window->display();
}
