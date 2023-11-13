/*
** EPITECH PROJECT, 2023
** LevelCreation.cpp
** File description:
** LevelCreation
*/

#include "LevelCreation.hpp"

Entity_type LevelCreation::FindType(const std::string Etype) {
    if (Etype == "ENEMY1") return (ENEMY1);
    else if (Etype == "ENEMY2") return (ENEMY2);
    else if (Etype == "ENEMY3") return (ENEMY3);
    // else if (Etype == "BOSS2") return (BOSS2);
    // else if (Etype == "BOSS3") return (BOSS3);
    return (ENEMY1);
}

int NODE_DISTANCE = 100;

Entity LevelCreation::create_Snake_Head(Registry &reg)
{
    Entity enemy = reg.spawn_entity_with_components(
        component::health_t {20},
        component::position_t {1000, 0},
        component::hitbox_t {20, 20},
        component::rect_t {150, 150},
        component::type_t {SNAKE_HEAD},
        component::damage_t {1},
        component::velocity_t {20}
    );
    reg.snake_nodes += 1;
    return (enemy);
}

Entity LevelCreation::create_Snake_Node(Registry &reg)
{
    Entity enemy = reg.spawn_entity_with_components(
        component::health_t {1},
        component::position_t {1000 + (reg.snake_nodes * NODE_DISTANCE), 0},
        component::hitbox_t {20, 20},
        component::rect_t {150, 150},
        component::type_t {SNAKE_NODE},
        component::damage_t {1},
        component::velocity_t {20}
    );
    reg.snake_nodes += 1;
    return (enemy);
}

Entity LevelCreation::create_Snake_Tail(Registry &reg)
{
    Entity enemy = reg.spawn_entity_with_components(
        component::health_t {1},
        component::position_t {1000 + (reg.snake_nodes * NODE_DISTANCE), 0},
        component::hitbox_t {20, 20},
        component::rect_t {150, 150},
        component::type_t {SNAKE_TAIL},
        component::damage_t {1},
        component::velocity_t {20}
    );
    reg.snake_nodes += 1;
    return (enemy);
}

void LevelCreation::spawn_BOSS1(Registry &reg, int node_number) {
    create_Snake_Head(reg);
    for (int i = 0; i < node_number; i++){
        create_Snake_Node(reg);
    }
    create_Snake_Tail(reg);
    reg.Boss--;
}

Entity LevelCreation::spawn_BOSS2(Registry &reg) {
    Entity enemy = reg.spawn_entity_with_components(
        component::health_t {50},
        component::position_t {1000, 100},
        component::hitbox_t {600, 400},
        component::rect_t {600, 400},
        component::type_t {BOSS2},
        component::damage_t {3},
        component::velocity_t {10}
    );
    reg.Boss--;
    return (enemy);
}

Entity LevelCreation::spawn_BOSS3(Registry &reg) {
    Entity enemy = reg.spawn_entity_with_components(
        component::health_t {75},
        component::position_t {1000, 100},
        component::hitbox_t {600, 400},
        component::rect_t {600, 400},
        component::type_t {BOSS3},
        component::damage_t {3},
        component::velocity_t {10}
    );
    reg.Boss--;
    return (enemy);
}

Entity LevelCreation::create_Enemy(Registry &reg, json data, std::string title) {
    Entity enemy = reg.spawn_entity_with_components(
        component::health_t {data[title]["health"][0]},
        component::position_t {std::rand() % 600 + 900, std::rand() % 800},
        component::hitbox_t {data[title]["hitbox"][0], data[title]["hitbox"][1]},
        component::rect_t {data[title]["rect"][0], data[title]["rect"][1]},
        component::type_t {FindType(data[title]["type"][0])},
        component::damage_t {data[title]["damage"][0]},
        component::velocity_t {data[title]["velocity"][0]},
        component::direction_t {true, true}
    );
    if (title == "boss2" || title == "boss33")
        reg.Boss--;
    return (enemy);
}

void LevelCreation::ReadJsonEnemies(Registry &reg) {
    json data;
    std::ifstream enemystream(ENEMY_FILEPATH);

    if (!enemystream.is_open())
        throw ("failed to open enemy config file\n");
    enemystream >> data;
    enemystream.close();
    auto enemies = data["Enemies"];
    int numEnemies = data["Enemies"].size();
    for (int t = 0; t < numEnemies; t++)
        reg._enemyConfig.push_back(enemies[t]);
    reg.Readlvl = true;
}

void LevelCreation::ReadJsonLevels(Registry &reg) {
    json data;
    std::ifstream levelstream(LEVEL_FILEPATH);

    if (!levelstream.is_open()) {
        throw ("failed to open enemy config file\n");
    }
    levelstream >> data;
    levelstream.close();
    auto levels = data["Levels"];
    int numLevels = data["Levels"].size();
    for (int t = 0; t < numLevels; t++)
        reg._levelConfig.push_back(levels[t]);
}

void LevelCreation::LevelFactory(Registry &reg, json data, std::string title) {
    reg.Enemy1 = data[title]["enemy1"];
    reg.Enemy2 = data[title]["enemy2"];
    reg.Enemy3 = data[title]["enemy3"];
    
    if (reg.Level == 2)
        reg.Boss = data[title]["boss1"];
    if (reg.Level == 4)
        reg.Boss = data[title]["boss2"];
    if (reg.Level >= 5)
        reg.Boss = data[title]["boss3"];

    reg.EnemiesLevelNbr = (reg.Enemy1 + reg.Enemy2 + reg.Enemy3);
}


void LevelCreation::EndlessMode(Registry &reg) {
    reg.Enemy3 = reg.Level * (rand() % (reg.Level + 5)) / 2;
    reg.Boss = 1;
}

void LevelCreation::ReadLevelInfo(Registry &reg) {
    std::string path = reg._levelConfig[reg.Level - 1]["path"];
    std::string title = reg._levelConfig[reg.Level - 1]["title"];
    json data;

    std::ifstream levelstream(path);
    if (!levelstream.is_open())
        throw("Failed to open level config file\n");
    levelstream >> data;
    levelstream.close();
    LevelFactory(reg, data, title);
}

void LevelCreation::enemyFactory(Registry &reg, std::string title) {

    if (title == "enemy1")
        reg.Enemy1--;
    else if (title == "enemy2")
        reg.Enemy2--;
    else if (title == "enemy3")
        reg.Enemy3--;
}

void LevelCreation::spawnBoss(Registry &reg, std::string title) {
    if (title == "boss1" && reg.Boss != 0)
        spawn_BOSS1(reg, 5);
    if (title == "boss2" && reg.Boss != 0)
        spawn_BOSS2(reg);
    if (title == "boss3" && reg.Boss != 0)
        spawn_BOSS3(reg);
}

void LevelCreation::ReadEnemies(Registry &reg, int enemy_type) {
    std::string path = reg._enemyConfig[enemy_type]["path"];
    std::string title = reg._enemyConfig[enemy_type]["title"];
    json data;

    std::ifstream enemystream(path);
    if (!enemystream.is_open())
        throw ("failed to open enemy config file\n");
    enemystream >> data;
    enemystream.close();
    if ((title == "boss1" || title == "boss2" || title == "boss3") && reg.Boss != 0) {
        spawnBoss(reg, title);
        reg.BossAlive = true;
    }
    if (!reg.BossAlive) {
        create_Enemy(reg, data, title);
        enemyFactory(reg, title);
    }
}

void LevelCreation::WaveControll(Registry &reg) {
    int EnemyNbr = rand() % 3;


    if (EnemyNbr == 0 && reg.Enemy1 != 0)
        ReadEnemies(reg, 0);
    else if (EnemyNbr == 1 && reg.Enemy2 != 0)
        ReadEnemies(reg, 1);
    else if (EnemyNbr == 2 && reg.Enemy3 != 0)
        ReadEnemies(reg, 2);
    if (reg.EnemiesLevelNbr == 0) {
        if (reg.Level == 2)
            ReadEnemies(reg, 3);
        if (reg.Level == 4)
            ReadEnemies(reg, 4);
        if (reg.Level >= 5)
            ReadEnemies(reg, 5);
    }
    if (reg.BossAlive == false && reg.EnemiesLevelNbr <= 0) {
        reg.Level++;
        reg.Readlvl = false;
    }
}

void LevelCreation::operator()(Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::damage_t> &dmg) {
    if (reg.Readlvl == false) {
        ReadJsonLevels(reg);
        ReadJsonEnemies(reg);
        if (reg.Level <= 5)
            ReadLevelInfo(reg);
        else
            EndlessMode(reg);
    }
    if (std::clock() - reg.enemy_wave_time > 900000){
        WaveControll(reg);
        reg.enemy_wave_time = std::clock();
    }
}