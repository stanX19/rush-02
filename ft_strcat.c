#include "header.h"
#include <stdio.h>
char* ft_strcat(char* dest, char* src) {
    int     i;

    if (!src || !dest)
        return dest;
    i = -1;
    while (dest[++i] != 0)
        ;
    while (*src != 0)
    {
        dest[i] = *src;
        src++;
        i++;
    }
    dest[i] = 0;
    return (dest);
}