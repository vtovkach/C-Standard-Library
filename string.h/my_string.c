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
        return 1; /* return 0 if destination string or source strings is NULL */
    }
    dest+= __strlen(dest);
    while(*source != '\0')
    {  
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return 0;   /* code 0 indicates successful function completion */
}

int __strncat(char *dest, const char *source, size_t n)
{   
    /* validate function arguments */
    if(dest == NULL || source ==  NULL) { return 1; }
    if(n == 0) { return 2; }
    dest+= __strlen(dest);
    unsigned int i = 0; 
    while(i < n && *source != '\0')
    {
        *dest = *source;
        dest++;
        source++;
        i++;
    }
    *dest = '\0';
    return 0;   /* code 0 indicates successful function completion */
}

void __memset(void *ptr, int value, size_t n)
{ 
    unsigned char *bytePtr = (unsigned char *)ptr; 
    unsigned char byteValue = (unsigned char)value; 
    while(n--)
    {
        *bytePtr = byteValue;
        bytePtr++;
    }
}

char *__strchr(const char *str, int c)
{
    while(*str != '\0')
    {
        if(*str == (char)c)
        {
            return (char *) str;
        }
        str++;
    }
    return NULL;
}

char *__strrchr(const char *str, int c)
{
    char *character = NULL; 
    while(*str != '\0')
    {
        if(*str == (char)c)
        {
            character = (char *)str;
        }
        str++;
    }
    return character;
}

char *__strstr(const char *source, const char *substr)
{
    if(*substr == '\0') return (char *)source;
    char *substring_ptr;
    char *copy_substr = (char *)substr;
    while(*source != '\0')
    {
        if(substring_ptr != NULL && *copy_substr == '\0')
        {
            break; 
        }
        else if(*source == *copy_substr)
        {   
            if(substring_ptr == NULL)
            {
                substring_ptr= (char *)source;
            }
            source++;
            copy_substr++;
        }
        else
        {
            copy_substr = (char *)substr;
            if(substring_ptr == NULL)
            {
                source++;
            }
            substring_ptr = NULL;
        }
    }
    if(*copy_substr == '\0')
    {
        return substring_ptr;
    }
    return NULL;
}