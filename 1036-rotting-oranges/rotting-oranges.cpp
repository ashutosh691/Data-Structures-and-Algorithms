class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        return x < n && x >= 0 && y < m && y >= 0 && grid[x][y] == 1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 2) q.push({i, j});

        int ans = 0;
        vector<int> dr = {0, -1, 0, 1}, dc = {1, 0, -1, 0};

        while(!q.empty()) {
            int sz = q.size();
            bool pushed = false;

            while(sz--) {
                auto [a, b] = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i) {
                    int nr = a + dr[i], nc = b + dc[i];

                    if(isSafe(grid, nr, nc)) {
                        pushed = true;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
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