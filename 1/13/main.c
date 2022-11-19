#include <stdio.h>

#define LEN 3

main()
{
    int c;
    int len_mots[LEN];
    int plus_grand_len = 0;
    
    for (int i = 0; i < LEN; ++i)
    {
        int len_mot = 0;
        while ((c = getchar()) != ' ' && c != '\n' && c != '\t' && c != EOF)
        {
            if (c != ' ' && c != '\n' && c != '\t')
                ++len_mot;
        }
        len_mots[i] = len_mot;
        if (plus_grand_len < len_mot)
            plus_grand_len = len_mot;
    }
    for (int i = plus_grand_len; i > 0; --i)
    {
        printf("%4d| ", i);
        for (int j = 0; j < LEN; ++j)
        {
            if (i <= len_mots[j])
                printf(" @ ");
            else
                printf("   ");
        }
        putchar('\n');
    }
}