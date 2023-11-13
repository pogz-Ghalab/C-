/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** PowerUpCreation_System
*/

#ifndef POWERUPCREATION_SYSTEM_HPP_
#define POWERUPCREATION_SYSTEM_HPP_

#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/PowerUpTypeComponent.hpp"


class Registry;

class PowerUpHearthCreation_System {
    public:
        PowerUpHearthCreation_System();
        ~PowerUpHearthCreation_System() = default;
        Entity create_PowerUpHeart(Registry &reg);
        void operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::PowerUpType_t> &powupType, sparse_array<component::position_t> &pos, sparse_array<component::velocity_t> &velo, sparse_array<component::rect_t> &rect, sparse_array<component::hitbox_t> &hitb);
    protected:
    private:
};

#endif /* !POWERUPCREATION_SYSTEM_HPP_ */
