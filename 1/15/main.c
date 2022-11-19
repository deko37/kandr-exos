#include <stdio.h>

float fahr_cels(float value);

int main()
{
	int mini, max, inter;
	mini = 0;
	max = 300;
	inter = 10;

	for(int i = mini; i <= max; i += inter)
		printf("%3d %6.1f\n", i, fahr_cels(i));

	return 0;
}

float fahr_cels(float value)
{
	return (5.0/9) * (value-32);
}
