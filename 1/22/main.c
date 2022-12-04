#include <stdio.h>

#define MAX_CHAR 1000
#define MAX_LIGNE 50

int lireligne(char ligne[], int limite);

int main()
{
	char ligne[MAX_CHAR];
	int longueur;

	while ((longueur = lireligne(ligne, MAX_CHAR)) > 0)
	{
		for (int i = 0, j = 0, stase = 0; i < longueur; ++i, ++j)
		{
			if ((j >= MAX_LIGNE) || ((ligne[i] == ' ' || ligne[i] == '\t') 
						&& j >= (MAX_LIGNE - 10)))
			{
				j = -1;
				putchar('\n');
				stase = 1;
			}
			if (stase == 1 && ligne[i] != ' ' && ligne[i] != '\t')
				stase = 0;
			if (stase == 0)
				putchar(ligne[i]);
			else
				--j;
		}
	}
	return 0;
}

int lireligne(char ligne[], int limite)
{
	int i, c;
	
	for (i = 0; i < (limite - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
		ligne[i] = c;
	if (c == '\n')
	{
		ligne[i] = c;
		++i;
	}
	ligne[i] = '\0';
	return i;

}
