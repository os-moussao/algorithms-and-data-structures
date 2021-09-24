/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn_42_exercise.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:00:23 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/24 17:18:55 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	g_total = 0;

void	backtrack(char stack[], int index, int start, int n)
{
	if (index == n)
	{
		if (g_total)
			write(1, ", ", 2);
		write(1, stack, n);
		g_total++;
		return ;
	}
	while (start <= '9')
	{
		stack[index] = start;
		backtrack(stack, index + 1, start + 1, n);
		start++;
	}
}

void	ft_print_combn(int n)
{
	char	stack[10];

	backtrack(stack, 0, '0', n);
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
	{
		write(2, "Usage: ./program [n]\n", 21);
		return (1);
	}
	n = atoi(argv[1]);
	if (n < 1 || n > 9)
	{
		write(2, "Enter: 0 < n < 10\n", 18);
		return (2);
	}
	ft_print_combn(n);
}
