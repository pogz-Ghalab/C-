/*
** EPITECH PROJECT, 2023
** R-type 
** File description:
** tools for the r-type project 
*/


#include "../include/Game.hpp"
#include "../include/SFML.hpp"

// CODE TO DISPLAY BUTTONS

// arrow display condition
//CODE TO DISPLAY BUTTONS

//arrow display condition
bool look_arrow_position(sf::Sprite sprite, Game *game, int pos_x, int pos_y)
{
    if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*game->Window->window).x, sf::Mouse::getPosition(*game->Window->window).y)){
        game->ArrowButton->SetPositionAndScale(pos_x, pos_y, 0.2, 0.2);
        return (true);
    }
    return (false);
}

// buttons position and scale
void buttons_position(Game *game)
{
    game->PlayButton->SetPositionAndScale(935, 350, 0.7, 0.7);
    game->SettingsButton->SetPositionAndScale(935, 450, 0.7, 0.7);
    game->HelpButton->SetPositionAndScale(935, 550, 0.7, 0.7);
    game->QuitButton->SetPositionAndScale(935, 650, 0.7, 0.7);
}

int Dir_to_Degree(char Direction)
{
    switch (Direction)
    {
        case 'N':
            return 0;
        case 'E':
            return 90;
        case 'S':
            return 180;
        case 'W':
            return 270;
    }
}