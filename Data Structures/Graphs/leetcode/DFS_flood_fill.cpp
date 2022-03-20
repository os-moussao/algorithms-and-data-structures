// problem: https://leetcode.com/problems/flood-fill/

class Solution {
private:
    int newCol;
    int oldCol;
    map <pair<int, int>, bool> visited;
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
    
    void dfs_flood_fill(vector<vector<int>> &grid, int i, int j) {
        grid[i][j] = newCol;
        visited[make_pair(i, j)] = 1;
        vector<pair<int, int>> nei = neigh(grid, i, j);
        for (int i = 0; i < nei.size(); i++) {
            if (grid[nei[i].first][nei[i].second] == oldCol && !visited[make_pair(nei[i].first, nei[i].second)])
                dfs_flood_fill(grid, nei[i].first, nei[i].second);
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        newCol = newColor;
        oldCol = image[sr][sc];
        dfs_flood_fill(image, sr, sc);
        return image;
    }
};
