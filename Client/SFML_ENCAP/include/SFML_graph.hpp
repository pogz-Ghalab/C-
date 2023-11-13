/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** SFML_graph
*/

#ifndef SFML_GRAPH_HPP_
#define SFML_GRAPH_HPP_

#include <SFML/Graphics.hpp>

namespace SFML
{
    class Window {
        public:
            sf::RenderWindow *window;
            void createWindow(int width, int height, char *windowname);
            bool isOpen();
            void draw(SFML::Sprite);
            bool eventloop(SFML::Event event);
            void destroy();
    };

    class Event {
        public:
            sf::Event *event;
    };

    class Sprite {
        public:
            sf::Texture *texture;
            sf::Sprite *sprite;

            bool SFML::Sprite::CreateSprite(char *filepath)
            bool loadTexture(char *filepath);
            void createSpritefromTexture(void);
            void createSpritefromCroppedTexture(int x, int y, int width, int height);
            //maybe add texture smooth function later
    };

} // namespace SMFL

#endif /* !SFML_GRAPH_HPP_ */
