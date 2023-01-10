#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100

#define NOMBRE '0'

int lire_op(char []);
void empiler(double);
double depiler(void);

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = lire_op(s)) != EOF)
	{
		switch (type)
		{
			case NOMBRE:
				empiler(atof(s));
				break;
			case '+':
				empiler(depiler() + depiler());
				break;
			case '*':
				empiler(depiler() * depiler());
				break;
			case '-':
				op2 = depiler();
				empiler(depiler() - op2);
				break;
			case '/':
				op2 = depiler();
				if (op2 != 0.0)
					empiler(depiler() / op2);
				else
					printf("erreur: division par zéro impossible\n");
				break;
			case '%':
				op2 = depiler();
				if (op2 != 0)
					empiler((long) depiler() % (long) op2);
				else
					printf("erreur: division par zéro impossible\n");
				break;
			case '\n':
				printf("\t%.8g\n", depiler());
				break;
			default:
				printf("erreur: commande inconnue\n");
				break;
		}
	}

	return 0;
}

#define MAXVAL 100

int pp = 0;
double val[MAXVAL]; // pile

void empiler(double f)
{
	if (pp < MAXVAL)
		val[pp++] = f;
	else
		printf("erreur: pile pleine\n");
}

double depiler(void)
{
	if (pp > 0)
		return val[--pp];
	printf("erreur: pile vide\n");
	return 0.0;
}

#include <ctype.h>

int lirecar(void);
void remettrecar(int);

int lire_op(char s[])
{
	int i, c;

	while ((s[0] = c = lirecar()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if (c == '-')
	{
		s[0] = '-';
		s[++i] = c = lirecar();
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = lirecar()))
				;
	else
		return '-';
	if (c == '.')
		while (isdigit(s[++i] = c = lirecar()))
			;
	s[i] = '\0';
	if (c != EOF)
		remettrecar(c);
	return NOMBRE;
}

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
