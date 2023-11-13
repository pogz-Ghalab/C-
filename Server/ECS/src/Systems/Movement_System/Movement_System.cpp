/*
** EPITECH PROJECT, 2023
** Movement_System.cpp
** File description:
** Movement_System
*/

#include "Movement_System.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

Entity Movement_System::create_bullet(Registry &reg, component::position_t &pos, component::username_t &uname)
{
    Entity bullet = reg.spawn_entity_with_components(
        component::hitbox_t{15, 15},
        component::position_t{pos.x, pos.y},
        component::type_t{BULLET},
        component::velocity_t{10},
        component::rect_t{15, 15},
        component::bulletid_t{uname.username},
        component::damage_t{1});
    return (bullet);
}

Entity Movement_System::create_powerbullet(Registry &reg, component::position_t &pos, component::username_t &uname)
{
    Entity PowerBullet = reg.spawn_entity_with_components(
        component::hitbox_t{15, 15},
        component::position_t{pos.x, pos.y},
        component::type_t{POWERBULLET},
        component::velocity_t{12},
        component::rect_t{15, 15},
        component::bulletid_t{uname.username},
        component::damage_t{3});
    return (PowerBullet);
}

Entity Movement_System::create_lazerbullet(Registry &reg, component::position_t &pos, component::username_t &uname)
{
    Entity LazerBullet = reg.spawn_entity_with_components(
        component::hitbox_t{25, 1500},
        component::position_t{pos.x, pos.y},
        component::type_t{LAZERBULLET},
        component::velocity_t{12},
        component::rect_t{25, 1500},
        component::bulletid_t{uname.username},
        component::damage_t{0.5}
        );
    return (LazerBullet);
}

Entity Movement_System::create_dronebullet(Registry &reg, component::position_t &pos, component::username_t &uname)
{
    Entity DroneBullet = reg.spawn_entity_with_components(
        component::hitbox_t{15, 15},
        component::position_t{pos.x, pos.y},
        component::type_t{DRONEBULLET},
        component::velocity_t{11},
        component::rect_t{15, 15},
        component::bulletid_t {uname.username},
        component::damage_t{2}
        );
    return (DroneBullet);
}

void Movement_System::Shooting(Registry &reg, component::position_t &pos, component::username_t &uname)
{
    if (reg.getFire())
        Entity bullet = create_bullet(reg, pos, uname);
    reg.NoUte();
}

void Movement_System::PowerShooting(Registry &reg, component::position_t &pos, component::username_t &uname, component::score_t &score)
{
    if (reg.getFire() && score.EnemiesKilled >= 2) {
        Entity PowerBullet = create_powerbullet(reg, pos, uname);
        score.EnemiesKilled = score.EnemiesKilled - 2;
    }
    reg.NoUte();
}

void Movement_System::LazerBullet(Registry &reg, component::position_t &pos, component::username_t &uname, component::score_t &score)
{
    if (reg.getFire() && score.EnemiesKilled >= 2) {
        Entity LazerBullet = create_lazerbullet(reg, pos, uname);
        score.EnemiesKilled = score.EnemiesKilled - 2;
    }
    reg.NoUte();
}

void Movement_System::DroneShooting(Registry &reg, component::position_t &pos, component::username_t &uname) {
    if (reg.Drone_active == 1) {
        if (std::clock() - reg.drone_shooting_time > 99999) {
            Entity DroneBullet = create_dronebullet(reg, pos, uname);
            reg.drone_shooting_time = std::clock();
        }
    }
}

void Movement_System::moveObject(component::velocity_t &vel, component::position_t &pos)
{
    if (pos.x > 0)
    {
        pos.x = pos.x - vel.speed;
    }
    if (pos.x <= 0)
    {
        pos.x = std::rand() % 600 + 100;
        pos.y = std::rand() % 100;
    }
}

//////////////////////////////////////////////////////////////////////////////

void Movement_System::MoveEnemy1(Registry &reg, component::position_t &pos, component::direction_t &dir)
{
    if (pos.x >= 500 && dir.left == true && dir.up == true)
    {
        pos.x--;
        if (pos.x <= 500)
            dir.left = false;
    }
    if (pos.y >= -101 && dir.up == true && dir.left == false)
    {
        pos.y--;
        if (pos.y <= -101)
            dir.up = false;
    }
    if (pos.x <= 1300 && dir.left == false && dir.up == false)
    {
        pos.x++;
        if (pos.x >= 1300)
            dir.left = true;
    }
    if (pos.y <= 700 && dir.up == false && dir.left == true)
    {
        pos.y++;
        if (pos.y >= 700)
            dir.up = true;
    }
}

void Movement_System::MoveEnemy2(Registry &reg, component::position_t &pos, component::direction_t &dir)
{
    if (pos.x >= 700 && dir.left == true)
    {
        pos.x--;
        if (pos.x <= 500)
            dir.left = false;
    }
    if (pos.y >= -101 && dir.up == true)
    {
        pos.y--;
        if (pos.y <= -101)
            dir.up = false;
    }
    if (pos.y <= 700 && dir.up == false)
    {
        pos.y++;
        if (pos.y >= 700)
            dir.up = true;
    }
}

void Movement_System::MoveEnemy3(Registry &reg, component::position_t &pos, component::direction_t &dir)
{
    if (pos.x >= 500 && dir.left == true)
    {
        pos.x--;
        if (pos.x <= 500)
            dir.left = false;
    }
    if (pos.y >= -101 && dir.up == true)
    {
        pos.y--;
        if (pos.y <= -101)
            dir.up = false;
    }
    if (pos.x <= 1300 && dir.left == false)
    {
        pos.x++;
        if (pos.x >= 1300)
            dir.left = true;
    }
    if (pos.y <= 700 && dir.up == false)
    {
        pos.y++;
        if (pos.y >= 700)
            dir.up = true;
    }
}

void Movement_System::moveEnemies(Registry &reg, component::type_t &type, component::position_t &pos, component::direction_t &dir)
{
    if (clock() - pos.movement_clock > 1500)
    {
        if (type.type == ENEMY1)
            MoveEnemy1(reg, pos, dir);
        if (type.type == ENEMY2)
            MoveEnemy2(reg, pos, dir);
        if (type.type == ENEMY3)
            MoveEnemy3(reg, pos, dir);
        pos.movement_clock = clock();
    }
}

void Move_Enemy(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::direction_t> &dir)
{
    for (std::size_t t = 0; t < type.size() && t < pos.size() && t < dir.size(); t++)
    {
        if (type[t] && pos[t])
        {
            auto &temptype = type[t];
            auto &temppos = pos[t];
            auto &tempdir = dir[t];
            if (temptype.value().type == ENEMY1 || temptype.value().type == ENEMY2 || temptype.value().type == ENEMY3)
                m->moveEnemies(reg, temptype.value(), temppos.value(), tempdir.value());
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Entity Movement_System::createParallax(Registry &reg)
{
    Entity parallax = reg.spawn_entity_with_components(
        component::velocity_t{1},
        component::type_t{PARALLAX},
        component::parallax_t{0, 0, 1280, 0});
    parallaxCreate = true;
    return (parallax);
}

void Movement_System::moveParallax(component::velocity_t &vel, component::parallax_t &par)
{
    if (par.first_x == -1280)
        par.first_x = 1280;
    if (par.second_x == -1280)
        par.second_x = 1280;
    par.first_x = par.first_x - vel.speed;
    par.second_x = par.second_x - vel.speed;
}

void Movement_System::Parallax(Registry &reg)
{
    if (!parallaxCreate)
        Entity parallax = createParallax(reg);
}

void Move_Parallax(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par)
{

    for (std::size_t t = 0; t < par.size() && t < velo.size(); t++)
    {
        if (par[t] && velo[t])
        {
            auto &Parpos = par[t];
            auto &Parvel = velo[t];
            m->moveParallax(velo[t].value(), par[t].value());
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void Movement_System::movePlayer(Registry &reg, component::username_t &uname, component::position_t &pos, char input, component::velocity_t &velo, component::score_t &score)
{
    int speed = 50;
    switch (input)
    {
    case 'U':
        if ((pos.y - velo.speed) > 0)
            pos.y -= velo.speed;
        break;
    case 'D':
        if ((pos.y + velo.speed) < 900)
            pos.y += velo.speed;
        break;
    case 'R':
        if ((pos.x + velo.speed) < 1200)
            pos.x += velo.speed;
        break;
    case 'L':
        if ((pos.x - velo.speed) > 0)
            pos.x -= velo.speed;
        break;
    case 'S':
        reg.Ute();
        Shooting(reg, pos, uname);
        break;
    case 'I':
        reg.Ute();
        PowerShooting(reg, pos, uname, score);
        break;
    case 'O':
        reg.Ute();
        LazerBullet(reg, pos, uname, score);
        break;
    default:
        break;
    }
}

void Move_Player(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::score_t> &score) {
    vector<string> input;

    for (int i = 0; i < reg.srv->INPUT_QUEUE.size(); i++) {
        input = reg.srv->GetFirstFromInput_Queue();

        if (input.size() == 0)
            continue;

        string username = input.at(0);
        string command = input.at(1);

        for (std::size_t t = 0; t < pos.size() && t < uname.size() && t < score.size(); t++) {
            if (pos[t] && uname[t] && score[t]) {
                auto &temppos = pos[t];
                auto &playeruname = uname[t];
                auto &playerScore = score[t];

                if (uname[t].value().username == username && reg.StopActive == 0) {
                    m->movePlayer(reg, playeruname.value(), pos[t].value(), command[0], velo[t].value(), playerScore.value());
                    //m->DroneShooting(reg, temppos.value(), playeruname.value());
                    //break;
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void Movement_System::moveRocks(Registry &reg, component::position_t &pos, component::velocity_t &velo, int entity)
{
    if (std::clock() - pos.movement_clock > 20000)
    {
        if (pos.x < -140)
            reg.kill_entity(reg.entity_from_index(entity));
        else
            pos.x -= velo.speed;
        pos.movement_clock = std::clock();
    }
}

void Move_Rocks(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par)
{
    for (std::size_t t = 0; t < type.size() && t < pos.size() && t < velo.size(); t++)
    {
        if (type[t] && pos[t])
        {
            auto &temptype = type[t];
            auto &temppos = pos[t];
            auto &tempvelo = velo[t];
            if (type[t].value().type == OBSFLOOR)
            {
                m->moveRocks(reg, pos[t].value(), velo[t].value(), t);
            }
        }
    }
}

void Movement_System::movePowerUps(Registry &reg, component::position_t &pos, component::velocity_t &velo, int entity)
{
    if (std::clock() - pos.movement_clock > 20000) {
        if (pos.x < 40)
            reg.kill_entity(reg.entity_from_index(entity));
        else
            pos.x -= velo.speed;
        pos.movement_clock = std::clock();
    }
}

void Move_Powerups(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par)
{
    for (std::size_t t = 0; t < type.size() && t < pos.size() && t < velo.size(); t++) {
        if (type[t] && pos[t]){
            auto &temptype = type[t];
            auto &temppos = pos[t];
            auto &tempvelo = velo[t];
            if (type[t].value().type == POWERUP) {
                m->movePowerUps(reg, pos[t].value(), velo[t].value(), t);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void zigzag(Registry &reg, component::position_t &pos)
{
    if (pos.y <= 600 && !reg.ascend)
    {
        if (pos.x >= 700 && pos.x <= 1450 || reg.gate == true)
        {
            reg.gate = false;
            pos.x += (100 * reg.movement_dir_switch);
            if (reg.movement_dir_switch == 1)
            {
                pos.direction = Direction::East;
            }
            else if (reg.movement_dir_switch == -1)
            {
                pos.direction = Direction::West;
            }
        }
        else
        {
            if (reg.movement_dir_switch == 1)
            {
                pos.y += 200;
            }
            else
            {
                pos.y += 10;
            }
            reg.movement_dir_switch *= -1;
            pos.direction = Direction::South;
            reg.gate = true;
        }
    }
    else
    {
        reg.ascend = true;
    }
    if (reg.ascend)
    {
        pos.y -= 100;
        pos.direction = Direction::North;
        if (pos.y < -100)
        {
            reg.ascend = false;
        }
    }
}

void moveSnakeHead(Registry &reg, component::position_t &pos)
{
    if (std::clock() - reg.snake_move_time > 500000)
    { // 500000){
        reg.snake_temp_x = pos.x;
        reg.snake_temp_y = pos.y;
        reg.snake_direction = pos.direction;

        // pos.x -= 100;
        zigzag(reg, pos);

        reg.snake_move_time = std::clock();

        reg.snake_switch = true;
    }
}

void moveSnakeBody(Registry &reg, component::position_t &pos)
{
    if (pos.x == reg.snake_temp_x && pos.y == reg.snake_temp_y)
        return;
    // save current pos
    int temp_x = pos.x;
    int temp_y = pos.y;
    Direction temp_dir = pos.direction;

    // change position
    pos.x = reg.snake_temp_x;
    pos.y = reg.snake_temp_y;
    pos.direction = reg.snake_direction;

    // save previous pos for the next body node
    reg.snake_temp_x = temp_x;
    reg.snake_temp_y = temp_y;
    reg.snake_direction = temp_dir;
}

void Move_Snake(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par)
{
    for (std::size_t t = 0; t < type.size() && t < pos.size(); t++)
    {
        if (type[t] && pos[t])
        {
            auto &temptype = type[t];
            auto &temppos = pos[t];
            if (type[t].value().type == SNAKE_HEAD)
            {
                moveSnakeHead(reg, pos[t].value());
            }
            else if (reg.snake_switch == true && (type[t].value().type == SNAKE_NODE || type[t].value().type == SNAKE_TAIL))
            {
                moveSnakeBody(reg, pos[t].value());
                if (type[t].value().type == SNAKE_TAIL)
                {
                    reg.snake_switch = false;
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void MoveVertically(Registry &reg, component::position_t &pos)
{
    if (std::clock() - reg.boss2_movement_time > 20000){
        int SPEED = 1;

        if (pos.y < -100){
            reg.boss2 = 1;
            pos.y += 5;
        }
        else if (pos.y >= 550){
            reg.boss2 = -1;
            pos.y -= 5;
        } else {
            pos.y += (reg.boss2 * SPEED);
        }
        reg.boss2_movement_time = std::clock();
    }
}

void Move_Boss2(Movement_System *m, Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par)
{
    for (std::size_t t = 0; t < type.size() && t < pos.size(); t++) {
        if (type[t] && pos[t]){
            auto &temptype = type[t];
            auto &temppos = pos[t];
            if (type[t].value().type == BOSS2) {
                MoveVertically(reg, pos[t].value());
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


void Movement_System::operator()(Registry &reg, sparse_array<component::velocity_t> &velo, sparse_array<component::username_t> &uname, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::parallax_t> &par, sparse_array<component::direction_t> &dir, sparse_array<component::score_t> &score) 
{
    Parallax(reg);

    Move_Parallax(this, reg, velo, uname, type, pos, par);
    Move_Rocks(this, reg, velo, uname, type, pos, par);
    Move_Enemy(this, reg, velo, uname, type, pos, dir);
    Move_Powerups(this, reg, velo, uname, type, pos, par);
    Move_Player(this, reg, velo, uname, type, pos, score);
    Move_Snake(this, reg, velo, uname, type, pos, par);
    Move_Boss2(this, reg, velo, uname, type, pos, par);
    
}
