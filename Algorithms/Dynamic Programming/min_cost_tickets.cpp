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

// tabulation approach: top --> down
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp (days.size() + 1, 1e9);
        dp[days.size()] = 0;
        int d7, d30;
        
		for (int i = days.size() - 1; i >= 0; i--) {
            d7 = lower_bound(days.begin() + i, days.end(), days[i] + 7) - days.begin();
            d30 = lower_bound(days.begin() + i, days.end(), days[i] + 30) - days.begin();
            dp[i] = min({costs[0] + dp[i + 1], costs[1] + dp[d7], costs[2] + dp[d30]});
        }
        // for (int i = 0; i < days.size() + 1; i++) cout << dp[i] << ' ';
        return dp[0];
    }
};

// tabulation: bottom --> up
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp (days.size() + 1, 1e9);
        dp[0] = 0;
        int pre7, pre30;
        
        for (int i = 1; i <= days.size(); i++) {
            pre7 = upper_bound(days.begin(), days.begin() + i, days[i - 1] - 7) - days.begin();
            pre30 = upper_bound(days.begin(), days.begin() + i, days[i - 1] - 30) - days.begin();
            dp[i] = min({dp[i - 1] + costs[0], dp[pre7] + costs[1], dp[pre30] + costs[2]});
            cout << dp[i] << ' ';
        }

        return dp[days.size()];
    }
};
