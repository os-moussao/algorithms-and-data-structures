// problem: https://leetcode.com/problems/count-sub-islands/

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
    
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& grid1) {
        int is_sub = (grid1[i][j] == 1);
        grid[i][j] = 0;
        vector<pair<int, int>> nei = neigh(grid, i, j);
        for (int i = 0; i < nei.size(); i++) {
            if (grid[nei[i].first][nei[i].second] == 1) {
                is_sub = dfs(grid, nei[i].first, nei[i].second, grid1) && is_sub;
            }
        }
        return is_sub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    n += dfs(grid2, i, j, grid1);
                }
            }
        }
        return n;
    }
};