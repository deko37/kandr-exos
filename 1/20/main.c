#include <stdio.h>

#define MAX_CHAR 1000
#define COLONNES 8

int lireligne(char ligne[], int limite);
int tab_vers_esp(int i, int colonnes);

int main()
{
        char ligne[MAX_CHAR];
        int longueur;        
        while ((longueur = lireligne(ligne, MAX_CHAR)) > 0)
        {
                int i_tab = 0; // Index from last tab
                for (int i = 0; i < longueur; ++i)
                {
                        if (ligne[i] == '\t')
                        {
                                for (int x = 0; x < tab_vers_esp(i - i_tab, COLONNES); ++x) // i - i_tab allows to process it like it was the first tab
                                        putchar(' ');
                                i_tab = i + 1; // We have to + 1 because i is not the length, just the index
                        }
                        else
                                putchar(ligne[i]);
                }
                printf("||||%d\n", longueur);
        }

        return 0;
}

int lireligne(char ligne[], int limite)
{
        int c;
        int i;
        for (i = 0; i < (limite - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
                ligne[i] = c;
        if (ligne[i] == '\n')
        {
                ligne[i] = '\n';
                ++i;
        }
        ligne[i] = '\0';
        return i;
}

int tab_vers_esp(int i, int colonnes)
{
        return colonnes - i % colonnes;
}
