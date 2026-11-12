class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int c1 = 1, c2 = 1, n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i - 1]) c1++;
            else c1 = 1;
            if(nums[i] < nums[i - 1]) c2++;
            else c2 = 1;
            ans = max(c1, max(ans, c2));
        }
        return ans;
    }
};