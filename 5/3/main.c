#include <stdio.h>
#include <assert.h>

void my_strcat(char*, char*);

int main()
{
	char s1[1000] = "JIo";
	char s2[] = "PS";
	my_strcat(s1, s2);
	for (int i = 0; s1[i] != '\0'; ++i)
		assert(s1[i] == "JIoPS"[i]);
	return 0;
}

void my_strcat(char *s, char *t)
{
	while (*s++ != '\0')
		;
	while ((*s++ = *t++) != '\0')
		;
}
