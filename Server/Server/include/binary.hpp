/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** binary
*/

#pragma once

#include <iostream>
#include <bitset>

using std::string;
using std::cout;
using std::endl;

class Binary
{
    public:
        char strToChar(const char *str)
        {
            char parsed = 0;
            for (int i = 0; i < 8; i++){
                if (str[i] == '1'){
                    parsed |= 1 << (7 - i);
                }
            }
            return parsed;
        }

        string Encode(string message)
        {
            return message;
            string binaryString = "";
            for (char &_char : message){
                binaryString += std::bitset<8>(_char).to_string();
            }
            return binaryString;
        }

        string Decode(string message)
        {
            return message;
            string plaintext = "";
            string temptext;

            int i = 0;
            while (i < message.size()){
                for (int j = 0; j < 8; j++){
                    temptext += message[i + j];
                }
                char const *s = &temptext[0];
                plaintext = plaintext + strToChar(s);
                temptext = "";
                i += 8;
            }
            return plaintext;
        }
};