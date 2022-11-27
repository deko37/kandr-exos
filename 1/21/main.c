#include <stdio.h>

#define MAX_CHAR 1000
#define COLONNES 8

int lireligne(char ligne[], int limite);
int tab_vers_esp(int i, int colonnes);
void esp_vers_tab(int tab_esp_val[], int i, int nbr_esp, int i_fin_esp, int colonnes);

int main()
{
        char ligne[MAX_CHAR];
        int longueur;
	while ((longueur = lireligne(ligne, MAX_CHAR)) > 0)
        {
                int i_tab = 0; // Index from last tab
                for (int i = 0; i < longueur; ++i)
                {
                        if (ligne[i] == ' ')
                        {
				int j = 0, nbr_esp = j, nbr_tab = j;
				while (ligne[i+j] == ' ')
				{
					++nbr_esp;
					++j;
				}
				while (nbr_esp >= tab_vers_esp(i + j - 1, COLONNES))
				{
					nbr_esp -= COLONNES;
					++nbr_tab;
				}
				for (int z = 0; z < nbr_tab; ++z)
					putchar('\t');
				for (int z = 0; z < nbr_esp; ++z)
					putchar(' ');
				i += j - 1;
			}
                        else
                                putchar(ligne[i]);
                }
		putchar('\n');
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
