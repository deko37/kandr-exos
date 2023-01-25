#include <stdio.h>
#include <string.h>
#include <limits.h>

void inverser(char s[]);
void itoa(int n, char s[]);

int main()
{
	char s[4096];
	itoa(INT_MIN, s);
	printf("%d\n%s\n", INT_MIN, s);
	return 0;
}

void inverser(char s[])
{
	int i, c, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int i, signe, limite_ajouteur;

	i = signe = limite_ajouteur = 0;

	if ((signe = n) < 0)
		n = -n;
	if (n < 0)
	{
		n += 1;
		n = -n;
		limite_ajouteur = 1;
	}

	do
	{
		s[i++] = n % 10 + limite_ajouteur + '0';
	} while ((n /= 10) > 0 && !(limite_ajouteur = 0));
	if (signe < 0)
		s[i++]= '-';
	s[i] = '\0';
	inverser(s);
}