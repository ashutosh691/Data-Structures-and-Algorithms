class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        int n = grid.size(), m = grid[0].size();
        return r >= 0 && r < n && c >= 0 && c < m && !visited[r][c];
    }

    bool canConnect(int curr, int next, int dr, int dc) {
        if(dr == 0 && dc == 1)   return (next == 1 || next == 3 || next == 5); 
        if(dr == 0 && dc == -1)  return (next == 1 || next == 4 || next == 6); 
        if(dr == 1 && dc == 0)   return (next == 2 || next == 5 || next == 6); 
        if(dr == -1 && dc == 0)  return (next == 2 || next == 3 || next == 4); 
        return false;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        int type = grid[r][c];

        if(type == 1) {
            if(isSafe(grid, r, c+1, visited) && canConnect(type, grid[r][c+1], 0, 1))
                dfs(grid, r, c+1, visited);
            if(isSafe(grid, r, c-1, visited) && canConnect(type, grid[r][c-1], 0, -1))
                dfs(grid, r, c-1, visited);
        }
        else if(type == 2) {
            if(isSafe(grid, r-1, c, visited) && canConnect(type, grid[r-1][c], -1, 0))
                dfs(grid, r-1, c, visited);
            if(isSafe(grid, r+1, c, visited) && canConnect(type, grid[r+1][c], 1, 0))
                dfs(grid, r+1, c, visited);
        }
        else if(type == 3) {
            if(isSafe(grid, r, c-1, visited) && canConnect(type, grid[r][c-1], 0, -1))
                dfs(grid, r, c-1, visited);
            if(isSafe(grid, r+1, c, visited) && canConnect(type, grid[r+1][c], 1, 0))
                dfs(grid, r+1, c, visited);
        }
        else if(type == 4) {
            if(isSafe(grid, r, c+1, visited) && canConnect(type, grid[r][c+1], 0, 1))
                dfs(grid, r, c+1, visited);
            if(isSafe(grid, r+1, c, visited) && canConnect(type, grid[r+1][c], 1, 0))
                dfs(grid, r+1, c, visited);
        }
        else if(type == 5) {
            if(isSafe(grid, r-1, c, visited) && canConnect(type, grid[r-1][c], -1, 0))
                dfs(grid, r-1, c, visited);
            if(isSafe(grid, r, c-1, visited) && canConnect(type, grid[r][c-1], 0, -1))
                dfs(grid, r, c-1, visited);
        }
        else {
            if(isSafe(grid, r-1, c, visited) && canConnect(type, grid[r-1][c], -1, 0))
                dfs(grid, r-1, c, visited);
            if(isSafe(grid, r, c+1, visited) && canConnect(type, grid[r][c+1], 0, 1))
                dfs(grid, r, c+1, visited);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(grid, 0, 0, visited);
        return visited[n - 1][m - 1];
    }
};