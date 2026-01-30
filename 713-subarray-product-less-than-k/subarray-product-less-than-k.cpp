class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0, n = nums.size(), p = 1;
        int j = 0;
        for(int i = 0; i < n; ++i) {
            p *= nums[i];
            while(p >= k) p /= nums[j++];
            ans += i - j + 1;
        }
        return ans;
    }
};