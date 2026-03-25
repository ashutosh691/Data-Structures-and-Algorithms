using ll = long long;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        ll total = 0;
        for(auto &row : grid)
            for(auto &x : row)
                total += x;

        ll curr = 0;
        for(int i = 0; i < r - 1; ++i) {
            curr += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if(curr == total - curr) return true;
        }

        vector<ll> colSum(c, 0);
        for(int j = 0; j < c; ++j)
            for(int i = 0; i < r; ++i)
                colSum[j] += grid[i][j];
\
        curr = 0;
        for(int j = 0; j < c - 1; ++j) {
            curr += colSum[j];
            if(curr == total - curr) return true;
        }

        return false;
    }
};