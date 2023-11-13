/*
** EPITECH PROJECT, 2023
** Movement_System.hpp
** File description:
** Movement_System
*/

#ifndef MOVEMENT_SYSTEM_HPP_
#define MOVEMENT_SYSTEM_HPP_

// #include "../../../Server/include/server.hpp"
#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/ParallaxComp.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/UsernameComp.hpp"
#include "../../../include/Components/DamageComp.hpp"
#include "../../../include/Components/DirectionComp.hpp"
#include "../../../include/Components/BulletIdComp.hpp"
#include "../../../include/Components/ScoreComp.hpp"
#include "../../../include/Libs/Definitions/Entity_Type.hpp"
#include <random>

class Registry;

class Movement_System
{
public:
    Movement_System() = default;
    ~Movement_System() = default;

    Entity createParallax(Registry &reg);
    void Parallax(Registry &reg);
    Entity create_bullet(Registry &reg, component::position_t &pos, component::username_t &uname);
    Entity create_powerbullet(Registry &reg, component::position_t &pos, component::username_t &uname);
    Entity create_dronebullet(Registry &reg, component::position_t &pos, component::username_t &uname);
    Entity create_lazerbullet(Registry &reg, component::position_t &pos, component::username_t &uname);

    void LazerBullet(Registry &reg, component::position_t &pos, component::username_t &uname, component::score_t &score);
    void PowerShooting(Registry &reg, component::position_t &pos, component::username_t &uname, component::score_t &score);
    void Shooting(Registry &reg, component::position_t &pos, component::username_t &uname);
    void operator()(Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par, sparse_array<component::direction_t> &dir, sparse_array<component::score_t> &score);
    void DroneShooting(Registry &reg, component::position_t &pos, component::username_t &uname);
    void PowerShooting(Registry &reg, component::position_t &pos, component::score_t &score);
    void Shooting(Registry &reg, component::position_t &pos);
    void MoveEnemy1(Registry &reg, component::position_t &pos, component::direction_t &dir);
    void MoveEnemy2(Registry &reg, component::position_t &pos, component::direction_t &dir);
    void MoveEnemy3(Registry &reg, component::position_t &pos, component::direction_t &dir);
    void moveParallax(component::velocity_t &vel, component::parallax_t &par);
    void moveEnemies(Registry &reg, component::type_t &type, component::position_t &pos, component::direction_t &dir);
    void moveRocks(Registry &reg, component::position_t &pos, component::velocity_t &velo, int entity);
    void movePlayer(Registry &reg, component::username_t &uname, component::position_t &pos, char input, component::velocity_t &velo, component::score_t &score);
    void moveObject(component::velocity_t &vel, component::position_t &pos);

    void movePowerUps(Registry &reg, component::position_t &pos, component::velocity_t &velo, int entity);

    std::clock_t rocks_time = std::clock();

protected:
private:
    bool parallaxCreate = false;
};

#endif /* !MOVEMENT_SYSTEM_HPP_ */
