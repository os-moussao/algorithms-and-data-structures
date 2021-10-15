/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberica_mcpc_2017.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:13:20 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/15 13:15:38 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void    copy_sol(char **sol, char **strs, int N);
bool    is_min(char **strs, char **sol, int N);

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

bool    equal(char *str1, char *str2, int len)
{
    while (len--)
    {
        if (str1[len] != str2[len])
            return (false);
    }
    return (true);
}

bool    connected(char **strs, int N, int D)
{
    for (int i = 0; i < N - 1; i++)
    {
        if (!equal(strs[i] + 1, strs[i + 1], D - 1))
            return (false);
    }
    return (true);
}

void	solve(char **strs, char **sol, int N, int D, int sw, bool *sol_found)
{
	if (sw == N)
	{
        if (connected(strs, N, D))
        {
            if (is_min(strs, sol, N) || !*sol_found)
                copy_sol(sol, strs, N);
            *sol_found = true;
        }
	}

	for (int i = sw; i < N; i++)
	{
		swap(&strs[sw], &strs[i]);
		solve(strs, sol, N, D, sw + 1, sol_found);
		swap(&strs[sw], &strs[i]);
	}
}

int	main(void)
{
	int	T;

	scanf("%d", &T);    
    while (T--)
    {
        int     N, D;
        char    **strs;
        char    **sol;
        bool    sol_found = false;

        scanf("%d%d", &N, &D);
        strs = malloc(N * sizeof(char *));
        sol = malloc(N * sizeof(char *));
        for (int i = 0; i < N; i++)
        {
            strs[i] = calloc(D + 1, 1);
            sol[i] = calloc(D + 1, 1);
            scanf("%s", strs[i]);
        }
        solve(strs, sol, N, D, 0, &sol_found);
        if (sol_found)
        {
            printf("Connected\n");
            for (int i = 0; i < N; i++)
                printf("%s ", sol[i]);
            printf("\n");
        }
        else
            printf("Not Connected\n");
    }
}

void    copy_sol(char **sol, char **strs, int N)
{
    for (int i = 0; i < N; i++)
        strcpy(sol[i], strs[i]);
}

bool    is_min(char **strs, char **sol, int N)
{
    int N1, N2;

    for (int i = 0; i < N; i++)
    {
        N1 = atoi(strs[i]);
        N2 = atoi(sol[i]);
        if (N1 == N2)
            continue ;
        else
            return (N1 < N2);
    }
    return (false);
}
