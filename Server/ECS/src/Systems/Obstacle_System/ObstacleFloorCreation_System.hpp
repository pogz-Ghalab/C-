/*
** EPITECH PROJECT, 2023
** B-CPP-500-BAR-5-2-rtype-arent.dollapaj
** File description:
** ObstacleFloorCreation_System
*/

#ifndef OBSTACLEFLOORCREATION_SYSTEM_HPP_
#define OBSTACLEFLOORCREATION_SYSTEM_HPP_

#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/HealthComp.hpp"
#include "../../../include/Components/DamageComp.hpp"


class Registry;

class ObstacleFloorCreation {
    public:
        ObstacleFloorCreation();
        ~ObstacleFloorCreation() = default;

        void operator()(Registry &reg, sparse_array<component::hitbox_t> &hitb, sparse_array<component::position_t> &pos, sparse_array<component::rect_t> &rec, sparse_array<component::type_t> &type, sparse_array<component::velocity_t> &vel);
        Entity create_ObstacleFloor(Registry &reg);

    protected:
    private:
};

#endif /* !OBSTACLEFLOORCREATION_SYSTEM_HPP_ */
