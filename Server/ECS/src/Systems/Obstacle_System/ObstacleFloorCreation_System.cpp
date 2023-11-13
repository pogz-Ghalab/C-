/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** ObstacleFloorCreation_System
*/

#include "ObstacleFloorCreation_System.hpp"

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

ObstacleFloorCreation::ObstacleFloorCreation() {}

Entity ObstacleFloorCreation::create_ObstacleFloor(Registry &reg) {
    Entity ObstacleFloor = reg.spawn_entity_with_components(
        component::hitbox_t {50, 50},
        component::position_t {random_number(1600, 2000), random_number(0, 900)},
        component::rect_t {50, 50},
        component::type_t {OBSFLOOR},
        component::health_t {2},
        component::damage_t {1},
        component::velocity_t {3}
    );
    return (ObstacleFloor);
}

void ObstacleFloorCreation::operator()(Registry &reg, sparse_array<component::hitbox_t> &hitb, sparse_array<component::position_t> &pos, sparse_array<component::rect_t> &rec, sparse_array<component::type_t> &type, sparse_array<component::velocity_t> &vel) {
    int n = 5;

    if (std::clock() - reg.rock_time > n * 1000000){
        Entity Obstaclefloor = create_ObstacleFloor(reg);
        reg.rock_time = std::clock();
    }
}