/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

//#include "../include/client.hpp"
//#include "../../main.hpp"
#include "../../game/include/Game.hpp"

int MainGame(Client *client);


int main(int argc, char **argv)
{
    if (argc != 3){
        cout << "Enter your ip and username when you execute" << endl;
        cout << "Press e to exit, Press r to make client ready in lobby" << endl;
        return -1;
    }
    char *serverIP = argv[1];
    Client cli(serverIP);
    *cli.GetUsername() = argv[2];
    cli.SEND(cli.b.Encode(*cli.GetUsername()));
    cli.game = new Game;
    cli.game->client = &cli;
    
    cli.Init_Threads();

    MainGame(&cli); 
    
}
