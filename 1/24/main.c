#include <stdio.h>

#define MAX_CHAR 1000
#define MAX_OCCU 5

int liretexte(char texte[], int limite);
int somme(int liste[], int longueur);
void vider(int liste[], int longueur);
void copier(int de[], int vers[], int longueur);

int main()
{
	char texte[MAX_CHAR];
	int longueur;
	int double_occurences[MAX_OCCU];	// 0 = (), 1 = [], 2 = {}, 3 = ", 4 = '

	while ((longueur = liretexte(texte, MAX_CHAR)) > 0)
	{
		// int cp_do[MAX_OCCU];
		// vider(cp_do, MAX_OCCU);
		vider(double_occurences, MAX_OCCU);

		for (int i = 0; i < longueur; ++i)
		{
			int c = texte[i];
			int indice_do = 0;
			int ajout = 1;

			if (c == '(' || c == ')')
			{
				indice_do = 0;
				if (c == ')')
					ajout = -double_occurences[indice_do];
			}
			else if (c == '[' || c == ']')
			{
				++indice_do;
				if (c == ']')
					ajout = -1;
			}
			else if (c == '{' || c == '}')
			{
				indice_do = 2;
				if (c == '}')
					ajout = -1;
			}
			else if (c == '"')
			{
				indice_do = 3;
				if ((double_occurences[indice_do] + 1) == 2)
					double_occurences[indice_do] = ajout = 0;
			}
			else if (c == '\'')
			{
				indice_do = 4;
				if ((double_occurences[indice_do] + 1) == 2)
					double_occurences[indice_do] = ajout = 0;
			}
			else
				ajout = 0;

			double_occurences[indice_do] += ajout;

		}
		if (somme(double_occurences, MAX_OCCU) == 0)
			printf("\n\t NO PROBLEMO \n");
		else
		{
			putchar('\n');
			for (int j = 0; j < MAX_OCCU; ++j)
				printf("\t%d = %d\n", j, double_occurences[j]);
			putchar('\n');
		}
	}
	return 0;
}

int liretexte(char texte[], int limite)
{
	int i, c;

	for (i = 0; i < (limite - 1) && (c = getchar()) != EOF && c != '#'; ++i)
		texte[i] = c;
	if (c == '\n')
	{
		texte[i] = c;
		++i;
	}
	texte[i] = '\0';
	return i;

}

int somme(int liste[], int longueur)
{
	int resultat = 0;

	for (int i = 0; i < longueur; ++i)
	{
		int nbr = liste[i];
		if (nbr < 0)
			resultat -= nbr;
		else
			resultat += nbr;
	}

	return resultat;
}

void vider(int liste[], int longueur)
{
	for (int i = 0; i < longueur; ++i)
		liste[i] = 0;
}

void copier(int de[], int vers[], int longueur)
{
	for (int i = 0; i < longueur; ++i)
		vers[i] = de[i];
}
