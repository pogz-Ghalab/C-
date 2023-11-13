/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** get_keys
*/

#include "../include/Game.hpp"

void get_keys(Game *game, sf::Event *event)
{
    if (event->type == sf::Event::KeyPressed && game->active_stop != true)
        if (event->key.code == sf::Keyboard::Left){
            game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",L"));
        }
        else if (event->key.code == sf::Keyboard::Right && game->active_stop != true){
            game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",R"));
            game->MainPlayerSprite->at(game->sights)->sprite->setRotation(0);
        }
        else if (event->key.code == sf::Keyboard::Up && game->active_stop != true){
            game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",U"));
            game->MainPlayerSprite->at(game->sights)->sprite->setRotation(-30);     
        }
        else if (event->key.code == sf::Keyboard::Down && game->active_stop != true){
            game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",D"));
            game->MainPlayerSprite->at(game->sights)->sprite->setRotation(30);     
        }
        else if (event->key.code == sf::Keyboard::Space){
            if (game->getkeytime.getElapsedTime().asSeconds() > 0.1f){

                game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",S"));
                game->Bullet_sound.play();
                game->Bullet_sound.setVolume(40.f);
                game->bullet_shot = true;
                game->getkeytime.restart();
            }
        }
        else if (event->key.code == sf::Keyboard::RShift){
            game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",I"));
        }
        else if (event->key.code == sf::Keyboard::LShift){
            game->client->SEND(game->client->b.Encode(*game->client->GetUsername() + ",O"));
        }
        else if (event->key.code == sf::Keyboard::Num1){
            game->sights = Sights::Normal;

        }
        else if (event->key.code == sf::Keyboard::Num2){
            game->sights = Sights::Night;

        }
        else if (event->key.code == sf::Keyboard::Num3){
            game->sights = Sights::Thermal;
        }
}
