#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>


int	solve(int *tab, int l, int r)
{
	int n = r - l + 1; 
	int	k = 1;
	int	res = 1;

	while (l < r)
		k += (tab[l - 1] == tab[l]), l++;
	while (n > k)
		res *= n--;
	return (res);
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T--)
	{
		int	N, Q;

		scanf("%d%d", &N, &Q);
		int	tab[N];
		int	ans[Q];
		for (int i = 0; i < N; i++)
			scanf("%d", &tab[i]);
		for (int i = 0; i < Q; i++)
		{
			int	l, r;
			scanf("%d%d", &l, &r);
			ans[i] = solve(tab, l, r);
		}
		for (int i = 0; i < Q; i++)
			printf("%d\n", ans[i]);
	}
}
