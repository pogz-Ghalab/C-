/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** SFML_graph
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace SFML
{
    class Button
    {
        public:
            bool active = false;
            Button(int _x, int _y, int _width, int _height, bool _active) : x(_x), y(_y), width(_width), height(_height), active(_active) {}

            bool isButtonClicked(int my, int mx)
            {
                if (my >= y && my <= y + height && mx >= x && mx <= x + width)
                {
                    return true;
                }
                return false;
            }
            sf::Sprite sprite;
            int x;
            int y;
            int width;
            int height;
    };

    class Event
    {
        public:
            sf::Event event;
    };

    class Sprite
    {
        public:
            sf::Texture *texture = new sf::Texture;
            sf::Sprite *sprite = new sf::Sprite;

            bool CreateSprite(char const *filepath);
            void CropSprite(int x, int y, int width, int height);
            void SetPositionAndScale(int x, int y, float sx, float sy);
    };

    class Text: public sf::Text
    {
        public:
            sf::Text text;

            void setString(const std::string& str);
            void setFont(const sf::Font& font);
            const sf::Vector2f getPosition() const;
            void setCharacterSize(unsigned int size);
            void setPosition(const sf::Vector2f &position);
            void setRotation(float angle);
            void setScale(float x, float y);
            void setFillColor(const sf::Color& color);
            void setOutlineColor(const sf::Color& color);
            void setOutlineThickness(float thickness);
            sf::FloatRect getLocalBounds() const;
            void setOrigin(float x, float y);
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };

    class RectangleShape: public sf::Transformable
    {
        public:
            sf::RectangleShape rec;
            using sf::Transformable::getPosition;
            using sf::Transformable::setPosition;
            
            void setRotation(float angle);
            void setScale(float x, float y);
            void setRecPosition(float x, float y);
            void setReccPosition(const sf::Vector2f &position);
            void setSize(const sf::Vector2f& size);
            sf::Vector2f getSize();
            void setFillColor(const sf::Color& color);
            void setOutlineThickness(float thickness);
            void setOutlineColor(const sf::Color& color);
            const sf::Vector2f getPosition() const;
            sf::FloatRect getGlobalBounds() const;
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };

    class Window
    {
        public:
            Window(int width, int height, std::string *WindowName);

            sf::RenderWindow *window;
            bool isOpen();
            void draw(SFML::Sprite *sprite);
            void drawText(SFML::Text text);
            void drawRectangle(SFML::RectangleShape rec);
            bool eventloop(SFML::Event *event);
            void destroy();
    };

} // namespace SMFL

#endif /* !SFML_GRAPH_HPP_ */