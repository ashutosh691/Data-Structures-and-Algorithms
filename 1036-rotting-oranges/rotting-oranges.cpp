class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                if(grid[i][j] == 2) q.push({i, j});

        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            bool p = false;
            while(sz--) {
                auto [r, c] = q.front();
                q.pop();
                vector<int> dr = {-1, 0, 1, 0};
                vector<int> dc = {0, 1, 0, -1};
                for(int i = 0; i < 4; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if(isSafe(grid, nr, nc)) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        p = true;
                    }
                }
            }
            if(p) ++ans;
        }

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                if(grid[i][j] == 1) return -1;

        return ans;
    }
};