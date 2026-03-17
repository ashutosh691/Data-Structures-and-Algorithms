class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i : coins) 
            for(int j = i; j <= amount; ++j) 
                dp[j] = min(dp[j], dp[j - i] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};