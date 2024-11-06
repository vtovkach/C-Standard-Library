#include <stdio.h> 
#include "my_string.h"

int main()
{
    char string[] = "Hello World";
    char string2[8];

    int status = __my_strcpy(string2, string, 12);

    printf("%s, %d", string2, status);

    return 0;
}