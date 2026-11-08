class Solution {
public:
    void mark(vector<vector<bool>> &vis, vector<vector<int>>& grid, int r, int c) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i) {
            if(grid[r][i]) ++count;
            if(count > 1) {
                for(int i = 0; i < m; ++i) if(grid[r][i]) vis[r][i] = true;
                break;
            }
        }
        count = 0;
        for(int i = 0; i < n; ++i) {
            if(grid[i][c]) ++count;
            if(count > 1) {
                for(int i = 0; i < n; ++i) if(grid[i][c]) vis[i][c] = true;
                break;
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(grid[i][j]) mark(vis, grid, i, j);
        int c = 0;
        for(auto i : vis) for(auto j : i) if(j) ++c;
        return c;
    }
};