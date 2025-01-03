#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#include "my_stdio.h"

static void covertIntToStr(int value, char *buffer)
{
    const int BASE_INTEGER_ASCII = 48;
    int quotient;
    int remainder;
    char tempChar;

    while(value > 0)
    {
        quotient = value / 10;
        remainder = value % 10;
        for(int i = 0; i < 10; i++)
        {
            if(remainder == i)
            {
                tempChar = BASE_INTEGER_ASCII + i;
            }
        }
        *buffer = tempChar;
        buffer++;
        value = quotient;
    }

    
}

void my_printf(char const *string, ...)
{

    char str[100];

    covertIntToStr(1233232, str);

    
    printf("%s\n", str);



    /*
    va_list args;

    va_start(args, string);
    while(*(string++) != '\0')
    {
        if(*string == '%')
        {
            string++;
            if(*string == 'd')
            {
                
            }
        }
    }
    */
}



/*

    %d integer
    %f double 
    ...

*/