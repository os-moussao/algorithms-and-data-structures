/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcpc_2017_problem_A.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:44:44 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/09 19:20:22 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Problem from MCPC 2017
 * find out the minimum length of a sub-string in S1 that contains all the letters in S2 at least once
 * link: https://bit.ly/3ApIASw (problem A)
**/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define INT_MAX 2147483647

int	min_len_substr(char *str, char *pat)
{
	int	len1 = strlen(str);
	int	len2 = strlen(pat);

	if (len1 < len2)
		return (-1);

	int	min_len = INT_MAX;
	int	count = 0;
	int	start = 0;
	int	end = -1;
	int	hash_pat[26] = {0};
	int	hash_str[26] = {0};

	for (int i = 0; i < len2; i++)
		hash_pat[pat[i] - 'a']++;

	for (int i = 0; i < len1; i++)
	{
		if (str[i] == 32)
			continue;

		hash_str[str[i] - 'a']++;

		if (hash_str[str[i] - 'a'] <= hash_pat[str[i] - 'a'])
			count++;

		if (count == len2)
		{
			while (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'])
				hash_str[str[start++] - 'a']--;

			int	window_len = i - start + 1;
			if (window_len < min_len)
			{
				min_len = window_len;
				end = i;
			}
			hash_str[str[start++] - 'a']--;
			count--;
		}
	}

	return (end != -1? min_len: -1);
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	int	solution[T];
	
	for (int i = 0; i < T; i++)
	{
		char	str[1000000];
		char	pat[1000000];

		scanf(" %[^\n]%*c", str);
		scanf(" %[^\n]%*c", pat);
		solution[i] = min_len_substr(str, pat);
	}

	for (int i = 0; i < T; i++)
		printf("%d\n", solution[i]);

	return (0);
}
