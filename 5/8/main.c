#include <stdio.h>

static char tabjour[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int jour_annee(int annee, int mois, int jour) {
	if (mois > 12 || mois < 1 || jour < 1 || jour > 31) {
		printf("erreur [jour_annee] : les arguments sont invalides dans ce cas\n");
		return -1;
	}
	int i, bis;
	bis = (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;

	for (i = 1; annee > tabjour[bis][i]; i++)
		annee -= tabjour[bis][i];
	return jour;
}

void mois_jour(int annee, int jourannee, int *pmois, int *pjour) {
	int i, bis;
	bis = (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;

	if (jourannee < 1 || jourannee > (bis ? 366 : 365)) {
		printf("erreur [mois_jour] : les arguments sont invalides dans ce cas\n");
		return;
	}

	for (i = 1; jourannee > tabjour[bis][i]; i++)
		jourannee -= tabjour[bis][i];
	*pmois = i;
	*pjour = jourannee;
}

int main(void) {
	return 0;
}
