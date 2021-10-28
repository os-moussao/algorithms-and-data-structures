#include <stdio.h>

/**
 * zero will not be counted so ones[0] = 0
 * "one" is 3 letters (ones[1] = 3)
 * "two" is 3 letters (ones[2] = 3)
 * ... "nineteen" is 8 letters (ones[19] = 8)
 **/
int	ones[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

/**
 * "twenty" is 6 letters (tens[2] = 6)
 * "thirty" is 6 letters (tens[3] = 6)
 * and so on...
 **/
int	tens[11] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

// other useful pieces
int	hundred = 7;
int	thousand = 8;
int	and = 3;

/**
 * this is the same algorithm I used in "numbers-to-words converter"
 * except that this one returns the letters count instead
 * see Math/Fun Projects/04
 **/
int	convert(int n)
{
	if (n < 20)
		return (ones[n]);
	else if (n < 100)
		return (tens[n / 10] + ones[n % 10]);
	else if (n < 1000)
	{
		int	res = convert(n / 100) + hundred;
		if (n % 100)
			res += and + convert(n % 100);
		return (res);
	}
	else
		return ones[1] + thousand;
}

int	main(void)
{
	int	sum = 0;
	for (int n = 1; n <= 1000; n++)
		sum += convert(n);
	printf("%d\n", sum);
}
