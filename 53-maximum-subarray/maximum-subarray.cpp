class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        int maxTillNow = INT_MIN, curr = 0;
        for(auto i : nums) {
            curr += i;
            maxTillNow = max(maxTillNow, curr);
            if(curr < 0) curr = 0;
        }
        return maxTillNow;
    }
};