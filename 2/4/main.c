#include <stdio.h>

#define MAX_CHAR 1000

int estdans(char s[], int c);
void tasser(char s1[], char s2[]);

int main()
{
	char s1[] = "pomme de pin"; // s1 devrait ressembler à "mmn"
	char s2[] = "poire de pet"; // s2 devrait ressembler à "od"
	char s3[] = "serpentin glaçant";	

	tasser(s1, s2);
	tasser(s2, s3);
	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}

int estdans(char s[], int c)
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == c)
			return i;
	}
	
	return -1;
}

void tasser(char s1[], char s2[])
{
	int i, j;

	for (i = j = 0; s1[i] != '\0'; ++i)
	{
		if (estdans(s2, s1[i]) == -1)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
