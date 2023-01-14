#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAXOP 100
#define NOMBRE '0'
#define LETTRE 'a'

int lire_op(char []);
void empiler(double);
double depiler(void);
double dernier_element();
void copier(void);
void echanger();
void vider(void);

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	double variables[26]; // variables
	int temp_var_char = LETTRE;
	double derniere_valeur = DBL_MAX;

	for (int i = 0; i < 26; ++i)
		variables[i] = DBL_MAX;

	while ((type = lire_op(s)) != EOF)
	{
		switch (type)
		{
			case NOMBRE:
				empiler(atof(s));
				break;
			case LETTRE:
				temp_var_char = s[0];
				double var_nbr = variables[temp_var_char - LETTRE];
				if (var_nbr != DBL_MAX) // We check if the variable has been used
					empiler(var_nbr); // If it is the case, we "replace" (we are just adding the value to the stack)
				break;
			case '#':
				if (derniere_valeur != DBL_MAX)
					empiler(derniere_valeur);
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
			case '^':
				op2 = depiler();
				double op1 = depiler();
				if (op2 <= 0 || op1 <= 0)
					printf("erreur: puissance impossible dans ce cas-là (un des opérateurs est nul)\n");
				else
					empiler(pow(op1, (long) op2));
				break;
			case ')':
				empiler(sin(depiler()));
				break;
			case ']':
				empiler(cos(depiler()));
				break;
			case '}':
				empiler(tan(depiler()));
				break;
			case '|':
				empiler(exp(depiler()));
				break;
			case '=':
				variables[temp_var_char - LETTRE] = depiler();
				break;
			case '\"':
				printf("\t%c\t%.8g\n", temp_var_char, variables[temp_var_char - LETTRE]);
				break;
			case '\'': case '\n':
				derniere_valeur = dernier_element();
				printf("\t\t%.8g\n", derniere_valeur); 
				break;
			case '>':
				copier();
				break;
			case '?':
				echanger();
				break;
			case '_':
				vider();
				type = '\n';
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

double dernier_element(void)
{
	return val[pp - 1];
}

void copier(void)
{
	double nbr = dernier_element();
	empiler(nbr);
}

void echanger(void)
{
	double n1 = depiler();
	double n2 = depiler();
	empiler(n1);
	empiler(n2);
}

void vider(void)
{
	while (pp > 0)
		val[pp--] = 0;
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
	if (!isdigit(c) && c != '.' && c != '-' && !islower(c))
		return c;
	i = 0;
	if (islower(c))
		return LETTRE;
	if (c == '-')
	{
		s[0] = '-';
		s[++i] = c = lirecar();
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = lirecar()))
				;
	else
		return s[0];
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
