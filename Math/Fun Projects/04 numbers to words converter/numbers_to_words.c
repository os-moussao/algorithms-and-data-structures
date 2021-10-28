/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:50:12 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/28 04:13:20 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * numbers that don't have a certain pattern
 */
char	*ones[20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
					"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
					"eighteen", "nineteen"};

char	*tens[11] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

/**
 * print number in letters
 * this function handles numbers from 0 up to a 1000
 */
void	convert(int n)
{
	if (n == 0)
		printf("zero");
	else if (n < 20)
		printf("%s", ones[n]);
	else if (n < 100)
	{
		printf("%s", tens[n / 10]);
		if (n % 10)
			printf(" %s", ones[n % 10]);
	}
	else if (n < 1000)
	{
		convert(n / 100);
		printf(" hundred");
		if (n % 100)
		{
			printf(" and ");
			convert(n % 100);
		}
	}
	else
		printf("one thousand");
}

int	main(void)
{
	int	n;
	printf("enter a number: ");
	scanf("%d", &n);
	convert(n);
	printf("\n");
}
