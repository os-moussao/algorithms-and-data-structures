// problem: https://leetcode.com/problems/longest-palindromic-substring/

// dp approach
// if a string is already palindrome
// and ajdacent character on the left and the right are equal
// then we get another bigger palindrom string
// Time: O(N^2)
// Space: O(N)   (return s.substr)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start, len = -1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 1; i-j>=-1 && i+j<=n;j++) {
                if (i-j < 0 || s[i-j] != s[i+j]) {
                    --j;
                    if (2*j+1 > len) {
                        start = i-j;
                        len = 2*j+1;
                    }
                    break ;
                }
            }
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; i-j>=-1 && i+j+1<=n;j++) {
                if (i-j < 0 || s[i-j] != s[i+j+1]) {
                    --j;
                    if (2*(j+1) > len) {
                        start = i-j;
                        len = 2*(j+1);
                    }
                    break ;
                }
            }
        }
        return s.substr(start, len);
    }
};

// another dp approach
// same as the brutforce solution, but we reduce the complexity for palindromic checks
// by using previous computations
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    vector <vector<int>> dp;
public:
    bool is_pal(const string &s, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l == r) return dp[l][r] = 1;
        dp[l][r] = (s[l] == s[r]);
        if (dp[l][r] && l+1<r-1)
            dp[l][r] = is_pal(s, l+1, r-1);
        return dp[l][r];
    }
    string longestPalindrome(string s) {
        int n = s.length();
        dp = vector (n, vector<int>(n, -1));
        int start, len = -1e9;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (r-l+1>len && is_pal(s, l, r)) {
                    start = l;
                    len = r-l+1;
                }
            }
        }
        return s.substr(start, len);
    }
};


// brutforce Time: ~O(N^3)
class Solution {
public:
    bool is_pal(const string &s, int l, int r) {
        for (int i = l; i < l+(r-l+1)/2; i++) {
            if (s[i] != s[r - (i-l)]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int start, len = -1e9;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (r-l+1>len && is_pal(s, l, r)) {
                    start = l;
                    len = r-l+1;
                }
            }
        }
        return s.substr(start, len);
    }
};
