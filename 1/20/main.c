#include <stdio.h>

#define COLONNES 4
#define MAX_CHAR 1000

void vider(char ligne[], int limite);
int lireligne(char ligne[], int limite);

int main()
{
    char ligne[MAX_CHAR];
    vider(ligne, MAX_CHAR);
    while (lireligne(ligne, MAX_CHAR) > 0)
    {
        for (int i = 0; ligne[i] != '\0'; ++i)
        {
            if (ligne[i] == '\t')
            {
                for (int j = 0; j < COLONNES; ++j)
                    putchar(' ');
            }
            else
                putchar(ligne[i]);
        }
        vider(ligne, MAX_CHAR);
    }
    return 0;
}


void vider(char ligne[], int limite)
{
    for (int i = 0; i < limite; ++i)
        ligne[i] = 0;
}

int lireligne(char ligne[], int limite)
{
    int i, c;

    for (i = 0; i < (limite - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        ligne[i] = c;
    }
    if (c == '\n')
    {
            ligne[i] = c;
            ++i;
    }
    ligne[i] = '\0';
    return i;

}