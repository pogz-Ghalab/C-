/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** socket
*/

#pragma once

#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>
#include <cstring>
#include <signal.h>

#include <iostream>

//CLASS TO SAVE THE ADDRESS OF SERVER OR CLIENT
class Address 
{
    public:
        Address(sockaddr_in *a) { address = *a; addressLength = sizeof(address); }
        Address() {}
        sockaddr_in *getAddress(){ return &address; }
        socklen_t getAddrLen(){ return addressLength; }

    private:
        sockaddr_in address;
        socklen_t addressLength;
};