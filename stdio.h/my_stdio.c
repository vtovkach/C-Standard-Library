#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

// % format specifier 

// d  integer 
// f  float 
// c  char 
// s  string 
// x  hex (In Progress) 
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

static void print_float(float num)
{
    char buf[2];
    int int_part;
    int count = 0;
    while(num > 0 && count++ < 6)
    {
        num *= 10;
        int_part = (int)num;
        buf[0] = int_part + '0';
        write(STDOUT_FILENO, buf, 1);
        num = num - int_part;
    }
}

static void print_string(const char *src)
{
    if(!src)
    {   
        return;
    }
    while(*src != '\0')
    {
        write(STDOUT_FILENO, src, 1);
        src++;
    }
}

void my_printf(char const *src, ...)
{
    va_list ap;
    va_start(ap, src);

    while(*src != '\0')
    {
        if(*(src) == '%')
        {
            switch(*(++src))
            {
                case 'd': 
                    int number = va_arg(ap, int);
                    if(number < 0)
                    {
                        write(STDOUT_FILENO, "-", 1);
                        print_integer(number * -1);
                    }
                    else
                    {
                        print_integer(number);
                    }
                    break;
                case 'f':
                    double f_number = va_arg(ap, double);
                    if(f_number < 0)
                    {
                        f_number *= -1;
                        write(STDOUT_FILENO, "-", 1);
                        print_integer(f_number);
                        write(STDOUT_FILENO, ".", 1);
                        print_float(f_number - (int)f_number);
                    }
                    else 
                    {
                        print_integer(f_number);
                        write(STDOUT_FILENO, ".", 1);
                        print_float(f_number - (int)f_number);
                    }
                    break;
                case 'c':
                    int character = va_arg(ap, int);
                    char chara = character;
                    write(STDOUT_FILENO, &chara, 1);
                    break;
                case 's':
                    char *str = va_arg(ap, char *);
                    print_string(str);
                    break;
                default:
                    write(STDERR_FILENO, "\n!!!Error Code -1.", strlen("\n!!!Error Code -1."));
                    exit(-1);
                    break;
            }
        }   
        else
        {
            write(STDOUT_FILENO, src, 1);
        }
        src++;
    }
    va_end(ap);
}
