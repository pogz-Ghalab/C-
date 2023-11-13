/*
** EPITECH PROJECT, 2022
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** animations_sprites.cpp
*/

#include "../include/Game.hpp"

sf::IntRect animate_player(Game *game, sf::IntRect rect_player, int frame, int max)
{
    if (game->clock.getElapsedTime().asSeconds() > 0.1f)
    {
        if (game->rect_player_y >= max)
        {
            game->rect_player_y = 0;
        }
        else
        {
            game->rect_player_y += frame;

            game->MainPlayerSprite->at(game->sights)->sprite->setTextureRect(rect_player);
        }
        game->clock.restart();
    }
    return (rect_player);
}

sf::IntRect animate_player_sheep2(Game *game, sf::IntRect rect_player)
{
    if (game->clock.getElapsedTime().asSeconds() > 0.1f)
    {
        if (game->rect_player_y >= 100)
        {
            game->rect_player_y = 0;
        }
        else
        {
            game->rect_player_y += 32;

            game->Player_1.at(game->sights)->sprite->setTextureRect(rect_player);
        }
    }
    return (rect_player);
}

void change_health_display(Game *game)
{    
        if (game->damage < game->damage_player ) {
            game->damage++;
            game->rect_health_y = game->rect_health_y + 90;
        }
        if (game->damage > game->damage_player && game->damage_player != 5) {
            game->damage--;
            game->rect_health_y = game->rect_health_y - 90;
        }
}

sf::IntRect animate_enemy(Game *game, sf::IntRect rect_enemy)
{
    if (game->enemy_clock.getElapsedTime().asSeconds() > 0.05f)
    {
        if (game->rect_enemy_x >= 1700)
        {
            game->rect_enemy_x = 0;
        }
        else
        {
            game->rect_enemy_x += 340;

            game->Enemy_1.at(game->sights)->sprite->setTextureRect(rect_enemy);
        }
        game->enemy_clock.restart();
    }
    return (rect_enemy);
}
// y = 190
sf::IntRect animate_drone(Game *game, sf::IntRect rect_drone)
{

    if (game->drone_clock.getElapsedTime().asSeconds() > 0.05f)
    {

        if (game->rect_drone_x >= game->aid_drone.at(game->sights)->texture->getSize().x)
        {

            game->rect_drone_x = 0;
        }
        else
        {

            game->rect_drone_x += 192;

            game->aid_drone.at(game->sights)->sprite->setTextureRect(rect_drone);
        }
        game->drone_clock.restart();
    }
    return (rect_drone);
}

sf::IntRect animate_lazershot_1(Game *game, sf::IntRect rect_lazer_start)
{
    if(game->lazer_clock_1.getElapsedTime().asSeconds() > 0.05f)
    {
        if(game->rect_startlazer_x >= game->LazerBullet_start.at(game->sights)->texture->getSize().x)
        {
            game->rect_startlazer_x = 0;
        } else {
            game->rect_startlazer_x += 136;
            game->LazerBullet_start.at(game->sights)->sprite->setTextureRect(rect_lazer_start);
        }
        //end of first if
        game->lazer_clock_1.restart();
    }
    return(rect_lazer_start);
}

sf::IntRect animate_lazershot_2(Game *game, sf::IntRect rect_lazer_end)
{
    if(game->lazer_clock_2.getElapsedTime().asSeconds() > 0.05f)
    {
        if(game->rect_endlazer_x >= game->LazerBullet_end.at(game->sights)->texture->getSize().x)
        {
            game->rect_endlazer_x = 0;
        } else {
            game->rect_endlazer_x += 233;
            game->LazerBullet_end.at(game->sights)->sprite->setTextureRect(rect_lazer_end);
        }
        game->lazer_clock_2.restart();
    }
    return(rect_lazer_end);
}

void animate_shooting(Game *game, sf::IntRect rect_shooting)
{

    if (game->shooting_animation.getElapsedTime().asSeconds() > 0.06f){
        if (game->shooting_animation_x > 1500) {
            game->shooting_animation_x = 0;
            game->bullet_shot = false;
        } else {
            game->shooting_animation_x += 381;
            game->ShootingAnimation->sprite->setTextureRect(rect_shooting);
        }
        game->shooting_animation.restart();
    }
}

void animate_boss2(Game *game, sf::IntRect rect_boss2)
{
    if (game->boss2_animation.getElapsedTime().asSeconds() > 0.1f){
        if (game->boss2_animation_x > 15100) {
            game->boss2_animation_x = 0;
        } else {
            game->boss2_animation_x += 631;
            game->Boss2->sprite->setTextureRect(rect_boss2);
        }
        game->boss2_animation.restart();
    }
}

void call_animations(Game *game)
{

    sf::IntRect rect_player_1(0, game->rect_player_y, 128, 128);
    sf::IntRect rect_player_2(0, game->rect_player_y, 128, 128);
    sf::IntRect rect_player_3(0, game->rect_player_y, 128, 128);
    sf::IntRect rect_player_4(0, game->rect_player_y, 128, 128);
    sf::IntRect rect_aiddrone(game->rect_drone_x, 0, 190, 177);

    sf::IntRect rect_enemy(0, game->rect_enemy_x, 340, 340);
    sf::IntRect rect_lazerstart(game->rect_startlazer_x, 0, 134, 107);
    sf::IntRect rect_lazerstart_2(game->rect_endlazer_x, 0, 233, 107);
    rect_enemy = animate_enemy(game, rect_enemy);
    // rect_enemy = animate_enemy(game, rect_enemy);
    rect_lazerstart = animate_lazershot_1(game, rect_lazerstart);
    rect_lazerstart_2 = animate_lazershot_2(game, rect_lazerstart_2);
    if (game->ship_select != 0)
        rect_aiddrone = animate_drone(game, rect_aiddrone);
    
    sf::IntRect a(game->shooting_animation_x, 0, 381, 650);

    sf::IntRect rect_boss2(game->boss2_animation_x, 0, 631, 482);


    rect_enemy = animate_enemy(game, rect_enemy);
    animate_boss2(game, rect_boss2);

    if (game->ship_select == 1)
        rect_player_1 = animate_player(game, rect_player_1, 128, 512);
    if (game->ship_select == 2)
        rect_player_2 = animate_player(game, rect_player_2, 128, 512);
    if (game->ship_select == 3)
        rect_player_3 = animate_player(game, rect_player_3, 128, 512);
    if (game->ship_select == 4)
        rect_player_4 = animate_player(game, rect_player_4, 128, 512);
    
    if (game->bullet_shot == true){
        animate_shooting(game, a);
    }
} 

