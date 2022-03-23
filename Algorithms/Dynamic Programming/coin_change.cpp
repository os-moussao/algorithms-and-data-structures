// problem: https://leetcode.com/problems/coin-change/


// solution 1: memoisation and backtracking
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

// solution 2: bottom up approach

class Solution {
private:
    vector<int> dp;

public:
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<int>(amount + 1, amount + 1); dp[0] = 0;

        for (int am = 1; am <= amount; am++) {
            // choices
            for (int coin: coins) {
                if (am - coin < 0) continue ;
                
                dp[am] = min(dp[am], 1 + dp[am - coin]);
            }
        }

        return dp[amount] == amount + 1? -1: dp[amount];
    }
};
