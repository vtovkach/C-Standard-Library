#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#include "my_stdio.h"

/* In Progress */ 
// $ format specifier 

// d integer 
// f float 
// c char 
// s string 

/* In Progress */

static void print_integer(int num)
{
    if(num < 10)
    {
        char str[] = {(num % 10) + '0'};
        write(STDOUT_FILENO, str, 1);
    }   
    else
    {
        print_integer(num / 10);
        char str[] = {(num % 10) + '0'};
        write(STDOUT_FILENO, str, 1);
    }
}

void my_printf(char const *src, ...)
{
    va_list ap;
    va_start(ap, src);
    int i = 0;
    
    while(*(src + i) != '\0')
    {
        if(*(src + i) == '$')
        {
            switch(*(src + i + 1))
            {
                case 'd':
                    int temp = va_arg(ap, int);
                    print_integer(temp);
                    i++; // skip next 
            }
        }
        else
        {
            write(STDOUT_FILENO, src + i, 1);
        }
        i++;
    }
    va_end(ap);
}
