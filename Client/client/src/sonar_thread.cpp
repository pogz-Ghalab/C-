/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** listen_thread
*/

#include <iostream>
#include "../include/client.hpp"

using std::cout;
using std::endl;
using std::string;
using std::pair;

void check_message(Client *cli, string s)
{   
    if ((s == "Start" || s[0] == 'G') && cli->game->state != State::InGame){
        cli->game->state = State::InGame;
        //cli->SEND("OKAY");
    } else {
        cli->game->msgFromClient = s;
    }
}

void ClientSonar(Client *cli, bool *online)
{
    while (*online){
        string msg = "x";
        msg = cli->RECEIVE();

        if (msg == "")
            continue;
        msg = cli->b.Decode(msg);
        if (msg == "ERROR"){
            cout << "Error: cannot connect to server" << endl;
            cli->TERMINATE_CLIENT = true;
            exit(-1);
        }

        cout << "===============" << endl;
        cout << msg << endl;
        cout << "===============" << endl;
        check_message(cli, msg);

    }
    cout << "Sonar Terminating!" << endl;
    return;
}

