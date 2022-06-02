// task: https://leetcode.com/problems/number-of-ways-to-separate-numbers/

class Solution {
public:
	int mod = (int)(1e9+7);
	int numberOfCombinations(string &n) {
		int sz = n.size();
		int dp[sz+10][sz+10];
		int pre[sz+10][sz+10];
		memset(dp, 0, sizeof dp);
		memset(pre, 0, sizeof pre);
		for (int i = 1; i <= sz; i++) {
			dp[i][i] = n[0] == '0'? 0: 1;
			for (int k = 1; k < i; k++) {
				if (n[i-k] == '0') {dp[i][k] = 0; continue;}
				dp[i][k] += pre[i-k][min(i-k, k-1)];
				dp[i][k] %= mod;
				if (k <= i-k) {
					string_view n1(n.c_str() + i-k, k);
					string_view n2(n.c_str() + i-2*k, k);
					if (n1 >= n2) dp[i][k] += dp[i-k][k], dp[i][k] %= mod;
				}
			}
			for (int j = 1; j <= i; j++) {
				pre[i][j] = (pre[i][j-1] + dp[i][j]) % mod;
			}
		}
		return pre[sz][sz];
	}
};