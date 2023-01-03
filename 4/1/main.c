#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_LIGNE 1000

int lireligne(char ligne[], int max);
int chpos(char source[], char chercher[]);
int chposd(char source[], char chercher[]);

int main(void)
{
	char s1[] = "01x34567x9";
	char s2[] = "";
	printf("%d\n", chposd(s1, "x9"));
	printf("%d\n", chposd(s1, "9"));
	return 1;
}

int lireligne(char ligne[], int max)
{
	int i, c;
	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n')
		ligne[i++] = c;
	if (c == '\n')
		ligne[i++] = '\n';
	ligne[i] = '\0';
	return i;
}

int chpos(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int chposd(char s[], char t[])
{
	int i, j, k;
	for (i = strlen(s); i >= 0; i--)
	{
		for (j = i, k = strlen(t); k >= 0 && s[j] == t[k]; j--, k--)
			;
		if (s[j] == t[0])
			return j;
	}
	return -1;
}
