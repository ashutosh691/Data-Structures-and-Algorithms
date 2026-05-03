class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins)
            for (int a = c; a <= amount; a++) {
                dp[a] += dp[a - c];
                dp[a] = min(dp[a], (long long)INT_MAX + 1); 
            }
        return (int)dp[amount];
    }
};