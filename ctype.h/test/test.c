#include <stdio.h>
#include "my_ctype.h"

int main()
{

    char c1 = '^';
    char c2 = 'A';
    char c3 = 'a';
    char c4 = '9';
    char c5 = '*';

    if(__isalnum(c5) == 1)
    {
        printf("It is indeed!\n");
    } 
    else
    {
        printf("It is not indeed\n");
    }

    return 0;
}