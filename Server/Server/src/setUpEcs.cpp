/*
** EPITECH PROJECT, 2023
** setUpEcs.cpp
** File description:
** setUpEcs
*/

#include "../../ECS/include/Libs/ECS/Registry.hpp"
#include "../../ECS/include/Components/HealthComp.hpp"
#include "../../ECS/include/Components/DamageComp.hpp"
#include "../../ECS/include/Components/PositionComp.hpp"
#include "../../ECS/include/Components/RectComp.hpp"
#include "../../ECS/include/Components/TypeComponent.hpp"
#include "../../ECS/include/Components/VelocityComp.hpp"
#include "../../ECS/include/Components/PowerUpTypeComponent.hpp"
#include "../../ECS/include/Components/UsernameComp.hpp"
#include "../../ECS/include/Components/ScoreComp.hpp"
#include "../../ECS/include/Components/HitboxComp.hpp"
#include "../../ECS/include/Components/DirectionComp.hpp"
#include "../../ECS/include/Components/ParallaxComp.hpp"
#include "../../ECS/include/Components/PlayerIdComponent.hpp"
#include "../../ECS/include/Components/BulletIdComp.hpp"
#include "../../ECS/include/Components/PowersComp.hpp"
/* Systems  */
#include "../../ECS/src/Systems/Hitbox_System/Hitbox.hpp"
#include "../../ECS/src/Systems/Bullet_System/Bullet_System.hpp"
#include "../../ECS/src/Systems/PlayerCreation_System/Create_Player.hpp"
#include "../../ECS/src/Systems/Movement_System/Movement_System.hpp"
#include "../../ECS/src/Systems/Obstacle_System/ObstacleFloorCreation_System.hpp"
#include "../../ECS/src/Systems/PowerUpCreation_System/PowerUpHeartCreation_System.hpp"
#include "../../ECS/src/Systems/PowerUpCreation_System/PowerUpDroneCreation_System.hpp"
#include "../../ECS/src/Systems/PowerUpCreation_System/PowerUpShieldCreation_System.hpp"
#include "../../ECS/src/Systems/PowerUpCreation_System/PowerUpStopCreation_System.hpp"
#include "../../ECS/src/Systems/Send_data/Send_data.hpp"
#include "../../ECS/src/Systems/LevelCreation_System/LevelCreation.hpp"
#include "../include/server.hpp"

class Create_Player;

void PrimeEcs(Registry *reg_);
void PrimeSystems(Registry *reg_);

void Server::Init_ECS()
{
    PrimeEcs(this->reg_);
    PrimeSystems(this->reg_);
}

void PrimeEcs(Registry *reg_)
{
    reg_->register_component<component::damage_t>();
    reg_->register_component<component::direction_t>();
    reg_->register_component<component::hitbox_t>();
    reg_->register_component<component::health_t>();
    reg_->register_component<component::position_t>();
    reg_->register_component<component::rect_t>();
    reg_->register_component<component::score_t>();
    reg_->register_component<component::type_t>();
    reg_->register_component<component::username_t>();
    reg_->register_component<component::velocity_t>();
    reg_->register_component<component::playerId_t>();
    reg_->register_component<component::parallax_t>();
    reg_->register_component<component::bulletid_t>();
    reg_->register_component<component::PowerUpType_t>();
    reg_->register_component<component::Powers_t>();
}

void PrimeSystems(Registry *reg_)
{
    Bullet_System _bullet_system;
    Hitbox _hitbox_system;
    LevelCreation _levelCreation_system;
    Send_data _send_system;
    Movement_System _movement_system;
    ObstacleFloorCreation _obstacleFloorCreation_system;
    PowerUpHearthCreation_System _powerUpHeartCreation_system;
    PowerUpShieldCreation_System _powerUpShieldCreation_system;
    PowerUpStopCreation_System _powerUpStopCreation_system;
    PowerUpDroneCreation _powerUpDroneCreation;
    Send_data _SendData_system;

    reg_->add_system<component::hitbox_t, component::position_t, component::rect_t, component::type_t, component::velocity_t>(_obstacleFloorCreation_system);
    reg_->add_system<component::type_t, component::PowerUpType_t, component::position_t, component::velocity_t, component::rect_t, component::hitbox_t>(_powerUpHeartCreation_system);
    reg_->add_system<component::type_t, component::PowerUpType_t, component::position_t, component::velocity_t, component::rect_t, component::hitbox_t>(_powerUpShieldCreation_system);
    reg_->add_system<component::type_t, component::PowerUpType_t, component::position_t, component::velocity_t, component::rect_t, component::hitbox_t>(_powerUpStopCreation_system);
    reg_->add_system<component::type_t, component::PowerUpType_t, component::position_t, component::velocity_t, component::rect_t, component::hitbox_t>(_powerUpDroneCreation);

    reg_->add_system<component::velocity_t, component::type_t, component::position_t, component::damage_t>(_levelCreation_system);
    reg_->add_system<component::health_t, component::position_t, component::rect_t, component::score_t, component::type_t, component::damage_t, component::bulletid_t, component::username_t, component::PowerUpType_t , component::Powers_t>(_hitbox_system);
    reg_->add_system<component::position_t, component::type_t, component::velocity_t, component::damage_t>(_bullet_system);
    reg_->add_system<component::velocity_t, component::username_t, component::type_t, component::position_t, component::parallax_t, component::direction_t, component::score_t>(_movement_system);
    reg_->add_system<component::type_t, component::position_t, component::username_t, component::parallax_t, component::health_t, component::PowerUpType_t, component::Powers_t>(_send_system);
}