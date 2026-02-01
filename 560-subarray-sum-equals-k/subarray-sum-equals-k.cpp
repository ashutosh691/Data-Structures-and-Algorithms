class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n); dp[0] = nums[0];
        for(int i = 1; i < n; ++i) dp[i] = dp[i - 1] + nums[i];
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            if(dp[i] == k) ++ans;
            int val = dp[i] - k;
            if(mp.count(val)) ans += mp[val];
            mp[dp[i]]++;
        }
        return ans;
    }
};