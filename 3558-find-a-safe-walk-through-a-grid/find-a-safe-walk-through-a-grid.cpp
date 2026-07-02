class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        queue<tuple<int, int, int>> q;  //x, y, health
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, 0));    
        if(grid[0][0]) --health;
        best[0][0] = health;
        q.push({0, 0, health});
        while(!q.empty()) {
            auto [x, y, h] = q.front();
            q.pop();
            if(h < 1) continue;
            for(int k = 0; k < 4; ++k) {
                int xr = dx[k] + x, yr = dy[k] + y;
                if(xr >= 0 && xr < n && yr >= 0 && yr < m) {
                    int temp = h + (grid[xr][yr] == 0 ? 0 : -1);
                    if(temp < 1) continue;
                    if(best[xr][yr] >= temp) continue;
                    if(xr == n - 1 && yr == m - 1) return true;
                    q.push({xr, yr, temp});
                    best[xr][yr] = temp;
                }
            }
        }
        return false;
    }
};