/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmax_codingame_contest.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:41:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/12 00:45:34 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int	main(void)
{
    int		width;
    int		height;
	char	**map, **sol;

    scanf("%d%d", &width, &height);
    
	map = malloc(height * sizeof(char *));
	sol = malloc(height * sizeof(char *));
	for (int i = 0; i < height; i++)
	{
		map[i] = calloc(width + 1, 1);
		sol[i] = calloc(width + 1, 1);
        scanf("%s", map[i]);
    }
    return 0;
}
