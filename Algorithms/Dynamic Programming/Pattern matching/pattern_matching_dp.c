#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool match(char *name, char *pattern)
{
	int		n = strlen(name);
	int		m = strlen(pattern);
	bool	T[n + 1][m + 1];

	T[0][0] = true;
	for (int i = 1; i < n + 1; i++) {
		T[i][0] = false;
	}
	for (int j = 1; j < m + 1; j++) {
		T[0][j] = false;
		if (pattern[j - 1] == '*') T[0][j] = T[0][j - 1];
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (name[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
				T[i][j] = T[i - 1][j - 1];
			}
			else if (pattern[j - 1] == '*') {
				T[i][j] = T[i - 1][j] || T[i][j - 1];
			}
			else {
				T[i][j] = false;
			}
		}
	}
	return T[n][m];
}

void test(char *n, char *p) {
	printf("%s\n", match(n, p)?"Yes":"No");
}

int main(int ac, char **av)
{
	if (ac != 3) {
		printf("./prog <name> <pattern>\n");
		return 1;
	}
	test(av[1], av[2]);
}