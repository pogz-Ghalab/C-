/*
** EPITECH PROJECT, 2023
** Hitbox.cpp
** File description:
** Hitbox
*/

#include "Hitbox.hpp"

bool Hitbox::Collision(component::type_t const &type, component::rect_t const &rect1, component::rect_t const &rect2, component::position_t const &pos1, component::position_t const &pos2)
{
    if (type.type == OBSFLOOR)
    {
        if (pos1.y < (pos2.y + rect2.height + 50) && (pos1.y + rect1.height) > pos2.y)
            if ((pos1.x < (pos2.x + rect2.width - 50) && (pos1.x + rect1.width) > pos2.x))
                return (true);
    }
    else
    {
        if (pos1.y < (pos2.y + rect2.height - 50) && (pos1.y + rect1.height + 50) > pos2.y)
            if ((pos1.x < (pos2.x + rect2.width - 70) && (pos1.x + rect1.width) > pos2.x))
                return (true);
    }
    return (false);
}

int typeReturn(component::type_t const &Etype)
{
    switch (Etype.type)
    {
    case ENEMY1:
        return (1);
        break;
    case ENEMY2:
        return (2);
        break;
    case ENEMY3:
        return (3);
        break;
    case SNAKE_HEAD:
        return (4);
        break;
    case BOSS2:
        return (5);
        break;
    case BOSS3:
        return (6);
        break;
    default:
        return (0);
    }
}

int Hitbox::Handle_Hitbox_Player(Registry &reg, component::type_t const &Etype, component::type_t const &Atype, sparse_array<component::damage_t> const &dmg, sparse_array<component::health_t> &hp, sparse_array<component::score_t> &score, int t, int x)
{
    if (Atype.type == PLAYER && reg.ShieldActive == 0)
    {
        hp[x].value().hp = hp[x].value().hp - dmg[t].value().dmg;
        hp[t].value().hp = hp[t].value().hp - dmg[x].value().dmg;
        if (hp[t].value().hp <= 0)
            reg.kill_entity(reg.entity_from_index(t));
        if (hp[x].value().hp > 0)
        {
            std::cout << "We have taken a hit\n";
            reg.Drone_active = 0;
        }
        else
            reg.kill_entity(reg.entity_from_index(x));
    }
    else if (Atype.type == BULLET || Atype.type == POWERBULLET || Atype.type == LAZERBULLET || Atype.type == DRONEBULLET)
    {
        if (Etype.type == SNAKE_HEAD || Etype.type == SNAKE_NODE || Etype.type == SNAKE_TAIL)
            reg.snake_hp = reg.snake_hp - dmg[x].value().dmg;
        else
            hp[t].value().hp = hp[t].value().hp - dmg[x].value().dmg;
        if (hp[t].value().hp > 0)
            std::cout << "We damaged them\n";
        else
        {
            if (reg.snake_hp <= 0 && !reg.snak_killed)
            {
                reg.Kill_Snake = true;
                return (0);
            }
            if (Etype.type == BOSS2 || Etype.type == BOSS3)
                reg.BossAlive = false;
            if (Etype.type == ENEMY1 || Etype.type == ENEMY2 || Etype.type == ENEMY3)
                reg.EnemiesLevelNbr--;
            reg.kill_entity(reg.entity_from_index(t));
            return (typeReturn(Etype));
        }
        reg.kill_entity(reg.entity_from_index(x));
    }
    return (0);
}

void updateScore(int res, component::score_t &score)
{
    if (res == 0)
        return;
    switch (res)
    {
    case 1:
        score.score += 10;
        break;
    case 2:
        score.score += 20;
        break;
    case 3:
        score.score += 30;
        break;
    case 4:
        score.score += 100;
        break;
    case 5:
        score.score += 200;
        break;
    case 6:
        score.score += 300;
        break;
    default:
        break;
    }
    score.EnemiesKilled++;
}

void Hitbox::Handle_Hitbox_PowerUp(Registry &reg, component::type_t const &PWType, component::type_t const &Ptype, component::Powers_t &pow, sparse_array<component::damage_t> const &dmg, sparse_array<component::health_t> &hp, sparse_array<component::score_t> &score, sparse_array<component::PowerUpType_t> &PowerUpType, int t, int x) {
    if (std::clock() - reg.ShieldActive_Timer > 4000000) {
        reg.ShieldActive = 0;
        reg.ShieldActive_Timer = std::clock();
    }
    if (std::clock() - reg.StopActive_Timer > 4000000) {
        reg.StopActive = 0;
        reg.StopActive_Timer = std::clock();
    }
    if (std::clock() - reg.droneactive_timer > 4000000) {
        reg.Drone_active = 0;
        reg.droneactive_timer = std::clock();
    }
    if (PowerUpType[t].value().type == HEART) {
        hp[x].value().hp = hp[x].value().hp + 2;
        pow.power = 1;
    }
    if (PowerUpType[t].value().type == SHIELD) {
        reg.ShieldActive = 1;
        pow.power = 2;
    }
    if (PowerUpType[t].value().type == STOP) {
        reg.StopActive = 1;
        pow.power = 3;
    }
    if (PowerUpType[t].value().type == DRONE) {
        reg.Drone_active = 1;
        pow.power = 4;
    }
    reg.kill_entity(reg.entity_from_index(t));
}

void Hitbox::operator()(Registry &reg, sparse_array<component::health_t> &hp, sparse_array<component::position_t> &pos, sparse_array<component::rect_t> &rec, sparse_array<component::score_t> &score, sparse_array<component::type_t> &type, sparse_array<component::damage_t> &dmg, sparse_array<component::bulletid_t> &bid, sparse_array<component::username_t> &uname, sparse_array<component::PowerUpType_t> &pwtype, sparse_array<component::Powers_t> &pow) {
    for (std::size_t t = 0; t < pos.size() && t < rec.size() && t < type.size(); t++) {
        if (pos[t] && rec[t] && type[t]) {
            if (type[t].value().type == OBSFLOOR || type[t].value().type == ENEMY1 || type[t].value().type == ENEMY2 || type[t].value().type == ENEMY3 || type[t].value().type == SNAKE_HEAD || type[t].value().type == SNAKE_NODE || type[t].value().type == SNAKE_TAIL || type[t].value().type == BOSS2 || type[t].value().type == BOSS3 || type[t].value().type == EBULLET) {
                auto &EnemyType = type[t];
                auto &EnemyPos = pos[t];
                auto &EnemyRec = rec[t];
                for (std::size_t x = 0; x < pos.size() && x < rec.size() && x < type.size(); x++) {
                    if (pos[x] && rec[x] && type[x]) {
                        if (x == t)
                            continue;
                        if (type[x].value().type == PLAYER || type[x].value().type == BULLET || type[x].value().type == POWERBULLET || type[x].value().type == LAZERBULLET || type[x].value().type == DRONEBULLET) {
                            auto &PlayerType = type[x];
                            auto &PlayerPos = pos[x];
                            auto &PlayerRec = rec[x];
                            if (Collision(EnemyType.value(), EnemyRec.value(), PlayerRec.value(), EnemyPos.value(), PlayerPos.value()) == true) {
                                if (PlayerType.value().type == BULLET || PlayerType.value().type == POWERBULLET || PlayerType.value().type == LAZERBULLET || PlayerType.value().type == DRONEBULLET) {
                                    for (std::size_t y = 0; y < uname.size() && y < type.size() && y < score.size(); y++) {
                                        if (uname[y] && type[y] && score[y]) {
                                            if (type[y].value().type == PLAYER && uname[y].value().username == bid[x].value().bulletid) {
                                                auto &Pscore = score[y];
                                                updateScore(Handle_Hitbox_Player(reg, EnemyType.value(), PlayerType.value(), dmg, hp, score, t, x), Pscore.value());
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                } else {
                                    Handle_Hitbox_Player(reg, EnemyType.value(), PlayerType.value(), dmg, hp, score, t, x);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (reg.Kill_Snake) {
        for (std::size_t x = 0; x < type.size(); x++) {
            if (type[x]) {
                if (type[x].value().type == SNAKE_HEAD || type[x].value().type == SNAKE_NODE || type[x].value().type == SNAKE_TAIL)
                    reg.kill_entity(reg.entity_from_index(x));
            }
        }
        reg.snak_killed = true;
        reg.BossAlive = false;
        reg.Kill_Snake = false;
    }
    for (std::size_t t = 0; t < pos.size() && t < rec.size() && t < type.size() && t < pwtype.size(); t++) {
        if (pos[t] && rec[t] && type[t] && pwtype[t]) {
            if (type[t].value().type == POWERUP) {
                auto &PowerUpType = type[t];
                auto &PowerPos = pos[t];
                auto &PowerRec = rec[t];
                auto &Pwtype = pwtype[t];
                for (std::size_t x = 0; x < pos.size() && x < rec.size() && x < type.size(); x++) {
                    if (pos[x] && rec[x] && type[x]) {
                        if (x == t)
                            continue;
                        if (type[x].value().type == PLAYER) {
                            auto &PlayerType = type[x];
                            auto &PlayerPos = pos[x];
                            auto &PlayerRec = rec[x];
                            auto &PlayerPow = pow[x];
                            if (Collision(type[x].value(), PowerRec.value(), PlayerRec.value(), PowerPos.value(), PlayerPos.value()) == true) {
                                Handle_Hitbox_PowerUp(reg, PowerUpType.value(), PlayerType.value(), PlayerPow.value(), dmg, hp, score, pwtype, t, x);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
