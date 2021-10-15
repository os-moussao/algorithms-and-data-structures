/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palindrome_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:10:55 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/14 13:15:46 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool	is_palindrome(char *str, int size)
{
	if (!*str)
		return (true);
	if (str[0] != str[size - 1])
		return (false);
	return is_palindrome(str + 1, size - 2);
}

int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		printf("%s\n", is_palindrome(av[i], strlen(av[i]))? "palindrome": "not palindrome");
}
