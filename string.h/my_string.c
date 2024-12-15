#include "my_string.h"
#include <stdio.h>
#include <stddef.h>
#include "my_string.h"


int __strlen(const char *source)
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

int __strcpy(char *dest, const char *source)
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


int __strncpy(char *dest, const char *source, size_t max_size)
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


int __strcmp(const char *str1, const char *str2)
{
    /* check if func arguments are not null */
    if(str1 == NULL || str2 == NULL)
    {
        return -1; /* return -1 to indicate error */
    }
    
    unsigned int str1_len = __strlen(str1);
    unsigned int str2_len = __strlen(str2);
    /* check if str1 and str2 are equal in size */
    if(str1_len != str2_len)
    {
        return 1; /* return 1 to indicate strings are not equal */
    }

    unsigned int i;
    /* iterate through each character */
    for(i = 0; i < str1_len; i++)
    {
        /* compare characters of str1 and str2 */
        if(str1[i] != str2[i])
        {
            return 1;
        }
    }
    return 0;  /* return 0 to indicate strings are equal */
}


int __strncmp(const char *str1, const char *str2, size_t n)
{
    /* check for NULL */
    if(str1 == NULL || str2 == NULL)
    {
        return -1; /* return -1 if either str1 or str2 is NULL */
    }
    unsigned int i = 0;
    /* iterate through str1 and str2 until i >= n */
    for(i = 0; i < n; i++)
    {
        /* check if both str1 and str2 characters are null termiantors */
        if(str1[i] == '\0' && str2[i] == '\0')
        {
            return 0; 
        }
        /* check if either str1 or str2 character is null terminator */
        if(str1[i] == '\0' || str2[i] == '\0')
        {
            return 1; /* return 1 if str1 and str2 are not equal */
        }
        if(str1[i] != str2[i])
        {
            return 1; /* return 1 if str1 and str2 are not equal */
        }
    }
    return 0; /* return 0 if both str1 and str2 are equal */
}

int __strcat(char *dest, const char *source)
{ 
    /* validate function arguments */
    if(dest == NULL || source == NULL)
    {
        return -1; /* return 0 if destination string or source strings is NULL */
    }
    /* the last position in the destination string */
    unsigned int dest_pos = __strlen(dest); 
    /* source string iterator */
    unsigned int src_pos = 0;
    /* current char */
    char current_char = source[src_pos];
    while(current_char != '\0')
    {
        dest[dest_pos] = current_char; 
        dest_pos++;
        src_pos++;
        current_char = source[src_pos];
    }
    /* terminate the string */
    dest[dest_pos] = '\0';
    return 0; /* code 0 indicates successful function completion */
}

// manage pointer arithmetic instead of using iterators in future versions 