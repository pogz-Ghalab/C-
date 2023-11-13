#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>





int main()
{
    char hello[] = "Hello World!";
    char *dup = my_strdup(hello);

    printf("|%s|\n", dup);
}