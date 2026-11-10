class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);  // step 0 is free, step i costs costs[i]
        vector<int> dp(n + 3, INT_MAX / 2);  // dp[i] = climb(i), the two steps past the top stay inf
        dp[n] = costs[n];
        for (int i = n - 1; i >= 0; --i)  // from the top step down
            dp[i] = costs[i] + min({dp[i + 1] + 1, dp[i + 2] + 4, dp[i + 3] + 9});
        return dp[0];
    }
};