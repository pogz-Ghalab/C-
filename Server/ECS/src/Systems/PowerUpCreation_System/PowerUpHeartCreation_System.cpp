/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** PowerUpCreation_System
*/

#include "PowerUpHeartCreation_System.hpp"

int random_number_powerupHeart(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

PowerUpHearthCreation_System::PowerUpHearthCreation_System()
{
}

Entity PowerUpHearthCreation_System::create_PowerUpHeart(Registry &reg)
{
    Entity PowerUp = reg.spawn_entity_with_components(
        component::type_t {POWERUP},
        component::PowerUpType_t {HEART},
        component::position_t {random_number_powerupHeart(1600, 2000), random_number_powerupHeart(0, 900)},
        component::velocity_t {3},
        component::rect_t {50, 50},
        component::hitbox_t {50, 50}
    );
    return (PowerUp);
}

void PowerUpHearthCreation_System::operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::PowerUpType_t> &powupType, sparse_array<component::position_t> &pos, sparse_array<component::velocity_t> &velo, sparse_array<component::rect_t> &rect, sparse_array<component::hitbox_t> &hitb)
{
    int n = 5;

    if (std::clock() - reg.PowerUp_time > n * 5000000) { //HERE IS THE TIMER
        Entity PowerUpHeart = create_PowerUpHeart(reg);
        reg.PowerUp_time = std::clock();
    }
}
