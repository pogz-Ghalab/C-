/*
** EPITECH PROJECT, 2023
** LevelCreation.hpp
** File description:
** LevelCreation
*/

#ifndef LEVELCREATION_HPP_
#define LEVELCREATION_HPP_

#include <fstream>
#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Libs/Definitions/Entity_Type.hpp"
#include "../../../include/Components/HealthComp.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/DamageComp.hpp"
#include "../../../include/Components/DirectionComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/ParallaxComp.hpp"
#include <ctime>
#include <time.h>

class Registry;

class LevelCreation {
    public:
        LevelCreation() = default;
        ~LevelCreation() = default;
        void ReadJsonEnemies(Registry &reg);
        void ReadJsonLevels(Registry &reg);
        void EndlessMode(Registry &reg);
        void ReadLevelInfo(Registry &reg);
        void WaveControll(Registry &reg);
        void LevelFactory(Registry &reg, json data, std::string title);
        void enemyFactory(Registry &reg, std::string title);
        void ReadEnemies(Registry &reg, int enemy_type);
        void operator()(Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::damage_t> &dmg);
        Entity create_Enemy(Registry &reg, json data, std::string title);
        Entity_type FindType(std::string);
        void spawn_BOSS1(Registry &reg, int node_number);
        Entity spawn_BOSS3(Registry &reg);
        Entity create_Snake_Head(Registry &reg);
        Entity create_Snake_Node(Registry &reg);
        Entity create_Snake_Tail(Registry &reg);
        void spawnBoss(Registry &reg, std::string title);
        Entity spawn_BOSS2(Registry &reg);
    protected:
    private:
        // bool macroMade = false;
        //int EnemiesMade = 0;
};

#endif /* !LEVELCREATION_HPP_ */
