class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n); dp[0] = nums[0];
        for(int i = 1; i < n; ++i) dp[i] = dp[i - 1] + nums[i];
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            int rem = (dp[i] % k + k) % k;
            if(rem == 0) ++ans;
            if(mp.count(rem)) ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};