class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            int temp = nums[i];
            if(temp < k) ++ans;
            for(int j = i + 1; j < n; ++j) {
                temp *= nums[j];
                if(temp < k) ++ans;
                else break;
            }
        }
        return ans;
    }
};