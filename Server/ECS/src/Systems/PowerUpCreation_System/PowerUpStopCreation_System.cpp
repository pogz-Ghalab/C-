/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** PowerUpStopCreation_System
*/

#include "PowerUpStopCreation_System.hpp"

int random_number_powerupStop(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

PowerUpStopCreation_System::PowerUpStopCreation_System()
{
}

Entity PowerUpStopCreation_System::create_PowerUpStop(Registry &reg)
{
    Entity Stop = reg.spawn_entity_with_components(
        component::type_t {POWERUP},
        component::PowerUpType_t {STOP},
        component::position_t {random_number_powerupStop(1600, 2000), random_number_powerupStop(0, 900)},
        component::velocity_t {3},
        component::rect_t {50, 50},
        component::hitbox_t {50, 50}
    );
    return (Stop);
}

void PowerUpStopCreation_System::operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::PowerUpType_t> &powupType, sparse_array<component::position_t> &pos, sparse_array<component::velocity_t> &velo, sparse_array<component::rect_t> &rect, sparse_array<component::hitbox_t> &hitb)
{
    int n = 5;

    if (std::clock() - reg.PowerUpStop_time > n * 7000000) { // HERE IS THE TIMER
        Entity PowerUpHeart = create_PowerUpStop(reg);
        reg.PowerUpStop_time = std::clock();
    }
}