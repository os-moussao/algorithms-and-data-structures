// task: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// I don't know why they tagged it as a hard problem!
class Solution {
public:
    typedef long long ll;
    map <pair<ll, ll>, ll> dp;
    ll solve(ll l, ll r, vector <int> &cuts) {
        if (dp[{l,r}]) return dp[{l, r}];
        ll ans = 1e18;
        for (ll i = 0; i < cuts.size(); i++) {
            if (cuts[i] >= r || cuts[i] <= l) continue;
            ans = min(ans, r-l+solve(l, cuts[i], cuts)+solve(cuts[i], r, cuts));
        }
        return dp[{l,r}] = (ans==1e18?0:ans);
    }

    ll minCost(int n, vector<int>& cuts) {
        return solve(0, n, cuts);
    }
};