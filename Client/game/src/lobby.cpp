/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** lobby
*/

#include "../include/SFML.hpp"
#include "../include/Game.hpp"
#include <string.h>
#include <sstream>
#include <unistd.h>

using std::cout;
using std::endl;
using std::string;

std::vector<std::string> split_data(std::string str, const char *delim)
{
    std::vector<std::string> out;
    char *token = strtok(const_cast<char *>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
    return (out);
}

int check_size(std::vector<std::string> res)
{
    int x = 0;
    while (x < res.size())
    {
        x++;
    }
    return (x);
}

bool IsServerSendingUsernames(Game *game)
{
    std::vector<std::string> result;
    if (game->msgFromClient == "x")
    {
        return false;
    }
    game->splited_data = split_data(game->msgFromClient, ",");
    ;
    return true;
}

void displayPlayerNames(Game *game)
{
    sf::Text text;
    int pos_y = 270;

    for (int x = 0; x < check_size(game->splited_data); x++)
    {
        if (game->splited_data[x] == "r")
        {
            game->ReadyButton->SetPositionAndScale(1054, pos_y - 100, 0.25, 0.25);
            game->Window->draw(game->ReadyButton);
        }
        else if (game->splited_data[x] == "u")
        {
            game->NotReadyButton->SetPositionAndScale(1054, pos_y - 100, 0.25, 0.25);
            game->Window->draw(game->NotReadyButton);
        }
        else
        {
            game->LobbyPlayerName.setFont(game->lobbyfont);
            game->LobbyPlayerName.setString(game->splited_data[x]);
            game->LobbyPlayerName.setCharacterSize(50);
            game->LobbyPlayerName.setPosition(500, pos_y);
            game->LobbyPlayerName.setStyle(sf::Text::Bold);
            game->LobbyPlayerName.setFillColor(sf::Color::White);
        }
        game->Window->window->draw(game->LobbyPlayerName);
        pos_y += 85;
    }
}

void LobbyEventLoop(Game *game)
{
    SFML::Event event;

    while (game->Window->eventloop(&event))
    {
        if (event.event.type == sf::Event::Closed)
        {
            game->client->SEND(game->client->b.Encode("Exit"));
            game->Window->destroy();
        }
        else if (event.event.type == sf::Event::MouseButtonPressed)
        {
            if (game->ReadyLobbyButton->isButtonClicked(event.event.mouseButton.y, event.event.mouseButton.x))
            {
                if (game->oncestart)
                {
                    game->client->SEND(game->client->b.Encode("Ready"));
                    game->oncestart = false;
                }
                *game->CurrentButton = *game->ReadyButton;
                game->CurrentButton->SetPositionAndScale(680, 760, 0.3, 0.3);
            }
        }
    }
}

void Game::Lobby()
{
    this->Window->window->clear(sf::Color::Black);
    this->Window->draw(this->LobbyBackground);

    LobbyEventLoop(this);

    this->Window->draw(this->CurrentButton);

    if (IsServerSendingUsernames(this))
    {
        displayPlayerNames(this);
    }
    this->ingame_music1.play();
    this->Window->window->display();

    // COMMENTING ONLY FOR TESTING CAUSE IT GETS ANNOYING
    // this->lobby_music.play();
}