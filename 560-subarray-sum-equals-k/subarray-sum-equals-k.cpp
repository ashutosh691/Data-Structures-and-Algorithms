class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            if(prefix[i] == k) ans ++;
            int val = prefix[i] - k;
            if(mp.find(val) != mp.end()) ans += mp[val];
            mp[prefix[i]] ++;
        }
        return ans;
    }
};
