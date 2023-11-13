/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** thread
*/

#pragma once

#include <thread>
#include <iostream>
#include "client.hpp"

class Client;
void ClientSonar(Client *cli, bool *online);
void SendToServer(Client *cli, bool *online);

//CLASS FOR INITIALIZING AND HOLDING A THREAD
class Thread
{
    public:
        Thread(Client *cli, int option) {
            if (option == 1){
                t = new std::thread(ClientSonar, cli, &online);
            } 
            else if (option == 2){
                t = new std::thread(SendToServer, cli, &online);
            } else { std::cout << "Error in creating threads!" << std::endl; return; }
            t->detach();
            online = true;
            std::cout << "Thread Created!" << std::endl;
        }
        void TerminateThread(void) { online = false; }

    private:
        bool online = false;
        std::thread *t;
};