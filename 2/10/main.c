#include <stdio.h>

int min(int c);

int main()
{
	printf("min('E') = %c\n", min('E'));
	printf("min('0') = %c\n", min('0'));
	printf("min('y') = %c\n", min('y'));
	return 0;
}

int min(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
