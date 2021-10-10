/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_describing_numbers_mcpc_2017.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:37:15 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 22:58:37 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define ARR_SIZE 10

bool	is_self_describing(char *nbr)
{
	int	hash_desc[ARR_SIZE] = {0};
	int	i = 0;
	
	while (nbr[i])
		hash_desc[nbr[i++] - '0']++;

	for (int j = 0; j < i; j++)
	{
		if ((int)(nbr[j] - '0') != hash_desc[j])
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
		char	nbr[ARR_SIZE];
		scanf(" %[^\n]", nbr);
		solution[i] = is_self_describing(nbr);
	}
	for (int i = 0; i < T; i++)
		printf("%s", solution[i]? "self-describing\n": "not self-describing\n");
}
