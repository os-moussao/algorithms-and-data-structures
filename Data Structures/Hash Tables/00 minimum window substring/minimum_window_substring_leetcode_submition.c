/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_window_substring_leetcode_submition        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:15:39 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 21:16:46 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char * minWindow(char *str, char *pat){
    char    *res = calloc(1, 1);
	int	    len1 = strlen(str);
	int	    len2 = strlen(pat);

	if (len1 < len2)
		return (res);

	int	min_len = INT_MAX;
	int	count = 0;
	int	start = 0;
    int start_index = 0;
	int	end = -1;
	int	hash_pat[256] = {0};
	int	hash_str[256] = {0};

	for (int i = 0; i < len2; i++)
		hash_pat[pat[i]]++;

	for (int i = 0; i < len1; i++)
	{
		hash_str[str[i]]++;

		if (hash_str[str[i]] <= hash_pat[str[i]])
			count++;

		if (count == len2)
		{
			while (hash_str[str[start]] > hash_pat[str[start]])
				hash_str[str[start++]]--;

			int	window_len = i - start + 1;
			if (window_len < min_len)
			{
				min_len = window_len;
                start_index = start;
				end = i;
			}
			hash_str[str[start++]]--;
			count--;
		}
	}

    if (end != -1)
    {
        res = malloc(min_len + 1);
        strncpy(res, str + start_index, min_len);
        res[min_len] = 0;
    }
    return (res);
}
