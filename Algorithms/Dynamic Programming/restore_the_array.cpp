// task: https://leetcode.com/problems/restore-the-array/
class Solution {
public:
    int mod = (int)(1e9+7);
    int numberOfArrays(string n, int bound) {
        string k = to_string(bound);
        int sz = n.size();
        int ksz = k.size();
        int dp[sz+10];
        dp[0] = 1;
        for (int i = 1; i <= sz; i++) {
            dp[i] = 0;
            int l = max(0, i - ksz), r = i-1;
            string_view tmp(n.c_str() + l, i-l);
            if ((tmp.size() >= ksz) && (tmp > k)) l++;
            for (int j = l; j <= r; j++) {
                if (n[j] != '0') {
                    dp[i] += dp[j];
                    dp[i] %= mod;
                }
            }
        }
        return dp[sz];
    }
};