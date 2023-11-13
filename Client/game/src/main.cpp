/*
** EPITECH PROJECT, 2023
** main
** File description:
** game r-type
*/

#include <iostream>
#include "../include/SFML.hpp"
#include "../include/Game.hpp"
#include "../../main.hpp"

void main_loop(Client *client, Game *game)
{
    if (game->state == State::MainMenu || game->state == State::SelectShip)
    {
        // COMMENTING MUSIC TEMPORARILY
        // game->start_music.play();
    }

    game->start_music.play();
    while (game->Window->isOpen())
    {
        if (game->state == State::MainMenu)
        {
            game->MainMenu();
        }
        else if (game->state == State::Inputs)
        {
            game->Inputs();
        }
        else if (game->state == State::SelectShip)
        {
            game->SelectShip();
        }
        else if (game->state == State::CustomShip)
        {
            game->CustomShip();
        }
        else if (game->state == State::HelpMe)
        {
            game->HelpMe();
        }
        else if (game->state == State::Lobby)
        {
            game->Lobby();
        }
        else if (game->state == State::InGame)
        {
            
            game->InGame();
        }
        else if (game->state == State::GameOver)
        {
            game->GameOver();
        }
    }
}

int MainGame(Client *client)
{

    initalize_game(client->game);

    main_loop(client, client->game);
}
