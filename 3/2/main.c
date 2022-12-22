#include <stdio.h>

#define MAX_CHAR 10000

void echap(char s[], char t[]);		// En supposant dans les deux fonctions que t est plus grand que s
void transf_echap(char s[], char t[]);

int main()
{
	char s[MAX_CHAR] = "toto\n\n\t";
	char t[MAX_CHAR];

	echap(s, t);
	printf("%s\n", t);

	for (int i = 0; t[i] != '\0'; ++i)
		printf("%c\n", t[i]);

	transf_echap(t, s);
	printf("%s\n", s);
}

void echap(char s[], char t[])
{
	int i = 0;
	int j = i;
	for (; s[i] != '\0'; ++i, ++j)
	{
		int c = s[i];
		switch (c)
		{
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j] = 't';
				break;
			default:
				t[j] = c;
				break;
		}
	}
	t[j + 1] = '\0';
}

void transf_echap(char s[], char t[])
{
	int i = 0;
	int j = i;
	for (; s[i] != '\0'; ++i, ++j)
	{
		int c = s[i];
		switch (c)
		{
			case '\\':
				switch (s[i + 1])
				{
					case 'n':
						t[j] = '\n';
						i++;
						break;
					case 't':
						t[j] = '\t';
						i++;
						break;
				}
				break;
			default:
				t[j] = c;
				break;
		}
	}
	t[j + 1] = '\0';
}
