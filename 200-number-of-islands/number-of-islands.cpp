class Solution {
    int n, m;
    vector<vector<bool>> vis;
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        vis[r][c] = true;
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; ++i) {
            int xr = r + dr[i], yr = c + dc[i];
            if(xr >= 0 && xr < n && yr >= 0 && yr < m && !vis[xr][yr] && grid[xr][yr] == '1') dfs(grid, xr, yr);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        vis.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j);
                    ++ans;
                }
        return ans;
    }
};