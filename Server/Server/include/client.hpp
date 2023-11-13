/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** client
*/

#pragma once

#include "address.hpp"

//CLASS USED BY SERVER TO SAVE THE CLIENTS AND THEIR PROPERTIES
class Client 
{
    public:
        Client(sockaddr_in *_addr, std::string _username) { *addr.getAddress() = *_addr; username = _username; }
        Address *getAddress() { return &addr; }
        std::string *getUsername() { return &username; }

        bool lobby_ready = false;
    private:
        Address addr;
        std::string username;
};