#include <stdio.h>
#include <time.h>

int dicho(int x, int v[], int n);
int my_dicho(int x, int v[], int n);

int main()
{
	int v[1000];

	for (int i = 1; i <= 1000; ++i)
		v[i - 1] = i;

	time_t tim1 = time(NULL);
	int a = dicho(30, v, 1000);
	
	time_t tim2 = time(NULL);
	int b = my_dicho(30, v, 1000);
	
	printf("Chez dicho, %d\t Chez mon dicho, %d\n", v[a], v[b]);
	printf("%fs de différence.\n", difftime(tim2, tim1));

	return 0;
}

int dicho(int x, int v[], int n)
{
	int haut, bas, milieu;

	haut = n - 1;
	bas = 0;

	while (bas <= haut)
	{
		milieu = (haut + bas) / 2;
		if (x < milieu)
			haut = milieu - 1;
		else if (x > milieu)
			bas = milieu + 1;
		else
			return milieu;
	}

	return -1;
}

int my_dicho(int x, int v[], int n)
{
	int haut, bas, indice, operateur;

	haut = n - 1;
	bas = 0;
	indice = haut / 2;

	if (indice < x)
		operateur = 1;
	else if (indice > x)
		operateur = -1;

	while (indice >= bas && indice <= haut)
	{
		if (indice == x)
			return indice;
		indice += operateur;
	}

	return -1;
}
