// task: https://leetcode.com/problems/decode-ways-ii/

class Solution {
public:
    typedef long long ll;
    ll mod = (int)(1e9+7);
    int numDecodings(string n) {
        ll sz = n.size();
        ll dp[sz+10];
        dp[0] = 1;
        dp[1] = n[0] == '*'? 9: n[0] != '0'? 1 : 0;
        for (ll i = 2; i <= sz; i++) {
            dp[i] = 0;
            string_view sub(n.c_str() + i-2, 2);
            // 4 cases (d: digit, *: '*'): dd - d* - *d - **
            bool cas[4];
            cas[0] = isdigit(sub[0]) && isdigit(sub[1]);
            cas[1] = isdigit(sub[0]) && sub[1] == '*';
            cas[2] = sub[0] == '*' && isdigit(sub[1]);
            cas[3] = sub[0] == '*' && sub[1] == '*';
            if (cas[0]) {
                dp[i] += sub[1] != '0'? dp[i-1]: 0, dp[i] %= mod;
                if (sub <= "26") dp[i] += sub[0] != '0'? dp[i-2]: 0, dp[i] %= mod;
            }
            else if (cas[1]) {
                dp[i] += 9 * dp[i-1], dp[i] %= mod;
                if (sub[0] == '1') dp[i] += 9 * dp[i-2], dp[i] %= mod;
                else if (sub[0] == '2') dp[i] += 6 * dp[i-2], dp[i] %= mod;
            }
            else if (cas[2]) {
                dp[i] += sub[1] != '0'? dp[i-1]: 0, dp[i] %= mod;
                dp[i] += dp[i-2], dp[i] %= mod;
                if (sub[1] <= '6') dp[i] += dp[i-2], dp[i] %= mod;
            }
            else if (cas[3]) {
                dp[i] += dp[i-1] * 9 + 15 * dp[i-2], dp[i] %= mod;
            }
        }
        return dp[sz] % mod;
    }
};