/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** server
*/

#pragma once

#include <cstring>
#include <signal.h>

#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "address.hpp"
#include "client.hpp"
#include "thread.hpp"
#include "binary.hpp"
#include <bitset>
#include "../../ECS/include/Libs/ECS/Registry.hpp"

using std::string;
using std::pair;
using std::vector;
using std::optional;
using std::cout;
using std::endl;
using std::mutex;

class Registry;
class Binary;

enum State
{
    Lobby,
    InGame,
    GameOver
};



////////////////////////////////////////////////////////////////////////////////////////////
//CLASS FOR THE MAIN SERVER
class Server 
{
    public:
        Server();
    /*---------------INPUT & OUTPUT-------------------*/
        Binary b;

        vector<vector<string>> INPUT_QUEUE;
        vector<string> OUTPUT_QUEUE;
        mutex m_output;
        mutex m_input;
        void ClearOutput_Queue();
        void ClearInput_Queue();
        void PushToOutput_Queue(string s);
        void PushToInput_Queue(vector<string> incoming_msg);
        string GetFirstFromOutput_Queue(void);
        vector<string> GetFirstFromInput_Queue(void);

    /*---------------Game------------------------------*/

        State *GetState() { return &state; };
        std::string FetchLobbyData(void);
        
    /*---------------Communication------------------------------*/

        void SEND(string message, Client *cli);
        void SEND(string message, sockaddr_in *cliaddr);
        void SendToAllClients(string msg);
        pair<sockaddr_in, string> RECEIVE(void);

    /*---------------Clients------------------------------*/

        std::vector<Client *> *GetClients();
        void AddClient(sockaddr_in *cliaddr, string username);
        void RemoveClient(sockaddr_in *cliaddr);
        int *GetConnectedNbr() { return &connectedNbr; }
        Client *FindSpecificClient(sockaddr_in *cliAddr);
        void SetClientReadiness(sockaddr_in *cliAddr, bool ready);
        short clientcount = 0;

    /*----------------ECS---------------------------------*/

        void Init_ECS();
        int getConnectedNbr() { return (this->connectedNbr); }
        Registry *getRegistrty() { return (this->reg_); }

    /*---------------Threads------------------------------*/

        void Init_Threads();
        void Shutdown_Threads();

    //////////    
    private:
    //////////     

        /*---------------Game---------------*/

            State state = State::Lobby;

        /*---------------Communication--------------*/

            int socket_fd;
            Address *addr;

        /*---------------Clients---------------------*/

            std::vector<Client *> connected_clients;
            int connectedNbr = 0;

        /*---------------Threads------------------*/

            std::vector<Thread *> thread_list;

        /*---------------ECS/Systems------------------*/

            Registry *reg_ = NULL;
        
};
////////////////////////////////////////////////////////////////////////////////////////////////////




void LiveStream(Server *srv, bool *online);
void Main_Loop(Server *srv);
std::vector<std::string> split_data(std::string str, const char* delim);
int check_size(std::vector<std::string> res);
