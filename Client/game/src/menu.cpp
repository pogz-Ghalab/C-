/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** main menu
*/

#include "../../main.hpp"
#include "../include/Game.hpp"
#include "../include/SFML.hpp"

void initalize_game(Game *game);
void start_game(Client *client, Game *game);
bool look_arrow_position(sf::Sprite sprite, Game *game, int pos_x, int pos_y);
void buttons_position(Game *game);
bool display_arrow(Game *game);


// arrow display condition
bool Game::look_arrow_position(sf::Sprite sprite, int pos_x, int pos_y)
{
    if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*this->Window->window).x, sf::Mouse::getPosition(*this->Window->window).y))
    {
        this->ArrowButton->SetPositionAndScale(pos_x, pos_y, 0.2, 0.2);
        return (true);
    }
    return (false);
}

bool display_arrow(Game *game)
{
    if (game->look_arrow_position(*game->PlayButton->sprite, 845, 350) == true)
        return (true);
    if (game->look_arrow_position(*game->HelpButton->sprite, 845, 550) == true)
        return (true);
    if (game->look_arrow_position(*game->SettingsButton->sprite, 845, 450) == true)
        return (true);
    if (game->look_arrow_position(*game->QuitButton->sprite, 845, 650) == true)
        return (true);
    return (false);
}
void animate_bg(Game *game)
{
    if (game->clock.getElapsedTime().asSeconds() > 0.08f){
        game->clock.restart();
        if (game->bg_y >= 7200){
            game->bg_y = 0;
            game->bg_x = 0;
        } else {

            int x = game->bg_x;
            int y = game->bg_y;
            if (y < 6300){
                if (x >= 7200){
                    game->bg_x = 0;
                    game->bg_y += 900;
                } else {
                    game->bg_x += 1600;
                }
            } else {
                if (x >= 4600){
                    game->bg_x = 0;
                    game->bg_y += 900;
                } else {
                    game->bg_x += 1600;
                }
            }
        }
        game->MainMenuBackground->CropSprite(game->bg_x, game->bg_y, 1600, 900);
    }
}

void Game::MainMenu()
{
    Client *cli = this->client;
    SFML::Event event;
    sf::Sprite *sprite;

    while (this->Window->eventloop(&event))
    {
        if ((event.event.mouseButton.button == sf::Mouse::Left) &&
            (event.event.mouseButton.x > 935) && (event.event.mouseButton.x < 1095) &&
            (event.event.mouseButton.y > 350) && (event.event.mouseButton.y < 410)) {
            std::cout << "you are clickin on the right coordinates" << std::endl;
            this->state = State::Inputs;
        }
        if ((event.event.mouseButton.button == sf::Mouse::Left) && 
            (event.event.mouseButton.x > 935) && (event.event.mouseButton.x < 1095) &&
            (event.event.mouseButton.y > 550) && (event.event.mouseButton.y < 610)){
            std::cout << "you are clicking on the help me, need help? go fuck yourslef" << std::endl;
            this->state = State::HelpMe;
            }

        if (event.event.type == sf::Event::Closed){
            std::cout << "the game has been closed" << std::endl;
            this->Window->destroy();
            client->SEND(client->b.Encode("Exit"));
            client->Shutdown_Threads();
            exit(1);

        }
        if ((event.event.mouseButton.button == sf::Mouse::Left) &&
            (event.event.mouseButton.x > 935) && (event.event.mouseButton.x < 1155) &&
            (event.event.mouseButton.y > 650) && (event.event.mouseButton.y < 750)){
                this->Window->destroy();
                this->client->SEND(client->b.Encode("Exit"));
                exit(0);
        }
        
    }

    //buttons_position(this);

    animate_bg(this);
    this->Window->draw(this->MainMenuBackground);
    this->Window->draw(this->PlayButton);
    this->Window->draw(this->SettingsButton);
    this->Window->draw(this->HelpButton);
    this->Window->draw(this->QuitButton);
    if (display_arrow(this) == true)
        this->Window->draw(this->ArrowButton);
    this->Window->window->display();
}
