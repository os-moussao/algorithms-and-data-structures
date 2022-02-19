#include <stdio.h>
#include <stdbool.h>

bool match(char *name, char *pattern)
{
    if (*pattern == '\0' && *name == '\0')
        return true;

	if (*pattern == '*')
		while (pattern[1] == '*')
			pattern++;

    if (*name == '\0' && *pattern == '*' && pattern[1])
        return false;

    if (*pattern == '*')
        return match(pattern + 1, name) || match(pattern, name + 1);

    return false;
}

void test(char *n, char *p) {
	printf("%s\n", match(n, p)?"Yes":"No");
}

int main(int ac, char **av)
{
	if (ac != 3) {
		printf("./prog <name> <wildcard pattern>\n");
		return 1;
	}
	test(av[1], av[2]);
}

/**
 * This is how I tried to solve this problem before (using two ponters method)
 * still have some bugs!
 */
bool	matches_pattern(char *name, char *pattern)
{
	int	i;
	int	j;
	int	tmp_i;
	int	tmp_j;

	if (pattern[0] == '*' && !pattern[1])
		return (1);
	i = 0;
	j = 0;
	while (name[i] && pattern[j])
	{
		tmp_j = j;
		tmp_i = i;
		if (pattern[j] == '*')
			j++;
		else if (name[i] != pattern[j] && j)
			i++;
		else
		{
			while (name[i] && pattern[j] && pattern[j] != '*' && pattern[j] == name[i])
			{
				i++;
				j++;
			}
			if (name[i] && pattern[j] && pattern[j] != '*')
			{
				if (!tmp_j)
					return 0;
				i = tmp_i + 1;
				j = tmp_j;
			}
		}
	}
	while (pattern[j] == '*')
		j++;
	return (!pattern[j] && !(pattern[j - 1] != '*' && name[i]));
}