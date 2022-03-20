// problem: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    vector<pair<int, int>> neigh(vector<vector<char> >& grid, int i, int j) {
        int d0[4] = {1, 0, -1, 0};
        int d1[4] = {0, 1, 0, -1};
        vector<pair<int, int>> ret;
        
        int ii, jj;
        for (int k = 0; k < 4; k++) {
            ii = i + d0[k]; jj = j + d1[k];
            if (ii < 0 || ii >= grid.size() || jj < 0 || jj >= grid[0].size()) continue ;
            ret.push_back(make_pair(ii, jj));
        }
        return ret;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        vector<pair<int, int>> nei = neigh(grid, i, j);
        for (int i = 0; i < nei.size(); i++) {
            if (grid[nei[i].first][nei[i].second] == '1')
                dfs(grid, nei[i].first, nei[i].second);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};