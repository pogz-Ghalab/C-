/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** send_thread
*/

#include <iostream>
#include "../include/client.hpp"

using std::cout;
using std::endl;
using std::string;
using std::pair;

void SendToServer(Client *cli, bool *online)
{
    int a = 1;
    while (*online){
        if (a && cli->ready){
            string s = "Ready";
            s = cli->b.Encode(s);
            cli->SEND(s);
            a--;
        }
    }
    cout << "Sonar Terminating!" << endl;
    return;
}
