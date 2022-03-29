
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define CFOR(i, Condition) for(int i = 0; Condition; i++)
#define OUT(s) printf(s)
#define OUTI(i) printf("%d", i)
#define OUTLL(l) printf("%lld", l)
#define OUTC(c) printf("%c", c)
#define OUTS(s) printf("%s", s)
#define LN(n, s) int n = strlen(s)
#define INT(a, n) int a = n
#define NNN printf("\n")
#define SSS printf(" ")

typedef long long ll;

int main()
{
	char *s = "013";

	CFOR(i, s[i])
	{
		OUTC(s[i]);
	}
	NNN;
}


