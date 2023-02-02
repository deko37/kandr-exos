#include "my_string_func.h"

void mstrncpy(char *t, char *s, int n)
{
    if (n >= 1)
        t += (n - 1);
    while (*t != '\0')
        *s++ = *t++;
    *s++ = '\0';
}

int mstrncmp(char *s, char *t, int n)
{
    if (n >= 1)
        s += (n - 1);
    while (*s == *t)
    {
        s++;
        t++;
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

void mstrncat(char *s, char *t, int n)
{

}