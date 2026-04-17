class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            if(mp.count(nums[i])) ans = min(ans, abs(i - mp[nums[i]]));
            mp[reverse(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};