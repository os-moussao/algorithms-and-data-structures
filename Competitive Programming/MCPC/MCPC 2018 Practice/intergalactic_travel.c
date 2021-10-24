#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

void	solve(int **graph, int *visited, int node, int N, int cost, int *min)
{
	if (graph[node][N - 1])
	{
		cost++;
		if (cost <= *min)
			*min = cost;
		return ;
	}
	
	visited[node] = 1;
	for (int i = 0; i < N - 1; i++)
	{
		if (graph[node][i] && !visited[i])
		{
			visited[i] = 1;
			solve(graph, visited, i, N, cost + 1, min);
			visited[i] = 0;
		}
	}
	visited[node] = 0;
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T--)
	{
		int	N;
		int	min = INT_MAX;

		scanf("%d", &N);
		int	*graph[N];
		for (int i = 0; i < N; i++)
			graph[i] = calloc(N, sizeof(int));
		int	*visited = calloc(N, sizeof(int));
		for (int i = 0; i < N; i++)
		{
			int	l, r;
			scanf("%d%d", &l, &r);
			for (int j = l - 1; j < r; j++)
				graph[i][j] = graph[j][i] = 1;
		}
		solve(graph, visited, 0, N, 0, &min);
		printf("%d\n", min == INT_MAX? -1: min);
	}
}
