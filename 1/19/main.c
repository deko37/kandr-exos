#include <stdio.h>

#define MAX_CHAR 1000

int lireligne(char ligne[], int limite);
void inverser(char ligne[]);
int copie(char de[], char vers[]);

int main()
{
	char ligne[MAX_CHAR];
	int longueur;

	while ((longueur = lireligne(ligne, MAX_CHAR)) > 0)
	{
		inverser(ligne);
		printf("%s\n",ligne);
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

void inverser(char ligne[])
{
	int i, j;
	char cp_ligne[MAX_CHAR];
	
	j = 0;
	i = copie(ligne, cp_ligne) - 1;

	for (; i >= 0; --i, ++j)
		ligne[j] = cp_ligne[i];
}

int copie(char de[], char vers[])
{
	int i = 0;

	while ((vers[i] = de[i]) != '\0')
		++i;
	return i;
}
