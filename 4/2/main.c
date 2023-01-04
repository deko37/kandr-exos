#include <stdio.h>
#include <ctype.h>
#include <assert.h>

double atof(char s[]);

int main(void)
{
	assert(atof("17.71e2") == 1771);
	assert(atof("-17.71e-2") == -0.1771);
	assert(atof("17.71E0") == 17.71);
	assert(atof("67") == 67);
	return 0;
}

double atof(char s[])
{
	double val, puiss, puiss_exp = 1.0;
	int i, signe, signe_exp, exp;

	for (i = 0; isspace(s[i]); i++)
		; // pour éviter les espaces en début de string
	signe = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;
	for (puiss = 1.0; isdigit(s[i]); i++)
	{
		val = 10 * val + (s[i] - '0');
		puiss *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E')
		i++;
	signe_exp = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	for (; exp > 0; exp--)
		puiss_exp *= 10.0;
	if (signe_exp == -1)
		puiss_exp = 1.0 / puiss_exp;

	return signe * val / puiss * puiss_exp;
}
