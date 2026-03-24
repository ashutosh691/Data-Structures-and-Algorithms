class Solution {
public:
    int isSafe(vector<vector<char>>& grid, int n, int m, int i, int j, vector<vector<bool>>& visited) {
        return (i < n && i >= 0 && j < m && j >= 0 && grid[i][j] == '1' && !visited[i][j]);
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m, int i, int j) {
        visited[i][j] = true;
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};
        for(int k = 0; k < 4; ++k) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(isSafe(grid, n, m, nr, nc, visited)) dfs(grid, visited, n, m, nr, nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, n, m, i, j);
                    ++ans;
                }
        return ans;
    }
};