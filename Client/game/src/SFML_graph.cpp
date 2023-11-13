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
    this->window = new sf::RenderWindow;
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

//FUNCTION THAT DRAWS A TEXT IN THE WINDOW
void SFML::Window::drawText(SFML::Text text)
{
    this->window->draw(text.text); //needs testing
}

//FUNCTION THAT DRAWS A TEXT IN THE WINDOW
void SFML::Window::drawRectangle(SFML::RectangleShape rec)
{
    this->window->draw(rec.rec); //needs testing
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

    std::string test(filepath);
    this->texture->loadFromFile(test);
        
    this->sprite->setTexture(*this->texture); //needs testing
    return true;
}

//CREATE SPRITE BUT ONLY FROM A SPECIFIC PART OF THE TEXTURE DEFINED BY X,Y,WIDHT,HEIGHT
void SFML::Sprite::CropSprite(int x, int y, int width, int height)
{
    this->sprite->setTextureRect(sf::IntRect(x, y, width, height));
}
////////////////////////////////////////////////////////////////////////////////////


//TEXT
////////////////////////////////////////////////////////////////////////////////////
//SET A STRING GIVEN AS STRING &STR
void SFML::Text::setString(const std::string& str) {
    text.setString(str);
}

//SET A FONT FROM SF::FONT
void SFML::Text::setFont(const sf::Font& font) {
    text.setFont(font);
}

//GET THE POSITION OF AN OBJECT
const sf::Vector2f SFML::Text::getPosition() const {
    return text.getPosition();
}

//SET THE CHARACTER SIZE FROM A GIVEN SIZE, THE DEFAULT SIZE IS 30
void SFML::Text::setCharacterSize(unsigned int size) {
    text.setCharacterSize(size);
}

//SET THE POSITION OF AN OBJECT FROM A VECTOR2F POSITION
void SFML::Text::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

//SET THE POSITION OF AN OBJECT FROM A FLOAT ANGLE
void SFML::Text::setRotation(float angle) {
    setRotation(angle);
}

//SET THE SCALE FACTORS FROM FLOAT X AND FLOAT Y
void SFML::Text::setScale(float x, float y) {
    text.setScale(sf::Vector2f(x, y));
}

//SET THE FILL COLOR OF THE TEXT, DEFAULT COLOR IS OPAQUE WHITE
void SFML::Text::setFillColor(const sf::Color& color) {
    text.setFillColor(color);
}

//SET THE OUTLINE COLOR OF THE TEXT, DEFAULT COLOR IS OPAQUE BLACK
void SFML::Text::setOutlineColor(const sf::Color& color) {
    text.setOutlineColor(color);
}

//SET THE OUTLINE THICKNESS OF THE TEXT, DEFAULT THICKNESS IS 0
void SFML::Text::setOutlineThickness(float thickness) {
    text.setOutlineThickness(thickness);
}
//GET THE LOCAL BOUNDING RECTANGLE OF THE ENTITY
sf::FloatRect SFML::Text::getLocalBounds() const {
    return text.getLocalBounds();
}

//SET THE ORIGIN POINTS OF THE ENTITY FROM FLOAT X AND FLOAT Y, DEFAULT IS (0, 0)
void SFML::Text::setOrigin(float x, float y) {
    text.setOrigin(x, y);
}

//DRAW A DRAWABLE OBJECT TO THE RENDER TARGET
void SFML::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}
////////////////////////////////////////////////////////////////////////////////////


//RECTANGLESHAPE
////////////////////////////////////////////////////////////////////////////////////
//SET THE POSITION OF AN OBJECT FROM A FLOAT ANGLE
void SFML::RectangleShape::setRotation(float angle) {
    rec.setRotation(angle);
}

void SFML::RectangleShape::setRecPosition(float x, float y) {
    rec.setPosition(x, y);
}

void SFML::RectangleShape::setReccPosition(const sf::Vector2f &position) {
    rec.setPosition(position);
}

//SET THE SCALE FACTORS FROM FLOAT X AND FLOAT Y
void SFML::RectangleShape::setScale(float x, float y) {
    rec.setScale(sf::Vector2f(x, y));
}

//SET THE SIZE OF THE RECTANGLE FROM A GIVEN VECTOR2F SIZE
void SFML::RectangleShape::setSize(const sf::Vector2f& size) {
    rec.setSize(size);
}

//RETURNS THE SIZE OF THE RECTANGLE
sf::Vector2f SFML::RectangleShape::getSize() {
    return rec.getSize();
}

//SET THE FILL COLOR OF THE RECTANGLE, DEFAULT COLOR IS OPAQUE WHITE
void SFML::RectangleShape::setFillColor(const sf::Color& color) {
    rec.setFillColor(color);
}

//SET THE OUTLINE THICKNESS OF THE RECTANGLE, DEFAULT THICKNESS IS 0
void SFML::RectangleShape::setOutlineThickness(float thickness) {
    rec.setOutlineThickness(thickness);
}

//SET THE OUTLINE COLOR OF THE RECTANGLE, DEFAULT COLOR IS OPAQUE BLACK
void SFML::RectangleShape::setOutlineColor(const sf::Color& color) {
    rec.setOutlineColor(color);
}

//RETURNS THE CURRENT POSITION OF THE RECTANGLE
const sf::Vector2f SFML::RectangleShape::getPosition() const {
    return rec.getPosition();
}

//GET THE LOCAL BOUNDING RECTANGLE OF THE ENTITY
sf::FloatRect SFML::RectangleShape::getGlobalBounds() const {
    sf::Transform transform = rec.getTransform();
    sf::FloatRect bounds = rec.getLocalBounds();
    return transform.transformRect(bounds);
}

//DRAW A DRAWABLE OBJECT TO THE RENDER TARGET
void SFML::RectangleShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rec, states);
}