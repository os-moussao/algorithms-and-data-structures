// problem: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
        vector<pair<int, int>> neigh(vector<vector<int> >& grid, int i, int j) {
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
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 1;
        vector<pair<int, int>> nei = neigh(grid, i, j);
        int is_closed = nei.size() == 4;
        for (int i = 0; i < nei.size(); i++) {
            if (grid[nei[i].first][nei[i].second] == 0)
                is_closed = dfs(grid, nei[i].first, nei[i].second) && is_closed;
        }
        return is_closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int closed = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    closed += dfs(grid, i, j);
                }
            }
        }
        return closed;
    }
};