#include <stdio.h>
#include "my_string_func.h"

int main(void)
{
    char s1[] = "1234";
    char s2[] = "xxxx";
    mstrncpy(s1, s2, 3);
    printf("%s\n", s2);
    return 0;
}