/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:08:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/08 23:09:34 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// O(n) = log(n)
int mySqrt(long x){
    long    start = 0, end = x, mid;
    
    if (x == 0 || x == 1)
        return (x == 1);
    while (end - start > 1)
    {
        mid = (start + end) / 2;
        if (mid * mid == x)
            return (mid);
        if (mid * mid > x)
            end = mid;
        else
            start = mid;
    }
    return (start);
}
