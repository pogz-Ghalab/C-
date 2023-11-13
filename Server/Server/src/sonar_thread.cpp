/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** listen_thread
*/

#include <iostream>
#include "../include/server.hpp"
bool Protocol(Server *srv, pair<sockaddr_in, string> ret);
bool RegisterNewClient(Server *srv, pair<sockaddr_in, string> ret);

//THREAD FUNCTION THAT HANDLES LISTENING IN THE SERVER
void Sonar(Server *srv, bool *online)
{
    while (*online){
        pair<sockaddr_in, string> ret = srv->RECEIVE();

        if (ret.second != ""){
            cout << "Incoming msg -> " << ret.second << endl;
            ret.second = srv->b.Decode(ret.second);
            if (RegisterNewClient(srv, ret))
                continue;
            if (Protocol(srv, ret))
                continue;
            srv->PushToInput_Queue(split_data(ret.second, ","));
        }
    }
}

bool RegisterNewClient(Server *srv, pair<sockaddr_in, string> ret)
{
    if (*srv->GetState() == State::Lobby &&
                            srv->FindSpecificClient(&ret.first) == NULL &&
                                                                *srv->GetConnectedNbr() < 4){
        cout << "+ New Client Joined! +" << endl;
        srv->AddClient(&ret.first, ret.second);
        return true;
    }
    return false;
}

bool Protocol(Server *srv, pair<sockaddr_in, string> ret)
{
    if (ret.second == "Exit"){
        srv->RemoveClient(&ret.first);
        return true;
    }
    else if (ret.second == "Ready" && *srv->GetState() == State::Lobby){ //lobby
        srv->SetClientReadiness(&ret.first, true);
        return true;
    }
    else if (ret.second == "Unready" && *srv->GetState() == State::Lobby){ //lobby make enum later
        srv->SetClientReadiness(&ret.first, false);
        return true;
    }
    return false;
}














/* void Protocol(Server *srv, sockaddr_in cliAddr, string msg)
{
    if (msg == "Exit"){
        srv->RemoveClient(&cliAddr);
    }
    else if (msg == "Ready" && *srv->GetState() == State::Lobby){ //lobby
        srv->SetClientReadiness(&cliAddr, true);
    }
    else if (msg == "Unready" && *srv->GetState() == State::Lobby){ //lobby make enum later
        srv->SetClientReadiness(&cliAddr, false);
    } else {
        srv->SEND("ERROR", &cliAddr);
    }
} */
