/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** send_thread
*/

#include <iostream>
#include "../include/server.hpp"

using std::cout;
using std::endl;
using std::string;
using std::pair;

void LiveStream(Server *srv, bool *online)
{
    while (*online){
        while (srv->OUTPUT_QUEUE.size() != 0){
            srv->SendToAllClients(srv->GetFirstFromOutput_Queue());
        }
    }
}



