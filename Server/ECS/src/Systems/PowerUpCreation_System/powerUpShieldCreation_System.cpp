/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** powerUpShieldCreation_System
*/

#include "PowerUpShieldCreation_System.hpp"

int random_number_powerupShield(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

PowerUpShieldCreation_System::PowerUpShieldCreation_System()
{
}

Entity PowerUpShieldCreation_System::create_PowerUpShield(Registry &reg)
{
    Entity PowerUpShield = reg.spawn_entity_with_components(
        component::type_t {POWERUP},
        component::PowerUpType_t {SHIELD},
        component::position_t {random_number_powerupShield(1600, 2000), random_number_powerupShield(0, 900)},
        component::velocity_t {3},
        component::rect_t {50, 50},
        component::hitbox_t {50, 50}
    );
    return (PowerUpShield);
}

void PowerUpShieldCreation_System::operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::PowerUpType_t> &powupType, sparse_array<component::position_t> &pos, sparse_array<component::velocity_t> &velo, sparse_array<component::rect_t> &rect, sparse_array<component::hitbox_t> &hitb)
{
    int n = 5;
    if (std::clock() - reg.PowerUpShield_time > n * 6000000) { // HERE IS THE TIMER
        Entity PowerUpShield = create_PowerUpShield(reg);
        reg.PowerUpShield_time = std::clock();
    }
}