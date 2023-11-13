/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** SFML_graph
*/

#include <iostream>
#include "../include/SFML.hpp"

//WINDOW
////////////////////////////////////////////////////////////////////////////////////
//FUNCTION TO CREATE WINDOW BASED ON WIDTH AND HEIGHT
SFML::Window::Window(int width, int height, std::string *WindowName)
{
    this->window->create(sf::VideoMode(width, height, 32), WindowName->c_str());
}

//FUNCTION THAT RETURNS TRUE OR FALSE IF THE WINDOW IS OPEN
bool SFML::Window::isOpen()
{
    return (this->window->isOpen());
}

//FUNCTION THAT DESTROYS WINDOW
void SFML::Window::destroy()
{
    this->window->close();
}

//FUNCTION THAT DRAWS A SPRITE IN THE WINDOW
void SFML::Window::draw(SFML::Sprite *sprite)
{
    this->window->draw(*sprite->sprite); //needs testing
}

//FUNCTION THAT RETURNS TRUE OR FALSE IF EVENT HAS BEEN DETECTED
bool SFML::Window::eventloop(SFML::Event *event)
{
    return this->window->pollEvent(event->event); //needs testing
}
////////////////////////////////////////////////////////////////////////////////////


void SFML::Sprite::SetPositionAndScale(int x, int y, float sx, float sy)
{
    this->sprite->setPosition(x, y);
    this->sprite->setScale(sx, sy);
}




//EVENT
////////////////////////////////////////////////////////////////////////////////////

//ASK THEO HOW TO ENCAPSULATE ENUMS OF THE EVENT CLASS

////////////////////////////////////////////////////////////////////////////////////

//TEXTURE & SPRITE
////////////////////////////////////////////////////////////////////////////////////
//CREATES TEXTURE FROM IMAGE PATH
bool SFML::Sprite::CreateSprite(char const *filepath)
{
    if (!this->texture->loadFromFile(filepath)){
        std::cout << "Error: File not found!" << std::endl;
        return false;
    }
    this->sprite->setTexture(*this->texture); //needs testing
    return true;
}

//CREATE SPRITE BUT ONLY FROM A SPECIFIC PART OF THE TEXTURE DEFINED BY X,Y,WIDHT,HEIGHT
void SFML::Sprite::CropSprite(int x, int y, int width, int height)
{
    this->sprite->setTextureRect(sf::IntRect(x, y, width, height));
}
////////////////////////////////////////////////////////////////////////////////////
