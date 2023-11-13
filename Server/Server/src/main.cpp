/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>

#include "../include/server.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    Server srv;

    srv.Init_Threads();
    srv.Init_ECS();
    
    cout << "Server is waiting for clients!" << endl;
    Main_Loop(&srv);
}






//VERY IMPORTANT FOR THE NETWORK PATH
//MAKE COMMUNICATION BINARY
//SPECIAL CLASS WITH CODE AND DECODE TO SERIALIZE AND DESERIALIZE THE BINARY WITH OVERLOADING THE FUNCITONS

// windows and linux
// vcs workflow
// c++ lintern linter

//add releases and everything in the github
//fix the readme
//server hosted online
//cmake cpack?
//erp diagram server client
//doc of proc if you need to rrecreate a client rfc document
//several levels with json
//random level generated
//several types of enemies
//1 snake style enemy
//1 huge enemy structure with turrets and health
//3 bosses with different patterns
//weapon charging and then shoot
//powerup that can block or shoot. something that shows like the mini shooter at b of isaac
//like a turret or something like that
//different weapons mandatory a laser types (continuous damage)
//power ups like extra speed, extra health

//asset editor for ships levels etc.

//player ai kind of random and changes y based on the level of enemies
//scoring system and highscore
//animated gui like menu or interface
//record screen and replay.


// very good is 16 points
// good is 12 points
// minimum of 4 software engineering

//good is 4 technical 
//very good is 5 tech


// 1 very good 
// 7 technical

// 1 good 
// 9 technical