class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), mtn = nums[0], Mtn = nums[0], p = 0;
        for(int i = 1; i < n; ++i) {
            if(nums[i] < Mtn || i == n - 1) {
                Mtn = max(Mtn, nums[i]);
                p += (Mtn - mtn);
                Mtn = nums[i];
                mtn = nums[i];
            }
            else Mtn = nums[i];
        }
        return p;
    }
};