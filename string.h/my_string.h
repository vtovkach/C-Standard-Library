#define MY_STRING_H
#ifdef MY_STRING_H

#include <stddef.h>

int __strlen(const char *source);

int __strcpy(char *dest, const char *source);

int __strncpy(char *dest, const char *source, size_t max_size);

int __strcmp(const char *str1, const char *str2);


#endif 