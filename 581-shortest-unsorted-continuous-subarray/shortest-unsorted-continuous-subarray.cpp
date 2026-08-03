class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), l = -1, r = -1;
        int maxi = nums[0], mini = nums[n - 1];
        for(int i = 0; i < n; ++i) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[n - i - 1]);
            if(maxi > nums[i]) r = i;
            if(mini < nums[n - i - 1]) l = n - i - 1;
        }
        if(l == -1) return 0;
        return r - l + 1;
    }
};