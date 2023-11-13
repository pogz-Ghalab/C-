/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** loops
*/

#include "../../ECS/src/Systems/PlayerCreation_System/Create_Player.hpp"
#include "../include/server.hpp"
#include <time.h>
using std::cout;
using std::endl;
using std::string;

void InGame_logic(Server *srv, Create_Player *p, Registry *reg);
bool AreClientsReady(Server *srv);
void StartGame(Server *srv);
void SendLobbyDataToClient(Server *srv);

//MAIN LOOP
void Main_Loop(Server *srv)
{
    Create_Player *p = new Create_Player();
    Registry *reg = srv->getRegistrty();

    while (1){

        if (*srv->GetState() == State::Lobby){
            if (AreClientsReady(srv)){
                StartGame(srv);
                continue;
            }
            SendLobbyDataToClient(srv);
            
        }
        else if (*srv->GetState() == State::InGame) {
            InGame_logic(srv, p, reg);
        }
    }
}

void InGame_logic(Server *srv, Create_Player *p, Registry *reg)
{
    clock_t start = clock();

    int SPEED_OF_SERVER = 1700;

    while (*srv->GetState() == State::InGame){
        if (clock() - start > SPEED_OF_SERVER){
            p->Spawn_Players(*srv, *reg);
            reg->run_systems();

            start = clock();
        }
    }
}

bool AreClientsReady(Server *srv)
{
    srv->FetchLobbyData();
    if (srv->GetClients()->size() == 0)
        return false;
    for (int i = 0; i < srv->GetClients()->size(); i++){
        if (srv->GetClients()->at(i)->lobby_ready == false){
            return false;
        }
    }
    return true;
}

void StartGame(Server *srv)
{
    srv->ClearOutput_Queue();
    srv->ClearInput_Queue();
    srv->PushToOutput_Queue("Start");
    *srv->GetState() = State::InGame;
}

void SendLobbyDataToClient(Server *srv)
{
    srv->PushToOutput_Queue(srv->FetchLobbyData());
}