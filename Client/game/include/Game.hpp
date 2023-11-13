/*
** EPITECH PROJECT, 2023
** R-type project
** File description:
** sprities for the game
*/

#ifndef SPRITES_GRAPHICAL_HPP_
#define SPRITES_GRAPHICAL_HPP_
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SFML.hpp"
#include "Game.hpp"
#include "../../main.hpp"
#include <time.h>

class Client;

enum State
{
    Inputs,
    MainMenu,
    HelpMe,
    SelectShip,
    CustomShip,
    Lobby,
    InGame,
    GameOver
};

enum Sights
{
    Normal,
    Night,
    Thermal
};

class Game
{
public:
    Sights sights = Sights::Normal;
    bool oncestart = true;

    SFML::Sprite *HelpBackground = new SFML::Sprite;
    sf::Music start_music;
    sf::Music lobby_music;
    sf::Music ingame_music1;
    sf::Music gameover_music;
    sf::SoundBuffer Bullet_soundb;
    sf::Sound Bullet_sound;
    std::string msgFromClient = "x";

    sf::Sprite *main_ship; // = new SFML::Sprite;
    int selected = 1;

    /*------------------- Client Class Pointer --------------------*/
    Client *client = NULL; // remember to initialize this because seg fault
    int state = State::MainMenu;

    SFML::Window *Window = NULL;
    /*------------------- main menu --------------------*/

    SFML::Sprite *MainMenuBackground = new SFML::Sprite;
    SFML::Sprite *PlayButton = new SFML::Sprite;
    SFML::Sprite *SettingsButton = new SFML::Sprite;
    SFML::Sprite *HelpButton = new SFML::Sprite;
    SFML::Sprite *QuitButton = new SFML::Sprite;
    SFML::Sprite *ArrowButton = new SFML::Sprite;

    sf::Clock clock; // these are needed to animate main menu bg
    sf::Clock enemy_clock;
    sf::Clock drone_clock;
    sf::Clock lazer_clock_1;
    sf::Clock lazer_clock_2;

    int bg_x = 0;
    int bg_y = 0;

    /*---------------In game ------------------------------*/

    sf::Sprite display_ingame;
    int ingame_bg_x = 0;
    int ingame_bg_y = 0;

    SFML::Sprite *player = new SFML::Sprite;

    /*----------------select menu---------------------------*/

    SFML::Sprite *SelectMenuBackground = new SFML::Sprite;
    SFML::Sprite *SelectButton = new SFML::Sprite;
    SFML::Sprite *SelectPressButton = new SFML::Sprite;

    /*----------------lobby menu---------------------------*/
    SFML::Button *ReadyLobbyButton = new SFML::Button(680, 760, 172, 72, true);

    SFML::Sprite *LobbyBackground = new SFML::Sprite;
    SFML::Sprite *ReadyButton = new SFML::Sprite;
    SFML::Sprite *NotReadyButton = new SFML::Sprite;
    SFML::Sprite *CurrentButton = new SFML::Sprite;
    sf::Font lobbyfont;
    sf::Text lobbyText;

    std::string data_from_server;
    std::vector<std::string> splited_data;
    sf::Clock lobby_clock;
    sf::Text LobbyPlayerName;
    /*---------------design ship----------------------------*/
    std::vector<SFML::Sprite *> ship1_design1;
    std::vector<SFML::Sprite *> ship1_design2;
    std::vector<SFML::Sprite *> ship1_design3;
    std::vector<SFML::Sprite *> ship1_design4;

    std::vector<SFML::Sprite *> ship2_design1;
    std::vector<SFML::Sprite *> ship2_design2;
    std::vector<SFML::Sprite *> ship2_design3;
    std::vector<SFML::Sprite *> ship2_design4;

    std::vector<SFML::Sprite *> ship3_design1;
    std::vector<SFML::Sprite *> ship3_design2;
    std::vector<SFML::Sprite *> ship3_design3;
    std::vector<SFML::Sprite *> ship3_design4;

    std::vector<SFML::Sprite *> ship4_design1;
    std::vector<SFML::Sprite *> ship4_design2;
    std::vector<SFML::Sprite *> ship4_design3;
    std::vector<SFML::Sprite *> ship4_design4;
    SFML::Sprite *desginShip_bg = new SFML::Sprite;
    int change_ship = 0;
    int slct = 0;

    /*------------------- Inputs Screen--------------------*/
    int activeTextBox = 0;
    // Font
    sf::Font inputsFont;
    sf::Font buttonFont;

    // IP Address
    SFML::Text ipText;
    SFML::RectangleShape ipTextBox;
    
    SFML::RectangleShape inputButton;
    SFML::Text inputButtonText;
    std::string ipInputString;
    SFML::Text defaultText;

    // Username
    SFML::Text usernameText;
    SFML::RectangleShape usernameTextBox;
    std::string usernameInputString;

    sf::FloatRect ipRect;
    sf::FloatRect usernameRect;

    // Background
    SFML::Sprite *InputsBackgroundSprite = new SFML::Sprite;
    std::vector<SFML::Sprite *> Rock;

    // std::vector<SFML::Sprite *> InGameBackground;

    /*---------------In game ------------------------------*/

    std::vector<SFML::Sprite *> *MainPlayerSprite = new std::vector<SFML::Sprite *>;

    std::vector<SFML::Sprite *> Bullet1;
    std::vector<SFML::Sprite *> PowerBullet;
    std::vector<SFML::Sprite *> DroneBullet;
    std::vector<SFML::Sprite *> LazerBullet_start;
    std::vector<SFML::Sprite *> LazerBullet_end;
    std::vector<SFML::Sprite *> aid_drone;

    std::vector<SFML::Sprite *> Ship_1;
    std::vector<SFML::Sprite *> Ship_2;
    std::vector<SFML::Sprite *> Ship_3;
    std::vector<SFML::Sprite *> Ship_4;

    std::vector<SFML::Sprite *> Player_1;
    std::vector<SFML::Sprite *> Player_2;
    std::vector<SFML::Sprite *> Player_3;
    std::vector<SFML::Sprite *> Player_4;

    std::vector<SFML::Sprite *> Enemy_1;
    std::vector<SFML::Sprite *> Enemy_2;

    SFML::Sprite *Snake_Head = new SFML::Sprite;
    SFML::Sprite *Snake_Node = new SFML::Sprite;
    SFML::Sprite *Snake_Tail = new SFML::Sprite;


    bool bullet_shot = false;

    SFML::Sprite *Boss2 = new SFML::Sprite;
    SFML::Sprite *Boss3 = new SFML::Sprite;

    SFML::Sprite *Enemy2 = new SFML::Sprite;
    SFML::Sprite *Enemy3 = new SFML::Sprite;

    SFML::Sprite *EnemyBullet = new SFML::Sprite;
    SFML::Sprite *ShootingAnimation = new SFML::Sprite;

    int player_x = 0;
    int player_y = 0;

    SFML::Sprite *Skull = new SFML::Sprite;

    //healht and powerups
    SFML::Sprite *health = new SFML::Sprite;
    SFML::Sprite *poweUp_heart = new SFML::Sprite;
    SFML::Sprite *poweUp_shield = new SFML::Sprite;
    SFML::Sprite *poweUp_stop = new SFML::Sprite;
    SFML::Sprite *poweUp_drone = new SFML::Sprite;

    std::vector<SFML::Sprite *> InGameBackground;

    sf::Clock getkeytime;
    sf::Clock shooting_animation;
    int shooting_animation_x = 0;
    
    sf::Clock boss2_animation;
    int boss2_animation_x = 0;

    SFML::Sprite *Info = new SFML::Sprite;

    /*--------------game over-----------------*/

    SFML::Sprite *GameOverBackground = new SFML::Sprite;

    /*-----------------------------------------*/

    int test = 0;

        /*-----------------------------------------*/
        
        int rect_health_y = 20;
        int damage_player = 0;
        int damage = 0;
        bool active_stop = false;
        bool drone_active = false;
        bool active_shield = false;
    // GAME STATE

    /*-----------------------------------------*/
    bool lazer_type = false;
    int rect_x = 0;
    int rect_enemy_x = 0;
    int rect_player_y = 0;
    int rect_drone_x = 0;
    /*-------------------------------------*/
    int rect_startlazer_x = 0;
    int rect_endlazer_x = 0;
    int rect_player_x = 0;
    int ship_select = 0;

    /*---------State Functions----------------------------*/
    void Inputs();
    void MainMenu();
    void SelectShip();
    void CustomShip();
    void Lobby();
    void GameOver();
    void InGame();
    bool look_arrow_position(sf::Sprite sprite, int pos_x, int pos_y);
    void HelpMe();
};

void initalize_game(Game *game);
void call_animations(Game *game);
sf::IntRect animate_player(Game *game, sf::IntRect rect_player);
sf::IntRect animate_enemy(Game *game, sf::IntRect rect_enemy);
sf::IntRect animate_drone(Game *game, sf::IntRect rect_drone);
sf::IntRect animate_lazershot_1(Game *game, sf::IntRect rect_lazer);
sf::IntRect animate_lazershot_2(Game *game, sf::IntRect rect_lazer);

std::vector<std::string> split_data(std::string str, const char *delim);
void get_keys(Game *game, sf::Event *event);
void call_animations(Game *game);
int Dir_to_Degree(char Direction);
void change_health_display(Game *game);
void power_ups(Game *game, std::vector<std::string> gamedata);

#endif /* !SPRITES_GRAPHICAL_HPP_ */
