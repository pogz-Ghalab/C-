/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** client
*/

#include "../include/client.hpp"
#include "../include/thread.hpp"

using std::cout;
using std::endl;

void Client::SEND(string message)
{
    sendto(socket_fd, message.c_str(), strlen(message.c_str()), 0,
        (sockaddr *)serverAddr->getAddress(), sizeof(*serverAddr->getAddress()));

    cout << "Message sent -> " << message << endl;
}

string Client::RECEIVE(void)
{
    char buf[2048];
    socklen_t len;

    int recvlen = recvfrom(socket_fd, buf, 2048, 0, (sockaddr *)serverAddr->getAddress(), &len); // wait; code blocking segment

    buf[recvlen] = '\0';
    
    if (strlen(buf) == 0){
        std::cout << "BUFF is " << buf << std::endl;
        std::cout << "Size of buff is zero" << std::endl;
        std::string s = "";
        return s;
    }
    string message (buf);
    
    return message;
}

Client::Client(char *serverIP)
{
    this->addr = new Address();
    
    if ((this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        std::cout << "\n\t Socket creation failed...\n\t Exiting..." << '\n';
        exit(0);
    }
    this->addr->getAddress()->sin_family = AF_INET;
    this->addr->getAddress()->sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(this->socket_fd,
            (sockaddr *)this->addr->getAddress(),
            sizeof(*this->addr->getAddress())) < 0){
        cout << "\n\t Bind failed...\n\t Exiting..." << endl;
        exit(0);
    }
    cout << "Client is Online!" << endl;
    this->serverAddr = new Address();
    this->serverAddr->getAddress()->sin_family = AF_INET;
    this->serverAddr->getAddress()->sin_port = htons(8080);
    if (inet_aton(serverIP, &this->serverAddr->getAddress()->sin_addr) == 0)
    {
        cout << "\n\t inet_aton() failed...\n\t Exiting..." << endl;
        exit(0);
    }
}

void Client::Init_Threads()
{
    thread_list.push_back(new Thread(this, 1));
    thread_list.push_back(new Thread(this, 2));
}

void Client::Shutdown_Threads()
{
    for (int i = 0; i < thread_list.size(); i++){
        thread_list.at(i)->TerminateThread();
    }
}