/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** thread
*/

#pragma once

#include <thread>
#include <iostream>
#include "server.hpp"

class Server;
void Sonar(Server *srv, bool *online);
void LiveStream(Server *srv, bool *online);
//CLASS FOR INITIALIZING AND HOLDING A THREAD
class Thread
{
    public:
        Thread(Server *srv, int option) {
            if (option == 1){
                t = new std::thread(Sonar, srv, &online);
            } 
            else if (option == 2){
                t = new std::thread(LiveStream, srv, &online);
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
