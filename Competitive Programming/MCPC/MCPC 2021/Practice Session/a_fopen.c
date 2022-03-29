#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*fp = fopen("eat.in", "r");
	int	T;

	fscanf(fp, "%d", &T);
	while (T--)
	{
		int	a, b;

		fscanf(fp, "%d%d", &a, &b);
		printf("Plate %d\n", a+b>a+b?1:2);
	}
	fclose(fp);
}
