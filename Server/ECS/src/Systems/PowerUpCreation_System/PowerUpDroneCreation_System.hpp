/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** aid drone 
*/

#ifndef POWERUPDRONECREATION_SYSTEM_HPP_
#define POWERUPDRONECREATION_SYSTEM_HPP_


#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/PowerUpTypeComponent.hpp"

class Registry;

class PowerUpDroneCreation {
    public:
        PowerUpDroneCreation();
        ~PowerUpDroneCreation() = default;
        Entity create_PowerUpDrone(Registry &reg);
        void operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::PowerUpType_t> &PowupType, sparse_array<component::position_t> &pos, sparse_array<component::velocity_t> &velo, sparse_array<component::rect_t> &rect, sparse_array<component::hitbox_t> &hitb);
    protected:
    private:
};

#endif /* !POWERUPDRONECREATION_HPP_ */
