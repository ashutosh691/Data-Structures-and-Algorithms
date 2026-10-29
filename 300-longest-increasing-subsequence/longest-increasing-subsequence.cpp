class Solution {
public:
    vector<int> memo;
    int utils(vector<int>& nums, int n, int i) {
        if(!i) return 1;
        if(memo[i] != -1) return memo[i];
        int res = 1;
        for(int j = 0; j < i; ++j) if(nums[j] < nums[i]) res = max(res, 1 + utils(nums, n, j));
        return memo[i] = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        int res = 1;
        memo.resize(n + 1, -1);
        for(int i = 1; i < n; ++i) res = max(res, utils(nums, n, i));
        return res;
    }
};