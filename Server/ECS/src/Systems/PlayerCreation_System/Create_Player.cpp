/*
** EPITECH PROJECT, 2023
** Create_Player.cpp
** File description:
** Create_Player
*/

#include "Create_Player.hpp"

Entity Create_Player::Init_Player(Registry &reg, std::string *username) {
    Entity player = reg.spawn_entity_with_components(
        component::direction_t {0, 0},
        component::health_t {5},
        component::hitbox_t {100, 200},
        component::position_t {200, 200},
        component::rect_t {100, 75},
        component::score_t {0},
        component::type_t {Entity_type::PLAYER},
        component::velocity_t {70},
        component::damage_t {1},
        component::Powers_t {0},
        component::username_t {*username}
    );
    PlayerCreated = PlayerCreated + 1;
    return (player);
}

void Create_Player::Spawn_Players(Server &srv, Registry &reg) {
    while (PlayerCreated < srv.getConnectedNbr()) {
        Entity Player = Init_Player(reg, srv.GetClients()->at(PlayerCreated)->getUsername());
    }
}
