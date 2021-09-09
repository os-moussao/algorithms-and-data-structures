/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_path_sum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:51:54 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 14:52:58 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// See description at: https://leetcode.com/problems/minimum-path-sum/

int min(int a, int b)
{
    return (a <= b? a: b);
}

int minPathSum(int** grid, int n, int* m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (j == 0 && i == 0)
                continue ;
            else if (i == 0)
                grid[i][j] += grid[i][j - 1];
            else if (j == 0)
                grid[i][j] += grid[i - 1][j];
            else
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
        }
    }
    return (grid[n - 1][*m - 1]);
}
