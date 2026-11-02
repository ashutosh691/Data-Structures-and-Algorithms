class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            ans += nums[i] - nums[0];
        }
        return ans;
    }
};