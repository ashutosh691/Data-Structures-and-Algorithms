class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size(), m = grid[0].size();
        return (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};
        queue<pair<int, int>> q;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 2) q.push({i, j});

        while(!q.empty()) {
            int sz = q.size();
            bool pushed = false;
            while(sz--) {
                auto u = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    int nr = u.first + dr[i];
                    int nc = u.second + dc[i];
                    if(isSafe(grid, nr, nc)) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        pushed = true;
                    }
                }
            }
            if(pushed) ++ans;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 1) return -1;

        return ans;
    }
};