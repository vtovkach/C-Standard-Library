#include "my_string.h"
#include <stdio.h>


size_t my_strlen(char *source)
{
    /* Check for null pointer */
    if(source == NULL)
    {
        return 0; /* return 0 indicating NULL string */
    }

    int len = 0;
    int i = 0;
    char current_char = 0;

    /* iterate through the strin until null terminator */
    while((current_char = *(source+i)) != '\0')
    {
        len++;
        i++;
    }
    return len;  /* return the length of the string */
}