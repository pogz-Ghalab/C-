/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** SFML_audio
*/

#ifndef SFML_AUDIO_HPP_
#define SFML_AUDIO_HPP_

#include <SFML/Audio.hpp>

namespace SFML
{
    class Sound {
        public:
            sf::SoundBuffer *soundbuffer;
            sf::Sound *sound;

            bool setSoundBuffer(char *audiofilepath);
            void createSoundfromBuffer(void);
            void playSound(void);
    };

    class Music {
        public:
            sf::Music *music;

            bool createMusicFromFile(char *audiofilepath);
            void playMusic(void);
    };
}

#endif /* !SFML_AUDIO_HPP_ */
