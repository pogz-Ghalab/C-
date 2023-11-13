/*
** EPITECH PROJECT, 2023
** R-type project
** File description:
** sprities for the game
*/

#ifndef SPRITES_GRAPHICAL_HPP_
#define SPRITES_GRAPHICAL_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.hpp"
#include "Sprites_graphical.hpp"
#include "../../main.hpp"

enum State
{
    MainMenu,
    SelectShip,
    HelpMe,
    Lobby,
    InGame,
    GameOver
};

class testt
{
    public:
        sf::Sprite ship1;
        sf::Texture ship1_t;
        sf::Sprite ship2;
        sf::Texture ship2_t;
        sf::Sprite ship3;
        sf::Texture ship3_t;
        sf::Sprite ship4;
        sf::Texture ship4_t;
        
};

class Button
{
    public:
        bool active = false;
        Button(int _x, int _y, int _width, int _height, bool _active) : 
        x(_x), y(_y), width(_width), height(_height), active(_active) { }

        bool isButtonClicked(int my, int mx){
            if (my >= y && my <= y + height && mx >= x && mx <= x + width){
                return true;
            }
            return false;
        }
        sf::Sprite sprite;
        int x;
        int y; 
        int width;
        int height;
    private:
        
};
/*
class music_sounds
{
    public:

    sf::Music start_sound;
};
*/

class game_sprites
{
public:

    std::string *msgFromClient;

    sf::Sprite *main_ship;
    int selected = 1;

    /*------------------- Client Class Pointer --------------------*/
    Client *client = NULL; // remember to initialize this because seg fault
    int state = State::MainMenu;

    SFML::Window window;
    /*------------------- main menu --------------------*/
    sf::Texture t_background;
    sf::Sprite background;

    sf::Clock clock;
    /*------------------- main menu --------------------*/

    int bg_x = 0;
    int bg_y = 0;

    sf::Texture t_play_button;
    sf::Sprite play_button;

    sf::Texture t_settings_button;
    sf::Sprite settings_button;

    sf::Texture t_help_button;
    sf::Sprite help_button;

    sf::Texture t_quit_button;
    sf::Sprite quit_button;
    /*---------------help----------------------------------*/
    sf::Texture t_help_me;
    sf::Sprite help_me;
    /*---------------In game ------------------------------*/
    sf::Texture t_ingame_bg;
    sf::Sprite ingame_bg;
   // sf::Texture t_ingame2_bg;
   // sf::Sprite ingame2_bg;

    sf::Sprite display_ingame;
    int ingame_bg_x = 0;
    int ingame_bg_y = 0;

    sf::Sprite player;
    sf::Texture t_arrow_button;
    sf::Sprite arrow_button;

    /*----------------select menu---------------------------*/

    sf::Texture t_select_menu_bg;
    sf::Sprite select_menu_bg;

    sf::Texture t_select_button;
    sf::Sprite select_button;

    sf::Texture t_select_press_button;
    sf::Sprite select_press_button;

     /*----------------lobby menu---------------------------*/
    Button *ReadyLobbyButton = new Button (680, 760, 172, 72, true);
    
    sf::Texture t_lobby_bg;
    sf::Sprite lobby_bg;

    sf::Texture t_ready_button;
    sf::Sprite ready_button;

    sf::Texture t_notready_button;
    sf::Sprite notready_button;

    std::string data_from_server;
    std::vector<std::string> splited_data;
    sf::Clock lobby_clock;
    sf::Text LobbyPlayerName;

    /*---------------In game ------------------------------*/
    
    sf::Sprite ship1;
    sf::Texture ship1_t;
    sf::Sprite ship2;
    sf::Texture ship2_t;
    sf::Sprite ship3;
    sf::Texture ship3_t;
    sf::Sprite ship4;
    sf::Texture ship4_t;

    sf::Texture t_player;
    sf::Sprite player_1;

    sf::Texture t_player_2;
    sf::Sprite player_2;

    sf::Texture t_player_3;
    sf::Sprite player_3;

    sf::Texture t_player_4;
    sf::Sprite player_4;

    sf::Sprite main_player;

    sf::Texture t_enemy;
    sf::Sprite enemy;
    /*--------------game over-----------------*/

    sf::Texture t_game_over_bg;
    sf::Sprite game_over_bg;
    /*--------------Music----------------------*/
    
    //sf::Sound start_sound;
    //sf::SoundBuffer sound_button;

    /*-----------------------------------------*/

    int test = 0;

    // GAME STATE

    /*-----------------------------------------*/
    int rect_x = 0;
    int rect_enemy_x = 60;
    int rect_player_y = 0;

    /*-------------------------------------*/
    int rect_player_x = 0;
    int ship_select = 0;

    /*---------State Functions----------------------------*/
    void MainMenu();
    void SelectShip();
    void CustomShip();
    void Lobby();
    void GameOver();
    void InGame();
    void HelpMe();
    bool look_arrow_position(sf::Sprite sprite, int pos_x, int pos_y);

    
};
void initalize_game();
void initalize_bg(game_sprites *main_sprites);

void call_animations(game_sprites *main_sprites);
sf::IntRect animate_player(game_sprites *main_sprites, sf::IntRect rect_player);
sf::IntRect animate_enemy(game_sprites *main_sprites, sf::IntRect rect_enemy);

#endif /* !SPRITES_GRAPHICAL_HPP_ */
