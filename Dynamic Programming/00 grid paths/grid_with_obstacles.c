/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_with_obstacles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:18:38 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 14:19:59 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// My leetcode solution
// Time: m * n
// Space: 1
int uniquePathsWithObstacles(int** arr, int n, int* m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
            if (arr[i][j] == 1)
                arr[i][j] = 0;
            else if (j == 0 && i == 0)
                arr[i][j] = !arr[i][j];
			else if (i == 0)
				arr[i][j] = arr[i][j - 1];
            else if (j == 0)
                arr[i][j] = arr[i - 1][j];
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	return (arr[n - 1][*m - 1]);
}
