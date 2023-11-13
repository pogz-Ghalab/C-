/*
** EPITECH PROJECT, 2023
** Create_Player.hpp
** File description:
** Create_Player
*/

#ifndef CREATE_PLAYER_HPP_
#define CREATE_PLAYER_HPP_

#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Components/DamageComp.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/PlayerIdComponent.hpp"
#include "../../../include/Components/HealthComp.hpp"
#include "../../../include/Components/DirectionComp.hpp"
#include "../../../include/Components/HitboxComp.hpp"
#include "../../../include/Components/RectComp.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/VelocityComp.hpp"
#include "../../../include/Components/UsernameComp.hpp"
#include "../../../include/Components/ScoreComp.hpp"
#include "../../../include/Components/PowersComp.hpp"
#include "../../../../Server/include/server.hpp"


#include <functional>

class Server;
class Registry;

class Create_Player {
    public:
        Create_Player() = default;
        ~Create_Player() = default;

        int PutPlayersInGame(int Players) {return (this->PlayersInGame = Players);};
        Entity Init_Player(Registry &reg, std::string *username);
        void Spawn_Players(Server &srv, Registry &reg);

    protected:
    private:
        int PlayersInGame = 0;
        int PlayerCreated = 0;
};

#endif /* !CREATE_PLAYER_HPP_ */
