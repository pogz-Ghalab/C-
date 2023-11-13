/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** bookmaker
*/

#include <memory.h>
#include <malloc.h>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
using std::string;



char **bookmaker(char *str, char delim);

char **StringtoArray(string s)
{
    cout << s << endl;
    char *str = (char *)malloc(sizeof(char) * (s.size() + 1)); 
    strcpy(str, s.c_str());
    cout << str << endl;
    return bookmaker(bookmaker(str,'\n')[0], ',');
}

int count_words(char *str, char delim)
{
    int i = 0;
    int c = 0;

    while (str[i] != '\0'){
        if (str[i] == delim && str[i + 1] != delim && str[i + 1] != '\0')
            c++;
        i++;
    }
    return c + 1;
}

char **init_array(int x, int y)
{
    int i = 0;
    char **arr = (char **)malloc(sizeof(char *) * (y + 1));
    while (i < y){
        arr[i] = (char *)malloc(sizeof(char) * (x + 1));
        arr[i][x] = '\0';
        i++;
    }
    arr[i] = NULL;
    return arr;
}

char **bookmaker(char *str, char delim)
{
    int n = count_words(str, delim);
    char **book = init_array(strlen(str) , n);
    int i = 0, j = 0, s = 0;
    while (j < n){
        while (str[s] != delim && str[s] != '\0'){
            book[j][i] = str[s];
            i++;
            s++;
        }
        book[j][i] = '\0';
        i = 0;
        while (str[s] == delim){
            s++;
        }
        j++;
    }
    book[j] = NULL;
    free(str);
    return book;
}   