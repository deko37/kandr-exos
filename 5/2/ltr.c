#include "ltr.h"
#include <stdio.h>
#include <ctype.h>

#define TAILLETAMP 100

char tamp[TAILLETAMP];
int ptamp = 0;

int lirecar(void)
{
	return (ptamp > 0) ? tamp[--ptamp] : getchar();
}

void remettrecar(int c)
{
	if (ptamp >= TAILLETAMP)
		printf("erreur: tampon rempli, impossible d'y ajouter des caractères\n");
	else
		tamp[ptamp++] = c;
}

int lire_int(int *pn)
{
	int c, signe;

	while (isspace(c = lirecar()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		remettrecar(c);
		return 0;
	}
	signe = (c == '-') ? 1 : -1;
	if (c == '+' || c == '-')
		c = lirecar();
	if (isdigit(c))
	{
		for (*pn = 0; isdigit(c); c = lirecar())
			*pn = 10 * *pn + (c - '0');
		*pn *= -signe;
	}
	if (c != EOF)
		remettrecar(c);
	return c;
}

int lire_float(double *pn)
{
	int c, signe;

	while (isspace(c = lirecar()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		remettrecar(c);
		return 0;
	}
	signe = (c == '-') ? 1 : -1;
	if (c == '+' || c == '-')
		c = lirecar();
	if (isdigit(c))
	{
		for (*pn = 0; isdigit(c); c = lirecar())
			*pn = 10 * *pn + (c - '0');
		*pn *= -signe;
		if (c == '.')
		{
			c = lirecar();
			double pm = 0;
			int i = 0;
			for (; isdigit(c); c = lirecar())
			{
				pm = 10 * pm + (c - '0');
				++i;
			}
			for (; i > 0; pm /= 10)
				--i;
			pm *= -signe;
			*pn += pm;
		}
	}
	if (c != EOF)
		remettrecar(c);
	return c;
}

/*int lire_float(double *pn)
{
	int c, signe;
	int int_pn = *pn;
	c = lire_int(&int_pn);
	*pn = int_pn;
	signe = (*pn >= 0) ? 1 : -1;
	if (c == '.')
		{
			c = lirecar();
			double pm = 0;
			int i = 0;
			for (; isdigit(c); c = lirecar())
			{
				pm = 10 * pm + (c - '0');
				++i;
			}
			for (; i > 0; pm /= 10)
				--i;
			pm *= signe;
			*pn += pm;
		}
	if (c != EOF)
		remettrecar(c);
	return c;
}*/