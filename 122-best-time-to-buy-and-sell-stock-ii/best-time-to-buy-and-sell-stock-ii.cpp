class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), mtn = nums[0], Mtn = nums[0], p = 0;
        for(int i = 1; i < n; ++i) 
            if(nums[i] > nums[i - 1])
                p += nums[i] - nums[i - 1]; 
        return p;
    }
};