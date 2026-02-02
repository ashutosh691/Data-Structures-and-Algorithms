class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, minProd = 1, maxProd = 1;
        for(int i = 0; i < nums.size(); ++i) {
            int temp = max(nums[i], max(nums[i] * maxProd, nums[i] * minProd));
            minProd = min(nums[i], min(nums[i] * maxProd, nums[i] * minProd));
            maxProd = temp;
            ans = max(maxProd, ans);
        }
        return ans;
    }
};