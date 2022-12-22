#include <stdio.h>
#include <ctype.h>

#define MAX_CHAR 10000

void developper(char s1[], char s2[]);	// developper considère s2 plus grande que s1
void strupp(char s[]);
int copier(char de[], char vers[]);

int main()
{
	char s1[MAX_CHAR] = "L'alphabet, c'est -a-z. On peut aussi le faire en majuscules : A-B-C--. Il y a aussi les chiffres (0-9).";
	char s2[MAX_CHAR];
	developper(s1, s2);

	printf("s1 (%s) devient:\n%s\n", s1, s2);

}

int copier(char de[], char vers[])
{	
	int i;
	for (i = 0; de[i] != '\0'; ++i)
		vers[i] = de[i];
	vers[i + 1] = '\0';
	return i;
}

void strupp(char s[])
{
	for (int i = 0; s[i] != '\0'; ++i)
		s[i] = toupper(s[i]);
}

void developper(char s1[], char s2[])
{
	int i, j;
	char nombres[] = "0123456789";
	char alpha_min[MAX_CHAR] = "abcdefghijklmnopqrstuvwxyz";
	char alpha_maj[MAX_CHAR];

	copier(alpha_min, alpha_maj);
	strupp(alpha_maj);

	for (i = j = 0; s1[i] != '\0'; ++i, ++j)
	{
		int c = s1[i];
		if ((c == 'a' || c == 'A' || c == '0') && s1[i + 1] == '-')
		{
			if (tolower(s1[i + 2]) == 'z')
			{
				for (int x = 0; alpha_min[x] != '\0'; ++x)
				{
					if (islower(c))
						s2[j++] = alpha_min[x];
					else
						s2[j++] = alpha_maj[x];
				}
				s2[j] = s1[(i += 3)];
			}
			else if (tolower(s1[i + 2]) == 'b' && s1[i + 3] == '-' && tolower(s1[i + 4]) == 'c')
			{
				for (int x = 0; alpha_min[x] != '\0'; ++x)
					if (islower(c))
						s2[j++] = alpha_min[x];
					else
						s2[j++] = alpha_maj[x];
				s2[j] = s1[(i += 5)];
			}
			else if (c == '0' && s1[i + 2] == '9')
			{
				for (int x = 0; nombres[x] != '\0'; ++x)
					s2[j++] = nombres[x];
				s2[j] = s1[(i += 3)];
			}

		}
		else
			s2[j] = c;
	}

	s2[j + 1] = '\0';
}
