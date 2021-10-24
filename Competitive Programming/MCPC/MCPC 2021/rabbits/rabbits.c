#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	FILE	*in = freopen("rabbits.in", "r", stdin);
	
	long long int	a, b;

	scanf("%lld%lld", &a, &b);
	printf("%lld\n", a * b + a);
	fclose(in);
}
