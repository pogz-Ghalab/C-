/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** tools
*/

#include "../include/server.hpp"

std::vector<std::string> split_data(std::string str, const char* delim)
{
    std::vector<std::string> out;
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr) {
        out.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
    return (out);
}

int check_size(std::vector<std::string> res)
{
    int x = 0;
    while (x < res.size()) { x++; }
    return (x);
}