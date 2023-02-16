#include <stdio.h>

static int tabjour[2][13] = {			    // I changed the type to an integer because... it had more sense and was more practical
	{ 0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int jour_annee(int annee, int mois, int jour) {
	if (mois > 12 || mois < 1 || jour < 1 || jour > 31) {
		printf("erreur [jour_annee] : les arguments sont invalides dans ce cas\n");
		return -1;
	}

	int *i, bis, j;
	bis = (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
	
	for (j = 1, i = ((bis) ? tabjour[1] : tabjour[0]) + 1; mois > j; i++, j++)
		printf("%d\n", *i), jour += *i;
	return jour;
}

void mois_jour(int annee, int jourannee, int *pmois, int *pjour) {
	int *i, bis, j;
	bis = (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;

	if (jourannee < 1 || jourannee > (bis ? 366 : 365)) {
		printf("erreur [mois_jour] : les arguments sont invalides dans ce cas\n");
		return;
	}

	for (j = 1, i = ((bis) ? tabjour[1] : tabjour[0]) + 1; jourannee > *i; i++, j++)
		jourannee -= *i;
	*pmois = j;
	*pjour = jourannee;
}

int main(void) {
	printf("main: %d\n", jour_annee(2022, 3, 29));
	return 0;
}
