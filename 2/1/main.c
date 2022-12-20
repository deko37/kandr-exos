#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	signed char  limit_cal_char  = 1;
	signed short limit_cal_short = 1;
	signed int   limit_cal_int   = 1;
	signed long  limit_cal_long  = 1;
	float  limit_cal_float  = 1;
	double limit_cal_double = 1;

	while (limit_cal_long > 0)
	{
		if (limit_cal_char > 0)
		{
			limit_cal_char *= 2;
			limit_cal_short = -limit_cal_char;
		}
		if (limit_cal_short > 0)
		{
			limit_cal_short *= 2;
			limit_cal_int = -limit_cal_short;
		}

		if (limit_cal_int > 0)
		{
			limit_cal_int *= 2;
			limit_cal_long = limit_cal_int;
		}
		else
			limit_cal_long *= 2;
	}

	while (limit_cal_double > 0)
	{
		if (limit_cal_float < 0)
		{
			limit_cal_float *= 2;
			limit_cal_double = limit_cal_float;
		}
		else
		{
			if (limit_cal_double == limit_cal_float)
				--limit_cal_double;
			else
				limit_cal_double *= 2;
		}
		printf("%f %f\n", limit_cal_float, limit_cal_double);
	}

	printf("Limites signées calculées : \nchar : de %d à %d\nshort: de %d à %d\nint: de %d à %d\nlong: de %d à %d\nfloat: de %f à %f\ndouble: de %f à %f",
			(limit_cal_char += 1), (--limit_cal_char), (limit_cal_short += 1), (--limit_cal_short),
			(limit_cal_int += 1), (--limit_cal_int), (limit_cal_long += 1), (--limit_cal_long), limit_cal_float, limit_cal_float, limit_cal_double, limit_cal_double);
	printf("\nLimites signées définies dans la bibliothèque stantard : \nchar : de %d à %d\nshort: de %d à %d\nint: de %d à %d\nlong: de %d à %d\n",
			CHAR_MIN, CHAR_MAX, SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN, LONG_MAX);

	unsigned char  un_limit_cal_char  = (limit_cal_char  - 1) * 2 + 1;
	unsigned short un_limit_cal_short = (limit_cal_short - 1) * 2 + 1;
	unsigned int   un_limit_cal_int   = (limit_cal_int   - 1) * 2 + 1;
	unsigned long  un_limit_cal_long  = (limit_cal_long  - 1) * 2 + 1;

	printf("\nLimites non signées calculées : \nchar : de %d à %d\nshort: de %d à %d\nint: de %d à %d\nlong: de %d à %d\n",
			0, un_limit_cal_char, 0, un_limit_cal_short, 0, un_limit_cal_int, 0, un_limit_cal_long);
	printf("\nLimites non signées définies dans la bibliothèque stantard : \nchar : de %d à %d\nshort: de %d à %d\nint: de %d à %d\nlong: de %d à %d\n",
			0, UCHAR_MAX, 0, USHRT_MAX, 0, UINT_MAX, 0, ULONG_MAX);

	return 0;
}
