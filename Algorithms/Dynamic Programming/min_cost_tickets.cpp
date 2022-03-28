// problem: https://leetcode.com/problems/minimum-cost-for-tickets/

// dynamic programming

// memoisation solution
class Solution {
private:
    vector <int> dp;
    vector<int> pass;
public:
    int rec_dp(vector<int> days) {
        
        if (dp[days.size()] != 1e9)
            return dp[days.size()];
        
        vector <int> days_cpy = days;

        for (int i = 0; i < pass.size(); i++) {

            int n = i == 0? 1: i == 1? 7: 30;

            auto it = lower_bound(days_cpy.begin(), days_cpy.end(), days_cpy[0] + n);
            
            // take coice
            days_cpy.erase(days_cpy.begin(), it);
            dp[days.size()] = min(rec_dp(days_cpy) + pass[i], dp[days.size()]);
            
            // backtrack
            days_cpy = days;
        }
        
        return dp[days.size()];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp = vector<int>(days.size() + 1, 1e9);
        dp[0] = 0;
        pass = costs;
        return rec_dp(days);
    }
};