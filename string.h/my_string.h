#define MY_STRING_H
#ifdef MY_STRING_H

#include <stddef.h>

size_t my_strlen(char str[]);

int my_strcpy(char *dest, const char *source);

int _my_strcpy(char *dest, const char *source, size_t max_size);


#endif