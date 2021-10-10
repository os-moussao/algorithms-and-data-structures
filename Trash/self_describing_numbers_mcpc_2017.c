/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_describing_numbers_mcpc_2017.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:28:41 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 22:22:02 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_SIZE 10

bool	is_self_describing(long long int nbr)
{
	int	power = 10;
	int	size = 1;
	
	while (nbr / power)
	{
		power *= 10;
		size++;
	}

	int	hash_int[ARR_SIZE] = {0};
	int	hash_desc[ARR_SIZE] = {0};

	for (int i = 0; i < size; i++)
	{
		power /= 10;
		hash_int[i] = (nbr / power) % 10;
		hash_desc[hash_int[i]]++;
	}

	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (hash_int[i] != hash_desc[i])
			return (false);
	}
	return (true);
}

int	main(void)
{
	int	T;

	scanf("%d", &T);

	bool	solution[T];
	for (int i = 0; i < T; i++)
	{
		long long int	nbr;
		scanf("%lld", &nbr);
		solution[i] = is_self_describing(nbr);
	}
	for (int i = 0; i < T; i++)
		printf("%s", solution[i]? "self-describing\n": "not self-describing\n");
}
