/*
** EPITECH PROJECT, 2023
** input username ip and port
** File description:
** R-type
*/

#include "../include/Game.hpp"

std::string handleInput(SFML::Event event, std::string InputString)
{
    if (event.event.text.unicode == '\b' && !InputString.empty()) // Backspace pressed
        InputString.pop_back();
    else
        InputString += static_cast<char>(event.event.text.unicode);
    return (InputString);
}

int checkActivity(int activeTextBox, sf::Vector2i mousePos, sf::FloatRect textBoxBounds1, sf::FloatRect textBoxBounds2)
{
    if (textBoxBounds1.contains(mousePos.x, mousePos.y))
        activeTextBox = 1;
    else if (textBoxBounds2.contains(mousePos.x, mousePos.y))
        activeTextBox = 2;
    else
        activeTextBox = 0;
    return (activeTextBox);
}

SFML::Text setTextPosition(SFML::Text Text, sf::FloatRect textRect, SFML::RectangleShape textBox)
{
    Text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    Text.setPosition(textBox.getPosition() + textBox.getSize() / 2.0f);
    return (Text);
}

void displayContent(Game *game)
{
    game->Window->window->clear();
    game->Window->draw(game->InputsBackgroundSprite);
    game->Window->drawRectangle(game->ipTextBox);
    //game->Window->drawText(game->defaultText);
    game->Window->drawText(game->ipText);
    game->Window->drawRectangle(game->inputButton);
    game->Window->drawText(game->inputButtonText);
    game->Window->drawRectangle(game->usernameTextBox);
    game->Window->drawText(game->usernameText);
    game->Window->window->display();
}

void InputsEventLoop(Game *game)
{
    SFML::Event event;

    while (game->Window->eventloop(&event)) {
        if (event.event.type == sf::Event::Closed) {
            game->client->SEND(game->client->b.Encode("Exit"));
            game->Window->destroy();
        } else if (event.event.type == sf::Event::TextEntered) {
            if (event.event.text.unicode < 128)  {
                if (game->activeTextBox == 1) {
                    game->ipInputString = handleInput(event, game->ipInputString);
                    game->ipText.setString(game->ipInputString);
                } else if (game->activeTextBox == 2) {
                    game->usernameInputString = handleInput(event, game->usernameInputString);
                    game->usernameText.setString(game->usernameInputString);
                }
            }
        } else if (event.event.type == sf::Event::MouseButtonPressed) {
            if (event.event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*game->Window->window);
                sf::FloatRect ipBoxBounds = game->ipTextBox.getGlobalBounds();
                sf::FloatRect usernameBoxBounds = game->usernameTextBox.getGlobalBounds();
                game->activeTextBox = checkActivity(game->activeTextBox, mousePos, ipBoxBounds, usernameBoxBounds);

                sf::FloatRect buttonBounds = game->inputButton.getGlobalBounds();
                if (buttonBounds.contains(mousePos.x, mousePos.y)) {
                    // The common button was clicked, do something with both input strings
                    if (!game->ipInputString.empty() && !game->usernameInputString.empty()) {
                        std::cout << "IP address: " << game->ipInputString << std::endl;
                        std::cout << "Username: " << game->usernameInputString << std::endl;
                        game->ipInputString.clear();
                        game->ipText.setString("");
                        game->usernameInputString.clear();
                        game->usernameText.setString("");
                        game->state = State::SelectShip;
                    } else {
                        std::cout << "Error: inputs are empty" << std::endl;
                    }
                }
            }
        }
    }
    game->ipRect = game->ipText.getLocalBounds();
    game->ipText = setTextPosition(game->ipText, game->ipRect, game->ipTextBox);

    game->usernameRect = game->usernameText.getLocalBounds();
    game->usernameText = setTextPosition(game->usernameText, game->usernameRect, game->usernameTextBox);

    //---------------------------------------------------------------
    // UPDATED PART: POSITIONING THE COMMON BUTTON
    sf::FloatRect ipButtonRect = game->inputButton.getGlobalBounds();
    game->inputButton.setPosition(game->ipTextBox.getPosition().x, game->usernameTextBox.getPosition().y + game->usernameTextBox.getSize().y + 10.f);
    //---------------------------------------------------------------

    displayContent(game);
}

void Game::Inputs()
{
    // this->Window->window->display();
    InputsEventLoop(this);
    // this->lobby_music.play();
}