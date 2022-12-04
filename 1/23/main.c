#include <stdio.h>

#define MAX_CHAR 1000

int liretexte(char texte[], int limite);

int main()
{
	char texte[MAX_CHAR];
	int longueur;

	while ((longueur = liretexte(texte, MAX_CHAR)) > 0)
		for (int i = 0; i < longueur; ++i)
		{
			int c = texte[i];
			if (c == '/')
			{
				if (texte[i + 1] == '/')
				{
					while (texte[i] != '\n')
						++i;
				}
				if (texte[i + 1] == '*')
				{
					while (texte[i] != '*' || texte[i + 1] != '/')
						++i;
					i += 2;
				}
			}
			putchar(texte[i]);
		}
	return 0;
}

int liretexte(char texte[], int limite)
{
	int i, c;
	
	for (i = 0; i < (limite - 1) && (c = getchar()) != EOF && c != '#'; ++i)
		texte[i] = c;
	if (c == '\n')
	{
		texte[i] = c;
		++i;
	}
	texte[i] = '\0';
	return i;

}
