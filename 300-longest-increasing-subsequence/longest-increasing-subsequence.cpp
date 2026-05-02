class Solution {
public:
    vector<vector<int>> memo;
    int utils(vector<int>& nums, int n, int i) {
        if(i == 0) return 1;
        if(memo[n][i] != -1) return memo[n][i];
        int res = 1;
        for(int prev = 0; prev < i; ++prev) 
            if(nums[prev] < nums[i]) res = max(res, 1 + utils(nums, n, prev));
        return memo[n][i] = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        memo.resize(n + 1, vector<int>(n + 1, -1));
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 0; i < n; ++i) res = max(res, utils(nums, n, i));
        return res;
    }
};