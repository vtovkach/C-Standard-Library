#include <stdio.h> 
#include "my_string.h"

int main()
{

    char str1[] = "Hello\n"; 
    char str2[] = "Hello World\n";
    char str5[] = "i Dont know you\n";

    char str3[100];

    
    __strcpy(str3, str2);

    __strncat(str3, str1, 20);

    __strncat(str3, str5, 20);
    printf("%s", str3);

    __memset(str3, 0, 100);

    printf("%d\n", str3);
    
    return 0;
}
