class Solution {
public:
    vector<int> dp;
    int utils(vector<int>& nums, int i, int n) {
        if(i >= n) return 1e9;
        if(i == n - 1) return 0;
        if(dp[i] != -1) return dp[i];
        if(!nums[i]) return dp[i] = 1e9;
        int ans = 1e9;
        for(int k = 1; k <= nums[i]; ++k) 
            ans = min(ans, 1 + utils(nums, i + k, n));
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        utils(nums, 0, n);
        return dp[0] == -1 ? 0 : dp[0];
    }
};