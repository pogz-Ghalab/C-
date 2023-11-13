/*
** EPITECH PROJECT, 2023
** Bullet_System.hpp
** File description:
** Bullet_System
*/

#ifndef BULLET_SYSTEM_HPP_
#define BULLET_SYSTEM_HPP_

#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/DamageComp.hpp"
#include "../../../include/Components/HealthComp.hpp"

class Registry;

class Bullet_System {
    public:
        Bullet_System() = default;
        ~Bullet_System() = default;

        Entity createEbullet(Registry &reg, component::position_t &pos, component::damage_t &dmg);
        void reverseBullet(Registry &reg, component::position_t &pos, component::velocity_t &vel, int entity);
        void EnemyFire(Registry &reg, component::position_t &pos, component::velocity_t &vel, component::damage_t &dmg);
        void moveBullet(Registry &reg, component::position_t &pos, component::velocity_t &vel, int entity);
        void operator()(Registry &reg, sparse_array<component::position_t> &pos, sparse_array<component::type_t> &type, sparse_array<component::velocity_t> &vel, sparse_array<component::damage_t> &dmg);

    protected:
    private:
};

#endif /* !BULLET_SYSTEM_HPP_ */
