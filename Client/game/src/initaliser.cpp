/*
** EPITECH PROJECT, 2023
** R-type Project
** File description:
** Initialising functions
*/

#include "../include/Game.hpp"
#include "../include/SFML.hpp"

// FUNCTION THAT INITIALIZES SPRITES


void initalize_music(Game *game)
{
    game->start_music.openFromFile("res/Music/Start_game.ogg");
    game->ingame_music1.openFromFile("res/Music/ingame1.ogg");
   // game->gameover_music.openFromFile("res/Music/game_over.ogg");
    game->Bullet_soundb.loadFromFile("res/Music/Gun_shot.wav");
    game->Bullet_sound.setBuffer(game->Bullet_soundb);
}

void initalize_powerUps(Game *game)
{
    game->poweUp_heart->CreateSprite("res/InGame-normal/heart.png");
    game->poweUp_shield->CreateSprite("res/InGame-normal/shield.png");
    game->poweUp_stop->CreateSprite("res/InGame-normal/stop.png");
    game->poweUp_drone->CreateSprite("res/InGame-normal/drone.png");
    game->Skull->CreateSprite("res/InGame-normal/Skull.png");
}

void initGameOver(Game *game)
{
    game->GameOverBackground->CreateSprite("res/GameOver/GameOverBackground.png");
}

void initSelectMenu(Game *game)
{
    game->SelectMenuBackground->CreateSprite("res/SelectMenu/background.png");
    game->SelectPressButton->CreateSprite("res/SelectMenu/PressButton.png");
    game->SelectButton->CreateSprite("res/SelectMenu/SelectButton.png");
}

void initVisions(int i, SFML::Sprite *a, std::string normal, std::string night, std::string thermal, int x, int y, float sx, float sy)
{
    string m;
    if (i == 0)
    {
        m = normal;
    }
    else if (i == 1)
    {
        m = night;
    }
    else if (i == 2)
    {
        m = thermal;
    }
    a->CreateSprite(m.c_str());
    a->CropSprite(x, y, sx, sy);
}

void initInGame(Game *game)
{
    game->Snake_Head->CreateSprite("res/InGame-normal/Snake_Head.png");
    game->Snake_Node->CreateSprite("res/InGame-normal/Snake_Node.png");
    game->Snake_Tail->CreateSprite("res/InGame-normal/Snake_Tail.png");
    game->EnemyBullet->CreateSprite("res/InGame-normal/EnemyBullet.png");
    game->ShootingAnimation->CreateSprite("res/InGame-normal/ShootingAnimation.png");
    game->Boss2->CreateSprite("res/InGame-normal/Boss2.png");
    game->Boss3->CreateSprite("res/InGame-normal/Boss3.png");
    game->Enemy2->CreateSprite("res/InGame-normal/Enemy2.png");
    game->Enemy3->CreateSprite("res/InGame-normal/Enemy3.png");
    game->Info->CreateSprite("res/InGame-normal/Info.png");
    for (int i = 0; i < 3; i++)
    {
        game->Bullet1.push_back(new SFML::Sprite);
        if (i == 0)
        {
            game->Bullet1.at(i)->CreateSprite("res/InGame-normal/bullet.png");
        }
        else if (i == 1)
        {
            game->Bullet1.at(i)->CreateSprite("res/InGame-nightvision/bullet.png");
        }
        else if (i == 2)
        {
            game->Bullet1.at(i)->CreateSprite("res/InGame-infrared/bullet.png");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        game->Rock.push_back(new SFML::Sprite);
        if (i == 0)
        {
            game->Rock.at(i)->CreateSprite("res/InGame-normal/rock.png");
        }
        else if (i == 1)
        {
            game->Rock.at(i)->CreateSprite("res/InGame-nightvision/rock.png");
        }
        else if (i == 2)
        {
            game->Rock.at(i)->CreateSprite("res/InGame-infrared/rock.png");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        game->Ship_1.push_back(new SFML::Sprite);
        initVisions(i, game->Ship_1.at(i), "res/InGame-normal/animation_1.png", "res/InGame-nightvision/animation_1.png", "res/InGame-infrared/animation_1.png", 0, 0, 128, 128);
    }
    for (int i = 0; i < 3; i++)
    {
        game->Ship_2.push_back(new SFML::Sprite);
        initVisions(i, game->Ship_2.at(i), "res/InGame-normal/animation_2.png", "res/InGame-nightvision/animation_2.png", "res/InGame-infrared/animation_2.png", 0, 0, 128, 128);
    }
    for (int i = 0; i < 3; i++)
    {
        game->Ship_3.push_back(new SFML::Sprite);
        initVisions(i, game->Ship_3.at(i), "res/InGame-normal/animation_3.png", "res/InGame-nightvision/animation_3.png", "res/InGame-infrared/animation_3.png", 0, 0, 128, 128);
    }
    for (int i = 0; i < 3; i++)
    {
        game->Ship_4.push_back(new SFML::Sprite);
        initVisions(i, game->Ship_4.at(i), "res/InGame-normal/animation_4.png", "res/InGame-nightvision/animation_4.png", "res/InGame-infrared/animation_4.png", 0, 0, 128, 128);
    }
    for (int i = 0; i < 3; i++)
    {
        game->Enemy_1.push_back(new SFML::Sprite);
        initVisions(i, game->Enemy_1.at(i), "res/InGame-normal/enemy_1.png", "res/InGame-nightvision/enemy_1.png", "res/InGame-infrared/enemy_1.png", 0, 0, 340, 340);
    }
    for (int i = 0; i < 3; i++)
    {
        game->Enemy_2.push_back(new SFML::Sprite);
        initVisions(i, game->Enemy_2.at(i), "res/InGame-normal/enemy_2.png", "res/InGame-nightvision/enemy_2.png", "res/InGame-infrared/enemy_2.png", 0, 0, 340, 340);
    }
    for (int i = 0; i < 3; i++)
    {
        game->InGameBackground.push_back(new SFML::Sprite);
        if (i == 0)
        {
            game->InGameBackground.at(i)->CreateSprite("res/InGame-normal/background.png");
        }
        else if (i == 1)
        {
            game->InGameBackground.at(i)->CreateSprite("res/InGame-nightvision/background.png");
        }
        else if (i == 2)
        {
            game->InGameBackground.at(i)->CreateSprite("res/InGame-infrared/background.png");
        }
    }
    game->health->CreateSprite("res/InGame-normal/health.png");
    game->health->SetPositionAndScale(1200, 790, 0.7, 0.7);
    
/* 
    game->Bullet1->CreateSprite("res/InGame-normal/bullet.png");
    game->Bullet1->SetPositionAndScale(0, 0, 0.2, 0.2);
    game->Ship_1->CreateSprite("res/InGame-normal/animation_1.png");
    game->Ship_1->CropSprite(0, 0, 128, 128);
    game->Ship_2->CreateSprite("res/InGame-normal/animation_2.png");
    game->Ship_2->CropSprite(0, 0, 128, 128);
    game->Ship_3->CreateSprite("res/InGame-normal/animation_3.png");
    game->Ship_3->CropSprite(0, 0, 128, 128);
    game->Ship_4->CreateSprite("res/InGame-normal/animation_4.png");
    game->Ship_4->CropSprite(0, 0, 128, 128);
    game->Enemy_1->CreateSprite("res/InGame-normal/enemy_1.png");
    game->Enemy_1->CropSprite(67, 145, 50, 100);
    game->Enemy_2->CreateSprite("res/InGame-normal/enemy_1.png");
    game->Enemy_2->CropSprite(67, 145, 50, 100);
    game->InGameBackground->CreateSprite("res/InGame-normal/background.png"); */
    game->PowerBullet.push_back(new SFML::Sprite);
    game->PowerBullet.at(0)->CreateSprite("res/InGame-normal/PowerBullet.png");

    game->DroneBullet.push_back(new SFML::Sprite);
    game->DroneBullet.at(0)->CreateSprite("res/InGame-normal/DroneBullet.png");

    game->LazerBullet_start.push_back(new SFML::Sprite);
    game->LazerBullet_start.at(0)->CreateSprite("res/InGame-normal/Lazer_start.png");

    game->LazerBullet_end.push_back(new SFML::Sprite);
    game->LazerBullet_end.at(0)->CreateSprite("res/InGame-normal/end_lazer.png");
    
    game->aid_drone.push_back(new SFML::Sprite);
    game->aid_drone.at(0)->CreateSprite("res/InGame-normal/aid_drone.png");
}

void init_designShip(Game *game)
{
    game->desginShip_bg->CreateSprite("res/customize_ship/Design_ship_bg.png");
    //------------------------------ship1------------------------------
    game->ship1_design1.push_back(new SFML::Sprite);
    game->ship1_design1.at(0)->CreateSprite("res/customize_ship/ship1/s1_green.png");
    game->ship1_design2.push_back(new SFML::Sprite);
    game->ship1_design2.at(0)->CreateSprite("res/customize_ship/ship1/s1_blue.png");
    game->ship1_design3.push_back(new SFML::Sprite);
    game->ship1_design3.at(0)->CreateSprite("res/customize_ship/ship1/s1_purple.png");
    game->ship1_design4.push_back(new SFML::Sprite);
    game->ship1_design4.at(0)->CreateSprite("res/customize_ship/ship1/s1_black.png");

    //-----------------------------ship2------------------------------------
    game->ship2_design1.push_back(new SFML::Sprite);
    game->ship2_design1.at(0)->CreateSprite("res/customize_ship/ship2/s2_green.png");
    game->ship2_design2.push_back(new SFML::Sprite);
    game->ship2_design2.at(0)->CreateSprite("res/customize_ship/ship2/s2_blue.png");
    game->ship2_design3.push_back(new SFML::Sprite);
    game->ship2_design3.at(0)->CreateSprite("res/customize_ship/ship2/s2_purple.png");
    game->ship2_design4.push_back(new SFML::Sprite);
    game->ship2_design4.at(0)->CreateSprite("res/customize_ship/ship2/s2_black.png");

    //-----------------------------ship3------------------------------------
    game->ship3_design1.push_back(new SFML::Sprite);
    game->ship3_design1.at(0)->CreateSprite("res/customize_ship/ship3/s3_green.png");
    game->ship3_design2.push_back(new SFML::Sprite);
    game->ship3_design2.at(0)->CreateSprite("res/customize_ship/ship3/s3_blue.png");
    game->ship3_design3.push_back(new SFML::Sprite);
    game->ship3_design3.at(0)->CreateSprite("res/customize_ship/ship3/s3_purple.png");
    game->ship3_design4.push_back(new SFML::Sprite);
    game->ship3_design4.at(0)->CreateSprite("res/customize_ship/ship3/s3_black.png");

    //-----------------------------ship4------------------------------------
    game->ship4_design1.push_back(new SFML::Sprite);
    game->ship4_design1.at(0)->CreateSprite("res/customize_ship/ship4/s4_green.png");
    game->ship4_design2.push_back(new SFML::Sprite);
    game->ship4_design2.at(0)->CreateSprite("res/customize_ship/ship4/s4_blue.png");
    game->ship4_design3.push_back(new SFML::Sprite);
    game->ship4_design3.at(0)->CreateSprite("res/customize_ship/ship4/s4_purple.png");
    game->ship4_design4.push_back(new SFML::Sprite);
    game->ship4_design4.at(0)->CreateSprite("res/customize_ship/ship4/s4_black.png");
}

void initMainMenu(Game *game)
{
    game->MainMenuBackground->CreateSprite("res/MainMenu/background.png");
    game->PlayButton->CreateSprite("res/MainMenu/PlayButton.png");
    game->SettingsButton->CreateSprite("res/MainMenu/SettingsButton.png");
    game->HelpButton->CreateSprite("res/MainMenu/HelpButton.png");
    game->QuitButton->CreateSprite("res/MainMenu/QuitButton.png");
    game->ArrowButton->CreateSprite("res/MainMenu/ArrowButton.png");
    game->HelpBackground->CreateSprite("res/help/Help.png");

    game->PlayButton->SetPositionAndScale(935, 350, 0.7, 0.7);
    game->SettingsButton->SetPositionAndScale(935, 450, 0.7, 0.7);
    game->HelpButton->SetPositionAndScale(935, 550, 0.7, 0.7);
    game->QuitButton->SetPositionAndScale(935, 650, 0.7, 0.7);
}

void initLobby(Game *game)
{
    game->LobbyBackground->CreateSprite("res/Lobby/background.png");
    game->ReadyButton->CreateSprite("res/Lobby/ReadyButton.png");
    game->NotReadyButton->CreateSprite("res/Lobby/NotReadyButton.png");

    game->CurrentButton = new SFML::Sprite;
    *game->CurrentButton = *game->NotReadyButton;
    game->CurrentButton->SetPositionAndScale(680, 760, 0.3, 0.3);
    game->lobbyfont.loadFromFile("res/fonts/Roboto-BoldItalic.ttf");
}

void initInputs(Game *game)
{
    // Fonts
    game->inputsFont.loadFromFile("res/fonts/Roboto-BoldItalic.ttf");
    game->buttonFont.loadFromFile("res/fonts/arcadeclassic.regular.ttf");

    // IP address
    game->ipText.setFont(game->inputsFont);
    game->ipText.setCharacterSize(30);
    game->ipText.setFillColor(sf::Color::Black);

    game->ipTextBox.setSize(sf::Vector2f(300, 50));
    game->ipTextBox.setFillColor(sf::Color::White);
    game->ipTextBox.setOutlineThickness(2);
    game->ipTextBox.setOutlineColor(sf::Color::Black);
    game->ipTextBox.setRecPosition((game->Window->window->getSize().x / 2) - 110, (game->Window->window->getSize().y / 2) - 35);

    game->defaultText.setString("127.0.0.1");
    game->defaultText.setFont(game->inputsFont);
    game->defaultText.setCharacterSize(30);
    game->defaultText.setFillColor(sf::Color::Black);
    game->defaultText.setFillColor(sf::Color::Black);
    game->defaultText.setPosition(game->ipTextBox.getPosition() + sf::Vector2f(10, 10));

    game->inputButton.setSize(sf::Vector2f(300, 50));
    game->inputButton.setReccPosition(game->ipTextBox.getPosition() + sf::Vector2f(0, game->ipTextBox.getSize().y + 120)); // add 20 pixels of vertical spacing
    game->inputButton.setFillColor(sf::Color::Blue);

    game->inputButtonText.setString("Enter");
    game->inputButtonText.setFont(game->buttonFont);
    game->inputButtonText.setCharacterSize(30);
    game->inputButtonText.setFillColor(sf::Color::White);
    game->inputButtonText.setPosition(game->inputButton.getPosition() + sf::Vector2f((game->inputButton.getSize().x / 2) - 35, 5));

    // Username
    game->usernameText.setFont(game->inputsFont);
    game->usernameText.setCharacterSize(30);
    game->usernameText.setFillColor(sf::Color::Black);

    game->usernameTextBox.setSize(sf::Vector2f(300, 50));
    game->usernameTextBox.setFillColor(sf::Color::White);
    game->usernameTextBox.setOutlineThickness(2);
    game->usernameTextBox.setOutlineColor(sf::Color::Black);
    game->usernameTextBox.setRecPosition((game->Window->window->getSize().x / 2) - 110, (game->Window->window->getSize().y / 2) + 70);

    game->InputsBackgroundSprite->CreateSprite("res/Inputs/background.JPG");
}

void initalize_game(Game *game)
{
    string *WindowName = new string("R-Type");
    game->Window = new SFML::Window(1600, 900, WindowName);

    initMainMenu(game);

    initSelectMenu(game);

    init_designShip(game);

    initLobby(game);
    initInGame(game);
    initGameOver(game);
    initalize_music(game);
    initInputs(game);
    initalize_powerUps(game);

}

/* void initalize_game(Game *game)
{
    string *WindowName = new string("R-Type");
    game->Window = new SFML::Window(1600, 900, WindowName);

    std::cout << "Started Initializing" << std::endl;
    initMainMenu(game);
    std::cout << "passed here 1" << std::endl;

    initSelectMenu(game);
    std::cout << "passed here 2" << std::endl;

    init_designShip(game);
    std::cout << "passed here 3" << std::endl;

    initLobby(game);
    initInGame(game);
    initGameOver(game);
    initalize_music(game);
    initInputs(game);
    initalize_powerUps(game);
} */