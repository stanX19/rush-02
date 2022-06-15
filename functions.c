#include "header.h"

char* substr(char* str, int start, int end)
{
	char* ret;
	int idx;

	if (start >= end)
		return 0;
	idx = 0;
	ret = malloc((sizeof(char) * (end - start + 2)));
	while (start < end)
		ret[idx++] = str[start++];
	ret[idx] = 0;
	return ret;
}

void *ft_memset(void*b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		((char*)(b))[i++] = c;
	return b;
}

int find(char*str, int start, int end, char target)
{
	while (start < end && str[start])
	{
		if (str[start++] == target)
			return start - 1;
	}
	return -1;
}

void * ft_memcpy(char *dst, const char *src, int n)
{
    int i;

	if (dst == src)
		return dst;
    i = 0;
    while (i < n)
    {
        ((char*)dst)[i] = ((char*)src)[i];
        i++;
    }
    return dst;
}

int ft_strlen(char* str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return i;
}