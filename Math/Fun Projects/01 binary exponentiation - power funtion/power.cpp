/*
 * useful resources:
 * https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
 * https://cp-algorithms.com/algebra/binary-exp.html
 * */
#include <iostream>
using namespace std;

#define int long long
#define double long double

double	power(double x, int n)
{
	double	res = 1;

	while (n)
	{
		if (n % 2 == 0)
		{
			x *= x;
			n /= 2;
		}
		else
		{
			if (n > 0)
			{
				res *= x;
				n -= 1;
			}
			else
			{
				res /= x;
				n += 1;
			}
		}
	}
	return (res);
}

int32_t	main(void)
{
	cout << power(3, -1) << endl;
}

// power only with natural numbers and unsigned integers
int	power_u(int x, unsigned int n)
{
	int res = 1;

	while (n > 0)
	{
		if (n % 2 == 0)
		{
			x *= x;
			n /= 2;
		}
		else
		{
			res *= x;
			n -= 1;
		}
	}
	return (res);
}

