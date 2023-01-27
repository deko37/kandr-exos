#include <stdio.h>
#include <assert.h>

int finchaine(char*, char*);

int main(void)
{
    assert(finchaine("aabc", "abc") == 1);
    assert(finchaine("fsqdfhqsufhqdofuhq", "fuhq") == 1);
    assert(finchaine("azertyuiop", "abc") == 0);
    assert(finchaine("qdcljqsdclqsjdcqqsdfa", "976967") == 0);
    return 0;
}

int finchaine(char *s, char *t)
{
    int len_t = 0;
    for (; *s != '\0'; s++) // va vers la fin de la chaîne de caractères (pour s)
        ;
    for (; *t != '\0'; t++) // va vers la fin de la chaîne de caractères (pour t)
        len_t++;
    printf("\n");
    while (len_t) // tant que s == t, on continue
    {
        s--;
        t--;
        len_t--;
    }
    if (*s != *t)
        return 0;
    return 1;
}