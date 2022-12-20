#include <stdio.h>

int ouestil(char s1[], char s2[]);

int main()
{
	char s1[] = "Hugo Valz";
	char s2[] = "Koyonamour";
	char s3[] = "Weyjeg";

	printf("%d\n", ouestil(s1, s2));
	printf("%d\n", ouestil(s2, s3));
	printf("%d\n", ouestil(s1, s3));

	return 0;
}

int ouestil(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == s2[i])
			return i;
		else
		{
			for (j = 0; s2[j] != '\0'; ++j)
			{
				if (s1[i] == s2[j])
					return i;
			}
		}
	}

	return -1;
}
