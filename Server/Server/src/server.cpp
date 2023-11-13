/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** server
*/

#include "../include/server.hpp"
#include "../include/thread.hpp"

using std::cout;
using std::endl;
using std::string;
using std::pair;

void Server::SendToAllClients(string msg)
{
    if (msg == "") return;
    for (int i = 0; i < connected_clients.size(); i++){
        SEND(b.Encode(msg), connected_clients.at(i)->getAddress()->getAddress()); 
    }
}

void Server::ClearOutput_Queue()
{
    m_output.lock();
    OUTPUT_QUEUE.clear();
    m_output.unlock();
}
void Server::ClearInput_Queue()
{
    m_input.lock();
    INPUT_QUEUE.clear();
    m_input.unlock();
}
void Server::PushToOutput_Queue(string s){
    m_output.lock();
        if (s != ""){
            OUTPUT_QUEUE.push_back(s);
        }
    m_output.unlock();
}
void Server::PushToInput_Queue(vector<string> incoming_msg)
{
    m_input.lock();
        INPUT_QUEUE.push_back(incoming_msg);
    m_input.unlock();
}
string Server::GetFirstFromOutput_Queue(void)
{
    m_output.lock();
        if (OUTPUT_QUEUE.size() > 0){
            string s = *OUTPUT_QUEUE.begin();
            OUTPUT_QUEUE.erase(OUTPUT_QUEUE.begin());
            m_output.unlock();
            return s;
        }
    m_output.unlock();
    return "";
}
vector<string> Server::GetFirstFromInput_Queue(void)
{
    m_input.lock();
        if (INPUT_QUEUE.size() > 0){
            vector<string> s = *INPUT_QUEUE.begin();
            INPUT_QUEUE.erase(INPUT_QUEUE.begin());
            m_input.unlock();
            return s;
        }
    m_input.unlock();
    return {};
}

string BoolToChar(bool b)
{
    if (b){
        return "r";
    } else {
        return "u";
    }
}

std::string Server::FetchLobbyData(void)
{
    string m = "";
    int i = 0;

    while (i < connected_clients.size()){
        m = m +  *connected_clients.at(i)->getUsername() + "," + BoolToChar(connected_clients.at(i)->lobby_ready);
        i++;
        m += ",";
    }
    return m;
}


Client *Server::FindSpecificClient(sockaddr_in *cliAddr)
{
    for (int i = 0; i != connected_clients.size(); i++){
        if (connected_clients.at(i)->getAddress()->getAddress()->sin_port == cliAddr->sin_port){
            return connected_clients.at(i);
        }
    }
    return NULL;
}

//IF ARGUMENT IS TRUE CLIENT WILL BE MADE READY
void Server::SetClientReadiness(sockaddr_in *cliAddr, bool ready)
{
    if (ready){
        FindSpecificClient(cliAddr)->lobby_ready = true;
    } else {
        FindSpecificClient(cliAddr)->lobby_ready = false;
    }
}

void Server::RemoveClient(sockaddr_in *cliaddr)
{
    if (connected_clients.size() == 0){
        return;
    }

    short cliport = ntohs(cliaddr->sin_port);

    for (int i = 0; i < connected_clients.size(); i++){
        short temp = ntohs(connected_clients.at(i)->getAddress()->getAddress()->sin_port);

        if (temp == cliport){
            connected_clients.erase(connected_clients.begin() + i);
        }
    }
    this->connectedNbr--;
}

void Server::AddClient(sockaddr_in *cliaddr, std::string username)
{
    connected_clients.push_back(new Client(cliaddr, username));
    connectedNbr++;
}

std::vector<Client *> *Server::GetClients()
{
    return &connected_clients;
}

void Server::SEND(string message, Client *cli)
{
    sendto(socket_fd, message.c_str(), message.size(), 0,
            (sockaddr *)cli->getAddress()->getAddress(), cli->getAddress()->getAddrLen());
}

void Server::SEND(string message, sockaddr_in *cliaddr)
{
    sendto(socket_fd, message.c_str(), message.size(), 0,
            (sockaddr *)cliaddr, sizeof(*cliaddr));
}
#include <cstring>

pair<sockaddr_in, string> Server::RECEIVE(void)
{
    char buff[2048];
    sockaddr_in temp;
    socklen_t addrlen = sizeof(temp);
    std::pair<sockaddr_in, string> ret;    
    
    int size = recvfrom(socket_fd, buff, 2048, 0, (sockaddr *)&temp, &addrlen);
    
    buff[size] = '\0';

    ret.first = temp;
    if (size < 1){
        ret.second = "";
    } else {
        ret.second = buff;
    }
    return ret;
}

#include <fcntl.h>
//FUNCTION USED TO MAKE A SOCKET BLOCKING OR NOT
bool SetSocketBlockingEnabled(int fd, bool blocking)
{
    if (fd < 0) return false;

    #ifdef _WIN32
        unsigned long mode = blocking ? 0 : 1;
        return (ioctlsocket(fd, FIONBIO, &mode) == 0) ? true : false;
    #else
        int flags = fcntl(fd, F_GETFL, 0);
        if (flags == -1) return false;
        flags = blocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK);
        return (fcntl(fd, F_SETFL, flags) == 0) ? true : false;
    #endif
}

Server::Server()
{
    this->addr = new Address();

    if ((this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        cout << "\n\t Socket creation failed...\n\t Exiting..." << '\n';
        exit(0);
    }

    this->addr->getAddress()->sin_family = AF_INET;
    this->addr->getAddress()->sin_addr.s_addr = htonl(INADDR_ANY);
    this->addr->getAddress()->sin_port = htons(8080);

    if ( bind(socket_fd, 
                (sockaddr *)this->addr->getAddress(),
                sizeof(*this->addr->getAddress()) )  == -1){
        cout << "\n\t Binding failed...\n\t Exiting..." << '\n';
        exit(0);
    }
    SetSocketBlockingEnabled(this->socket_fd, false);

    reg_ = new Registry;
    reg_->srv = this;

    cout << "Server is online in port " << ntohs(this->addr->getAddress()->sin_port) << ":\n";
}

void Server::Init_Threads()
{
    thread_list.push_back(new Thread(this, 1));
    thread_list.push_back(new Thread(this, 2));
}

void Server::Shutdown_Threads()
{
    for (int i = 0; i < thread_list.size(); i++){
        thread_list.at(i)->TerminateThread();
    }
}


/*

game loop()
{
    init playerss based on their number
    int background

    while (1){
        move_background
        move_enemies
        if (enemies hit){
            if (all enemies dead){
                create new enemies
            }
            decrement enemy life
        }
        if (player got hit){
            if (player died){
                remove player
                send exit to client
            }
            decrement player health
        }

        if player moved
            move
        if player shooted
            shoot

        send entities list to the client
    
    }
}

*/



