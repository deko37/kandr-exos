#include "ltr.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
	double nombre = 0;
	while (lire_float(&nombre) != EOF)
		printf("%f\n", nombre);
	return 0;
}
