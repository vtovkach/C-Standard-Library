#include "my_ctype.h"

int __isalnum(const int c)
{
    if((c <= 0x39 && c>= 0x30)  ||  /* 0-9 */
       (c >= 0x41 && c <= 0x5A) ||  /* A-Z */
       (c >= 0x61 && c <= 0x7A))    /* a-z */
    {
        return 1;
    }
    return 0;
}

int __tolower(int c)
{
    if(c >= 0x41 && c <= 0x5A)
    {
        return c | 0x20;
    }
    return c;
}

int __toupper(const int c)
{
    if(c >= 0x61 && c <= 0x7A)
    {
        return c & 0xDF;
    }
    return c; 
}