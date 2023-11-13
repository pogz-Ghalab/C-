/*
** EPITECH PROJECT, 2023
** Bullet_System.cpp
** File description:
** Bullet_System
*/

#include "./Bullet_System.hpp"


void Bullet_System::moveBullet(Registry &reg, component::position_t &pos, component::velocity_t &vel, int entity) {
    pos.x = pos.x + vel.speed - 9;

    if (pos.x > 2000)
        reg.kill_entity(reg.entity_from_index(entity));
}

Entity Bullet_System::createEbullet(Registry &reg, component::position_t &pos, component::damage_t &dmg) {
    Entity Ebullet = reg.spawn_entity_with_components (
        component::hitbox_t {15, 15},
        component::position_t {pos.x, pos.y},
        component::type_t {EBULLET},
        component::velocity_t {1},
        component::health_t {1},
        component::rect_t {15, 15},
        component::damage_t {dmg.dmg}
    );

    return (Ebullet);
}

void Bullet_System::EnemyFire(Registry &reg, component::position_t &pos, component::velocity_t &vel, component::damage_t &dmg) {

    Entity Ebullet = createEbullet(reg, pos, dmg);
}

void Bullet_System::reverseBullet(Registry &reg, component::position_t &pos, component::velocity_t &vel, int entity) {
    pos.x = pos.x - vel.speed;

    if (pos.x <= -40)
        reg.kill_entity(reg.entity_from_index(entity));
}

void Bullet_System::operator()(Registry &reg, sparse_array<component::position_t> &pos, sparse_array<component::type_t> &type, sparse_array<component::velocity_t> &vel, sparse_array<component::damage_t> &dmg) {
        for (std::size_t t = 0; t < pos.size() && t < vel.size() && t < type.size();t ++) {
            if (pos[t] && vel[t] && type[t]) {
                if (type[t].value().type == BULLET || type[t].value().type == POWERBULLET || type[t].value().type == DRONEBULLET) {
                    auto &BulletPos = pos[t];
                    auto &BulletVel = vel[t];
                    moveBullet(reg, BulletPos.value(), BulletVel.value(), t);
                }
            }
        }
        if (std::clock() - reg.enemy_bullets_time > 7999999) {
            for (std::size_t t = 0; t < pos.size() && t < vel.size() && t < type.size() && t < dmg.size(); t++) {
                if (pos[t] && vel[t] && type[t] && dmg[t]) {
                    if (type[t].value().type ==  ENEMY1 || type[t].value().type == ENEMY2 || type[t].value().type == ENEMY3 || type[t].value().type == SNAKE_HEAD || type[t].value().type == BOSS2 || type[t].value(). type == BOSS3) {
                        auto &BulletPos = pos[t];
                        auto &BulletVel = vel[t];
                        auto &BulletDmg = dmg[t];

                        EnemyFire(reg, BulletPos.value(), BulletVel.value(), BulletDmg.value());
                    }
                }
            }
            reg.enemy_bullets_time = std::clock();
        }
        for (std::size_t t = 0; t < pos.size() && t < vel.size() && t < type.size(); t++) {
            if (pos[t] && vel[t] && type[t]) {
                if (type[t].value().type ==  EBULLET) {
                    auto &BulletPos = pos[t];
                    auto &BulletVel = vel[t];
                    reverseBullet(reg, BulletPos.value(), BulletVel.value(), t);
                }
            }
        }
}