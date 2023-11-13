/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** power_ups
*/

#include "../include/Game.hpp"
#include "../include/SFML.hpp"

using std::vector;

void power_ups(Game *game, std::vector<std::string> gamedata)
{
    for (int i = 0; i < gamedata.size(); i += 1) {
        if (gamedata[i] == "POWERUP") {
            if (gamedata[i + 1] == "HEART") {
                game->poweUp_heart->SetPositionAndScale(stoi(gamedata[i + 2]), stoi(gamedata[i + 3]), 1, 1);
                game->Window->draw(game->poweUp_heart);

            }
            if (gamedata[i + 1] == "SHIELD") {
                game->poweUp_shield->SetPositionAndScale(stoi(gamedata[i + 2]), stoi(gamedata[i + 3]), 0.7, 0.7);
                game->Window->draw(game->poweUp_shield);
            }
            if (gamedata[i + 1] == "STOP") {
                game->poweUp_stop->SetPositionAndScale(stoi(gamedata[i + 2]), stoi(gamedata[i + 3]), 0.7, 0.7);
                game->Window->draw(game->poweUp_stop);
            }
        }
    }
}

