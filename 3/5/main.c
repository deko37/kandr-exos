#include <stdio.h>
#include <string.h>

void inverser(char s[]);
void itob(int n, char s[], int b);

int main()
{
	char s[4096];
	for (int i = 0; i < 0xFFFFFF; ++i)
	{
		itob(i, s, 16);
		printf("%d\n%s\n", i, s);
	}
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

void itob(int n, char s[], int b)
{
	int i, signe, limite_ajouteur, chrng_niveau;

	i = signe = limite_ajouteur = 0;

	switch (b)
	{
		case 16:
			chrng_niveau = 0x10;
			break;
		case 2:
			chrng_niveau = 0b10;
			break;
		case 8:
			chrng_niveau = 010;
			break;
		default:
			chrng_niveau = 10;
			break;
	}

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
		if (b != 16)
			s[i++] = n % chrng_niveau + limite_ajouteur + '0';
		else
		{
			if (n % chrng_niveau + limite_ajouteur >= 10)
				s[i++] = n % chrng_niveau + limite_ajouteur + '7';
			else
				s[i++] = n % chrng_niveau + limite_ajouteur + '0';
		}
	} while ((n /= chrng_niveau) > 0 && !(limite_ajouteur = 0));
	if (signe < 0)
		s[i++]= '-';
	s[i] = '\0';
	inverser(s);
}
