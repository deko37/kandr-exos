#include <stdio.h>

#define MAX_CHAR 1000

int lireligne(char ligne[], int limite);

int main()
{
	char ligne[MAX_CHAR];
	int longueur;

	while ((longueur = lireligne(ligne, MAX_CHAR)) > 0)
		printf("%d\t|%s\n", longueur, ligne);
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
