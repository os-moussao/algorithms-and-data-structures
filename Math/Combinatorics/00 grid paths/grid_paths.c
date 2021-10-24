/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:43:32 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 18:45:55 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// number of unique paths is: (n - 1) C (m - 1 + n - 1)  [k C n: k elements out of n elements]
int uniquePaths(int n, int m)
{
    long long res = 1;
    
    for (int i = n; i < n + m - 1; i++)
    {
        res *= i;
        res /= i - n + 1;
    }
	return (res);
}
