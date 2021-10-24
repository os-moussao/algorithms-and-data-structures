#include <stdio.h>

int	main(void)
{
	long long fib;
	long long fib_n = 1;
	long long fib_m = 0;
	long long count = 0;
	int i = 2;

	while (fib <= 4000000)
	{
		fib = fib_n + fib_m;
		fib_m = fib_n;
		fib_n = fib;
		if (fib % 2 == 0 && fib <= 4000000)
			count += fib; //, printf("%lld	%d\n",fib,  i);
		i++;
	}
	printf("%lld", count);
}
