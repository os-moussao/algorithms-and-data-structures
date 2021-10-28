#include <stdio.h>
#include <string.h>

/*
 * I first did just by calculating 2 to the power 1000
 * but turns out to be an extremely large number 
 * this can work in languages like python but not in C (we don't do that here hhhhhhhh)
 *
 * so I implemented the simple algorithm that every one uses to calculate a multiplication in a paper
 * multiplying digit by digit and adding the carry along the way
**/

int	Power = 1000;

void	res_push(char *res, int n)
{
	int	len = strlen(res);

	for (int i = len; i > 0; i--)
		res[i] = res[i - 1];
	res[0] = n + '0';
}

int	main(void)
{
	char	res[1000] = {0};
	char	replace;
	int		carry, mult;
	int		digit_sum = 0;

	res[0] = '2';
	for (int i = 1; i < Power; i++)
	{
		int	j = 0;
		while (res[j])j++;j--;

		carry = 0;
		while (j >= 0)
		{
			mult = (res[j] - '0') * 2 + carry;
			replace = mult % 10 + '0';
			carry = mult / 10;
			res[j] = replace;
			j--;
		}
		if (carry)
			res_push(res, carry);
	}

	for (int i = 0; res[i]; i++)
		digit_sum += res[i] - '0';

	printf("2^1000 = %s\n\n", res);
	printf("digits = %zd\n", strlen(res));
	printf("DIGIT SUM = %d\nQED!\n", digit_sum);
}

/* useless functions */
long long	power(long long b, long long p)
{
	if (p <= 0)
		return (p == 0);
	if (p % 2 == 0)
		return (power(b*b, p / 2));
	else
		return (b * power(b*b, (p - 1) / 2));
}

int	sum_dig(long long nbr)
{
	int	sum = 0;
	while (nbr)
	{
		sum += nbr % 10;
		nbr /= 10;
	}
	return (sum);
}
