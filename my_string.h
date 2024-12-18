#define MY_STRING_H
#ifdef MY_STRING_H

#include <stddef.h>


int __strlen(const char *source);

int __strcpy(char *dest, const char *source);

int __strncpy(char *dest, const char *source, size_t max_size);

int __strcmp(const char *str1, const char *str2);

int __strncmp(const char *str1, const char *str2, size_t n); 

int __strcat(char *dest, const char *source);                  

int __strncat(char *dest, const char *source, size_t n);     

void __memset(void *ptr, int value, size_t n);

#endif 