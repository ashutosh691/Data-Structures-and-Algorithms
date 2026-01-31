class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, ans = 0, zeroCount = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) zeroCount++;
            while(zeroCount > k) {
                if(nums[j] == 0) zeroCount--;
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};