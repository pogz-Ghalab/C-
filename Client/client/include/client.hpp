/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** client
*/

#pragma once
#include <vector>
#include "address.hpp"
#include "thread.hpp"
#include "binary.hpp"
#include "../../game/include/Game.hpp"

using std::cout;
using std::endl;
using std::string;

class Thread;
class Binary;
class Game;

class Client
{
    public:
        bool TERMINATE_CLIENT = false;
        Binary b;

        Game *game;

        Client(char *serverIP);
    /*---------------Game------------------------------*/
        string *GetUsername() { return &username; }
        bool ready = false;

    /*---------------Communication------------------------------*/
        void SEND(string message);
        string RECEIVE(void);

    /*---------------Threads------------------------------*/
        void Init_Threads();
        void Shutdown_Threads();
    //////////    
    private:
    //////////
        /*---------------Game------------------*/
        string username;

        /*---------------Communication------------------*/
        int socket_fd;
        Address *addr;
        Address *serverAddr;

        /*---------------Threads------------------*/
        std::vector<Thread *> thread_list;
};
