#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int main (void)
{
	FILE *fp = freopen("input.in", "r", stdin);

	int	T;

	scanf("%d", &T);
	while (T--)
	{
		int	a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}
	//freopen("output.txt", "w", stdout);
	fclose(fp);
	return(0);
}
