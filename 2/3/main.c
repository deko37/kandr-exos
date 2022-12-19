#include <stdio.h>
#include <ctype.h>

#define MAX_CHAR 1000

int lireligne(char ligne[], int limite);
int htoi(char s[]);

int main()
{
	char ligne[MAX_CHAR];

	while (lireligne(ligne, MAX_CHAR) > 0)
		printf("%d\n", htoi(ligne));

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

int htoi(char s[])
{
	int hex_nbr = 0;
	int c = 0;

	for (int i = 2; i < MAX_CHAR && isxdigit((c = s[i])); ++i)
	{
		if (isdigit(c))
			hex_nbr = 0x10 * hex_nbr + (c - '0');
		else
		{
			c = toupper(c);
			hex_nbr = 0x10 * hex_nbr + (c - 'A' + 10);
		}
	}
	
	return hex_nbr;
}
