class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& piles, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int left = piles[i] - solve(piles, i + 1, j);
        int right = piles[j] - solve(piles, i, j - 1);
        return dp[i][j] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(piles, 0, n - 1) > 0;
    }
};