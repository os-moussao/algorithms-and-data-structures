// problem: https://leetcode.com/problems/coin-change/

class Solution {
private:
    vector<int> dp;
    vector<int> coins;
public:
    int backtrack_dp(int amount) {
    
        if (amount == 0) return 0;
        
        if (amount < 0) return -1;
       
        if (dp[amount]) return dp[amount];
        
        bool ok = 0;
        dp[amount] = amount + 1;
        for (int coin: coins) {
            int res = backtrack_dp(amount - coin);
            
            if (res >= 0 && res + 1 < dp[amount]) {
                dp[amount] = 1 + res;
                ok = 1;
            }
        }
        
        return ok? dp[amount]: dp[amount] = -1;
    }
    
    int coinChange(vector<int>& coins_inp, int amount) {
        dp = vector<int>(amount + 1);
        coins = coins_inp;
        return backtrack_dp(amount);
    }
};
