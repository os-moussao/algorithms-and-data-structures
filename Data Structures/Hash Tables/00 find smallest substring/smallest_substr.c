/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:44:44 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/08 22:55:27 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Problem from MCPC 2017
 * find out the minimum length of a sub-string in S1 that contains all the letters in S2 at least once
 * link: https://bit.ly/3ApIASw (problem A)
**/
#include <stdio.h>
#include <string.h>

int	min_len_substr(char *s1, char *s2)
{
	int	len = strlen(s2);
	int	found[len];
	int	ans;

	for (int i = 0; i < len; i++)
		found[i] = 0;
	for (int i = 0; s1[i]; i++)
	{

	}
}
