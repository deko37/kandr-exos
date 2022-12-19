#include <stdio.h>

#define MAX_CHAR 1000

int lireligne(char ligne[], int limite);

int main()
{
	char ligne[MAX_CHAR];

	while (lireligne(ligne, MAX_CHAR) > 0)
		printf("%s\n", ligne);
	return 0;
}

int lireligne(char ligne[], int limite)
{
	int i, c;
	i = 0;
	
	while (i < limite - 1)
	{
		c = getchar();
		if (c == EOF)
			break;
		if (c == '\n')
			break;
		ligne[i] = c;
		++i;
	}

	if (c == '\n')
	{
		ligne[i] = c;
		++i;
	}
	ligne[i] = '\0';
	return i;

}
