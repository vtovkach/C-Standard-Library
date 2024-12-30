#include <unistd.h>
#include <stdarg.h>

#include "my_stdio.h"


void my_printf(char const *string, ...)
{
    va_list arg;
    int args = 0;
    int i = 0;
    char current_char; 
    
    current_char = string[i];
    while(current_char != '\0')
    {
        if(current_char == '%')
        {
            args++;
        }
        i++;
    }

    
    /*
    i = 0;
    current_char = string[i];
    while(*string != '\0')
    {
        
    }
    */
    
}


/*

    %d integer
    %f double 
    ...

*/