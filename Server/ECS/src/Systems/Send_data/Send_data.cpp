/*
** EPITECH PROJECT, 2023
** Send_data.cpp
** File description:
** Send_data
*/

#include "Send_data.hpp"
#include <string>

std::string Send_data::SendPosition(component::position_t pos)
{

    std::string positionX = std::to_string(pos.x);
    std::string positionY = std::to_string(pos.y);
    std::string position = positionX + "," + positionY;
    return (position);
}

std::string SendPowerUp(component::PowerUpType_t powuptype)
{
    switch (powuptype.type)
    {
    case HEART:
        return ("HEART");
    case SHIELD:
        return ("SHIELD");
    case STOP:
        return ("STOP");
    case DRONE:
        return ("DRONE");
    }
    return ("NVT");
}

std::string Send_data::SendType(component::type_t type)
{
    switch (type.type)
    {
    case ENEMY1:
        return ("E1");
    case ENEMY2:
        return ("E2");
    case ENEMY3:
        return ("E3");
    case BULLET:
        return ("B1");
    case POWERBULLET:
        return ("B2");
    case LAZERBULLET:
        return ("B3");
    case DRONEBULLET:
        return ("B4");
    case BOSS2:
        return ("BOSS2");
    case BOSS3:
        return ("BS3");
    case EBULLET:
        return ("EB1");
    case OBSFLOOR:
        return ("OBSFLOOR");
    case SNAKE_HEAD:
        return ("S_H");
    case SNAKE_NODE:
        return ("S_N");
    case SNAKE_TAIL:
        return ("S_T");
    case POWERUP:
        return ("POWERUP");
    }
    return ("NVT");
}

void Send_data::operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::username_t> &uname, sparse_array<component::parallax_t> &par, sparse_array<component::health_t> &health, sparse_array<component::PowerUpType_t> &powupType, sparse_array<component::Powers_t> &pow)
{
    std::string toClientMsg = "";

    for (std::size_t t = 0; t < par.size(); t++)
    {
        if (type[t] && par[t])
        {
            auto &Parpos = par[t];
            toClientMsg = toClientMsg + "P," + std::to_string(Parpos.value().first_x) + "," + std::to_string(Parpos.value().first_y) + ",P," + std::to_string(Parpos.value().second_x) + "," + std::to_string(Parpos.value().second_y) + ",";
        }
    }

    for (std::size_t x = 0; x < type.size() && x < pos.size() && x < uname.size(); x++)
    {
        if (type[x] && pos[x] && uname[x])
        {
            auto &playerType = type[x];
            auto &playerPos = pos[x];
            auto &playerUname = uname[x];
            toClientMsg = toClientMsg + uname[x].value().username + "," + std::to_string(pos[x].value().x) + "," + std::to_string(pos[x].value().y) + ",";
        }
    }

    for (std::size_t t = 0; t < type.size() && t < pos.size(); t++)
    {
        if (type[t] && pos[t])
        {
            auto &temptype = type[t];
            auto &temppos = pos[t];
            if (SendType(type[t].value()) != "NVT" && SendType(type[t].value()) != "POWERUP")
            {
                if (SendType(type[t].value()) == "S_H" || SendType(type[t].value()) == "S_N" || SendType(type[t].value()) == "S_T")
                {
                    toClientMsg = toClientMsg + SendType(type[t].value()) + pos[t].value().getDirection();
                }
                else
                {
                    toClientMsg = toClientMsg + SendType(type[t].value());
                }
                toClientMsg = toClientMsg + "," + SendPosition(pos[t].value()) + ",";
            }
        }
    }

    for (std::size_t t = 0; t < type.size() && t < health.size(); t++)
    {
        if (type[t] && health[t]) {
            auto &htype = type[t];
            auto &phealth = health[t];
            if (htype.value().type == PLAYER) {
                toClientMsg = toClientMsg + "H" + "," + std::to_string(health[t].value().hp) + ",";
                if (pow[t].value().power == 2)
                    toClientMsg = toClientMsg + "SHIELDACTIVE," + std::to_string(pos[t].value().x) + "," + std::to_string(pos[t].value().y) + ",";     
                if (pow[t].value().power == 3)
                    toClientMsg = toClientMsg + "STOPACTIVE," + std::to_string(pos[t].value().x) + "," + std::to_string(pos[t].value().y) + ",";  
            }
        }
    }

    for (std::size_t a = 0; a < type.size() && a < pos.size() && a < powupType.size(); a++)
    {
        if (type[a] && pos[a] && powupType[a])
        {
            auto &tmpType = type[a];
            auto &tmpPos = pos[a];
            auto &tmpPowupType = powupType[a];
            if (SendType(type[a].value()) == "POWERUP")
            {
                // toClientMsg = toClientMsg + SendType(type[a].value());
                if (SendPowerUp(powupType[a].value()) == "HEART")
                    toClientMsg = toClientMsg + "HEART" + "," + SendPosition(pos[a].value()) + ",";
                if (SendPowerUp(powupType[a].value()) == "SHIELD")
                    toClientMsg = toClientMsg + "SHIELD" + "," + SendPosition(pos[a].value()) + ",";
                if (SendPowerUp(powupType[a].value()) == "STOP")
                    toClientMsg = toClientMsg + "STOP" + "," + SendPosition(pos[a].value()) + ",";
                if (SendPowerUp(powupType[a].value()) == "DRONE")
                    toClientMsg = toClientMsg + "DRONE" + "," + SendPosition(pos[a].value()) + ",";
            }
        }
    }

    if (reg.Drone_active == 1)
    {
        for (std::size_t x = 0; x < type.size() && x < pos.size() && x < uname.size(); x++)
        {
            if (type[x] && pos[x] && uname[x])
            {
                auto &playerType = type[x];
                auto &playerPos = pos[x];
                auto &playerUname = uname[x];
                toClientMsg = toClientMsg + "DRONEACTIVE," + std::to_string(pos[x].value().x) + "," + std::to_string(pos[x].value().y) + ",";
            }
        }
    }
    std::cout << toClientMsg << std::endl;
    toClientMsg = "Game," + toClientMsg;
    reg.srv->PushToOutput_Queue(toClientMsg);
}