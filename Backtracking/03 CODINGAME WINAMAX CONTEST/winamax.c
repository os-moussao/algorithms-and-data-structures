/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winamax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:36:48 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/13 22:02:53 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int w;
    int h;

    scanf("%d%d", &w, &h);

    char    grid[h][w + 1];

    for (int i = 0; i < h; i++) {
        char row[w + 1];
        scanf("%s", row);
        strncpy(grid[i], row, w);
        grid[i][w] = 0;
    }

    for (int i = 0; i < h; i++)
        printf("%s\n", grid[i]);

    return 0;
}
