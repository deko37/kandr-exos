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
	
	for (i = 0; i < limite - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		ligne[i] = c;

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
	int i;
	if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x'))
		i = 2;
	else
		i = 0;

	for (; i < MAX_CHAR && isxdigit((c = s[i])); ++i)
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
