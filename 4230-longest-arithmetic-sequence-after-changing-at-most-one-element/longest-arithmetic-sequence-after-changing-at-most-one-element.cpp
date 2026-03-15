class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 2), right(n, 2);
        for(int i = 2; i < n; ++i) 
            if(nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1])
                left[i] = left[i - 1] + 1;
        for(int i = n - 3; i >= 0; --i)
            if(nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i])
                right[i] = right[i + 1] + 1;
        int ans = 2;
        for(int i : left) ans = max(ans, i);
        for(int i = 1; i < n - 1; ++i) {
            if((nums[i + 1] - nums[i - 1]) % 2 == 0) {
                int d = (nums[i + 1] - nums[i - 1]) / 2;
                int l = 1, r = 1;
                if(i >= 2 && nums[i - 1] - nums[i - 2] == d) l = left[i - 1];
                if(i + 2 < n && nums[i + 2] - nums[i + 1] == d) r = right[i + 1];
                ans = max(ans, l + r + 1);
            }
            ans = max(ans, left[i - 1] + 1);
            ans = max(ans, right[i + 1] + 1);
        }
        ans = max(ans, left[n - 2] + 1);
        ans = max(ans, right[1] + 1);
        return ans;
    }
};