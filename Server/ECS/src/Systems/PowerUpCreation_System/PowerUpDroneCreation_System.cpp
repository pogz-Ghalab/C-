/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** PowerUpCreation_System
*/

#include "PowerUpDroneCreation_System.hpp"

int random_number_powerupDrone(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

PowerUpDroneCreation::PowerUpDroneCreation()
{
}

Entity PowerUpDroneCreation::create_PowerUpDrone(Registry &reg)
{
    Entity PowerUpDrone = reg.spawn_entity_with_components(
        component::type_t{POWERUP},
        component::PowerUpType_t{DRONE},
        component::position_t{random_number_powerupDrone(1600, 2000), random_number_powerupDrone(0, 900)},
        component::velocity_t{3},
        component::rect_t{50, 50},
        component::hitbox_t{50, 50}
    );
    return (PowerUpDrone);
}

void PowerUpDroneCreation::operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::PowerUpType_t> &PowupType, sparse_array<component::position_t> &pos, sparse_array<component::velocity_t> &velo, sparse_array<component::rect_t> &rect, sparse_array<component::hitbox_t> &hitb){
    int n = 5;
    
    if(std::clock() - reg.PowerUpDrone_time > n * 5000000) {
        Entity PowerUpDrone = create_PowerUpDrone(reg);
        reg.PowerUpDrone_time = std::clock();
    }
}