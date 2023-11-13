/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** SFML_audio
*/

#include <iostream>
#include "../include/SFML_audio.hpp"

//SOUND
////////////////////////////////////////////////////////////////////////////////////
//CREATE A SOUNDBUFFER FROM AUDIO FILE
bool SFML::Sound::setSoundBuffer(char *audiofilepath)
{
    if (!this->soundbuffer->loadFromFile(audiofilepath)){
        std::cout << "Error: Audio file not found!" << std::endl;
        return false;
    }
    return true;
}

//CREATE SOUND FROM SOUNDBUFFER
void SFML::Sound::createSoundfromBuffer(void)
{
    this->sound->setBuffer(*this->soundbuffer);
}

//PLAY SOUND
void SFML::Sound::playSound(void)
{
    this->sound->play();
}
////////////////////////////////////////////////////////////////////////////////////

//MUSIC
////////////////////////////////////////////////////////////////////////////////////
//CREATES MUSIC FROM AUDIO FILE
bool SFML::Music::createMusicFromFile(char *audiofilepath)
{
    if (!this->music->openFromFile(audiofilepath)){
        std::cout << "Error: Audio file not found!" << std::endl;
        return false;
    }
    return true;
}

//START THE MUSIC PLAYING LOOP
void SFML::Music::playMusic(void)
{
    this->music->play();
}
////////////////////////////////////////////////////////////////////////////////////
