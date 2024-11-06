#include "my_string.h"
#include <stdio.h>
#include <stddef.h>

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

int my_strcpy(char *dest, const char *source)
{
    if(dest == NULL || source == NULL)
    {
        return -1; /* return -1 to indicate unsuccessful operation */
    }

    char current_char; 
    int i = 0;

    /* iterate through source string */
    while((current_char = *(source+i)) != '\0')
    {
        *(dest+i) = current_char; /* copy character from the source to destination string */
        i++; 
    }

    *(dest+i) = '\0'; /* add null terminator to the end */

    return 0; /* return 0 if everything is fine */
}


int _my_strcpy(char *dest, const char *source, size_t max_size)
{
    if(dest == NULL || source == NULL)
    {
        return -1;  /* return -1 to indicate unsuccessful operation */
    }

    int i = 0;
    char current_char; 

    /* iterate through source string */
    while((current_char = *(source+i)) != '\0' && i < max_size-1)
    {
        *(dest+i) = current_char;  /* copy character from the source to destination string */
        i++;
    }

    *(dest+i) = '\0';  /* add null terminator to the end */

    return 0;  /* return 0 if everything is fine */
}
