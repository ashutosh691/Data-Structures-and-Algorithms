class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        for(int i = 1; i < n; ++i) ans[i] = ans[i - 1] + nums[i];
        int rsum = 0;
        for(int i = n - 1; i >= 0; --i) {
            rsum += nums[i];
            ans[i] = abs(ans[i] - rsum);
        }
        return ans;
    }
};