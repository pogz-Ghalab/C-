/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** in game, playing the game (start off by being static)
*/

#include "../include/Game.hpp"
#include "../include/SFML.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

std::vector<std::string> split_data(std::string str, const char *delim);

sf::Vector2f get_sprite_coords(sf::Sprite sprite)
{
    sf::Vector2f position = sprite.getPosition();
    return (position);
}

void set_sprite_pos(Game *game)
{
    game->MainPlayerSprite->at(game->sights)->SetPositionAndScale(50, 450, 1.2, 1.2);
    game->Enemy_1.at(game->sights)->SetPositionAndScale(1300, 450, 1.3, 1.3);
    game->test = 1;
}

void Display_Snake(Game *game, char type, char direction, int x, int y)
{
    switch (type)
    {
    case 'H':
        game->Snake_Head->SetPositionAndScale(x, y + 200, 1, 1);
        game->Snake_Head->sprite->setRotation(Dir_to_Degree(direction));
        game->Window->draw(game->Snake_Head);
        break;
    case 'N':
        game->Snake_Node->SetPositionAndScale(x, y + 200, 1, 1);
        game->Snake_Node->sprite->setRotation(Dir_to_Degree(direction));
        game->Window->draw(game->Snake_Node);
        break;
    case 'T':
        game->Snake_Tail->SetPositionAndScale(x, y + 200, 1, 1);
        game->Snake_Tail->sprite->setRotation(Dir_to_Degree(direction));
        game->Window->draw(game->Snake_Tail);
        break;
    }
}
void display_health(Game *game, vector<string> gamedata)
{
    for (int i = 0; i < gamedata.size(); i += 1)
    {
        if (gamedata[i] == "H")
        {
            game->damage_player = 5 - stoi(gamedata[i + 1]);
            if (game->damage_player < 0)
                game->damage_player = 0;
        }
    }
    change_health_display(game);
    game->health->CropSprite(0, game->rect_health_y, 543, 85);
    game->Window->draw(game->health);
}

void display_entity(Game *game, string entity, int x, int y) // maybe y x
{
    /* if (gamedata.at(game->sights) == "DRONEACTIVE")
   {
       if (gamedata[game->sights + 1] == "1")
           game->drone_active = true;
       else
           game->drone_active = false;
   } */
    int yes = 0;
    if (entity == "DIED"){
        game->state = State::GameOver;
    }
    if (entity == *game->client->GetUsername())
    {
        cout << "----------check" << endl;
        game->MainPlayerSprite->at(game->sights)->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->MainPlayerSprite->at(game->sights));
        game->player_x = x;
        game->player_y = y;
        if (game->bullet_shot)
        {
            game->ShootingAnimation->SetPositionAndScale(x + 80, y - 35, 0.3, 0.3);
            game->Window->draw(game->ShootingAnimation);
        }
    }
    else if (entity == "DRONEACTIVE")
    {
        game->aid_drone.at(game->sights)->SetPositionAndScale(x, y, 0.6, 0.6);
        game->Window->draw(game->aid_drone.at(game->sights));
    }

    else if (entity == "E1")
    {
        game->Enemy_1.at(game->sights)->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->Enemy_1.at(game->sights));
    }
    else if (entity == "E2")
    {
        game->Enemy2->SetPositionAndScale(x, y, 0.3, 0.3);
        game->Window->draw(game->Enemy2);
    }
    else if (entity == "E3")
    {
        game->Enemy3->SetPositionAndScale(x, y, 0.1, 0.1);
        game->Window->draw(game->Enemy3);
    }
    else if (entity == "B1")
    {
        game->Bullet1.at(game->sights)->SetPositionAndScale(x - 5, y + 40, 0.1, 0.1);
        game->Window->draw(game->Bullet1.at(game->sights));
    }
    else if (entity == "B2")
    {
        game->PowerBullet.at(game->sights)->SetPositionAndScale(x - 5, y + 40, 0.1, 0.1);
        game->Window->draw(game->PowerBullet.at(game->sights));
    }
    else if (entity == "B3")
    {
        // the lazer bullet
        game->LazerBullet_start.at(game->sights)->SetPositionAndScale(x + 30, y, 3, 1);
        game->LazerBullet_end.at(game->sights)->SetPositionAndScale(x + 170, y, 6, 1);
        game->Window->draw(game->LazerBullet_start.at(game->sights));
        game->Window->draw(game->LazerBullet_end.at(game->sights));
    }
    else if (entity == "B4")
    {
        game->DroneBullet.at(game->sights)->SetPositionAndScale(x + 5, y - 30, 0.15, 0.15);
        game->Window->draw(game->DroneBullet.at(game->sights));
    }
    else if (entity == "P")
    {
        game->InGameBackground.at(game->sights)->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->InGameBackground.at(game->sights));
    }
    else if (entity == "OBSFLOOR")
    {
        game->Rock.at(game->sights)->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->Rock.at(game->sights));
    }
    else if (entity == "BOSS2")
    {
        game->Boss2->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->Boss2);
    }
    else if (entity == "BS3")
    {
        game->Boss3->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->Boss3);
    }
    else if (entity == "EB1")
    {
        game->EnemyBullet->SetPositionAndScale(x, y, 0.2, 0.2);
        game->Window->draw(game->EnemyBullet);
    }
    else if (entity[0] == 'S' && entity[1] == '_')
    {
        Display_Snake(game, entity[2], entity[3], x, y);
    }
    else if (entity == "HEART")
    {
        game->poweUp_heart->SetPositionAndScale(x, y, 0.7, 0.7);
        game->Window->draw(game->poweUp_heart);
    }
    else if (entity == "SHIELD")
    {
        game->poweUp_shield->SetPositionAndScale(x, y, 0.1, 0.1);
        game->Window->draw(game->poweUp_shield);
    }
    else if (entity == "STOP")
    {
        game->poweUp_stop->SetPositionAndScale(x, y, 0.1, 0.1);
        game->Window->draw(game->poweUp_stop);
    }
    else if (entity == "DRONE")
    {

        game->poweUp_drone->SetPositionAndScale(x, y, 0.25, 0.25);
        game->Window->draw(game->poweUp_drone);
    }
    else if (entity == "SHIELDACTIVE")
    {
        game->poweUp_shield->SetPositionAndScale(x, y, 0.4, 0.4);
        game->Window->draw(game->poweUp_shield);
    }
    else if (entity == "STOPACTIVE")
    {
        game->Skull->SetPositionAndScale(x, y, 0.6, 0.6);
        game->Window->draw(game->Skull);
    }
    else
    {
        game->Ship_1.at(game->sights)->SetPositionAndScale(x, y, 1, 1);
        game->Window->draw(game->Ship_1.at(game->sights));
    }
}

void active_powerups(vector<string> gamedata, int i, Game *game)
{

    /*
     if (game->drone_active == true)
         printf("ACTIVE\n"); */
}

void DRAW_SPRITES(Game *game)
{
    if (game->msgFromClient == "x")
        return;
    vector<string> gamedata = split_data(game->msgFromClient, ",");
    if (gamedata.at(0) != "Game")
        return;
    gamedata.erase(gamedata.begin());
    // power_ups(game, gamedata);
    for (int i = 0; i < gamedata.size();)
    {
        // if (gamedata.at(i) != "H" && gamedata.at(i) != "SHIELDACTIVE" && gamedata.at(i) != "STOPACTIVE") {
        if (gamedata.at(i) != "H")
        {
            display_entity(game, gamedata.at(i), stoi(gamedata.at(i + 1)), stoi(gamedata.at(i + 2)));
            i = i + 3;
        }
        else
            i = i + 2;
    }

    display_health(game, gamedata);
}

void Game::InGame()
{
    SFML::Event event;

    while (this->Window->eventloop(&event))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O))
        {
            this->state = 4;
        }
        if (event.event.type == sf::Event::Closed)
        {
            this->Window->destroy();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        {
            std::cout << "You have quitted the game" << std::endl;
            this->client->SEND(client->b.Encode("Exit"));
            this->Window->destroy();
            exit(1);
        }
        // if (std::clock() - getkeytime > 300000)
        //{
        get_keys(this, &event.event);
        //    getkeytime = std::clock();
        //}
    }
    this->start_music.stop();
    this->ingame_music1.setLoop(true);
    this->ingame_music1.setVolume(35.f);
    this->Window->window->clear(sf::Color::Black);
    call_animations(this);
    DRAW_SPRITES(this);
    // this->window.window.draw(this->main_player);
    // this->window.window.draw(this->enemy);

    // this->start_music.stop();
    this->Info->SetPositionAndScale(20, 700, 0.2, 0.2);
    this->Window->draw(this->Info);

    // this->start_music.stop();

    this->Window->window->display();
}
