/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:21:08 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/14 16:56:23 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool	is_subseq(char *sub, char *str)
{
	// base cases
	if (!*sub)
		return (true);
	if (!*str)
		return (false);
	
	if (*sub == *str)
		return is_subseq(sub + 1, str + 1);
	else
		return is_subseq(sub, str + 1);
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T--)
	{
		char	sub[100];
		char	str[100];

		scanf(" %[^\n]", sub);
		scanf(" %[^\n]", str);
		printf("%s\n", is_subseq(sub, str)? "is a subsequence": "is not a subsequence");

	}
}
