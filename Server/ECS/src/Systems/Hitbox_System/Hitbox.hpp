/*
** EPITECH PROJECT, 2023
** Hitbox.hpp
** File description:
** Hitbox
*/

#ifndef HITBOX_HPP_
#define HITBOX_HPP_

#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/ScoreComp.hpp"
#include "../../../include/Components/DamageComp.hpp"
#include "../../../include/Components/HealthComp.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Libs/Definitions/Entity_Type.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/UsernameComp.hpp"
#include "../../../include/Components/BulletIdComp.hpp"
#include "../../../include/Components/PowersComp.hpp"
#include "../../../include/Components/PowerUpTypeComponent.hpp"

class Registry;

class Hitbox {
    public:
        Hitbox() = default;
        ~Hitbox() = default;
        int Handle_Hitbox_Player(Registry &reg, component::type_t const &Etype, component::type_t const &Atype, sparse_array<component::damage_t> const &dmg, sparse_array<component::health_t> &hp, sparse_array<component::score_t> &score, int first, int second);
        void Handle_Hitbox_PowerUp(Registry &reg, component::type_t const &PWType, component::type_t const &Ptype, component::Powers_t &pow,sparse_array<component::damage_t> const &dmg, sparse_array<component::health_t> &hp, sparse_array<component::score_t> &score, sparse_array<component::PowerUpType_t> &PowerUpType, int first, int second);
        void operator()(Registry &reg, sparse_array<component::health_t> &hp, sparse_array<component::position_t> &pos, sparse_array<component::rect_t> &rec, sparse_array<component::score_t> &score, sparse_array<component::type_t> &type, sparse_array<component::damage_t> &dmg, sparse_array<component::bulletid_t> &bid, sparse_array<component::username_t> &uname, sparse_array<component::PowerUpType_t> &pwtype, sparse_array<component::Powers_t> &pow);
        bool Collision(component::type_t const &type, component::rect_t const &rect1, component::rect_t const &rect2, component::position_t const &pos1, component::position_t const &pos2);

    protected:
    private:
};

#endif /* !HITBOX_HPP_ */
