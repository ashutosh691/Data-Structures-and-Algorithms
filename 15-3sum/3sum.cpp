class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int a = nums[i];
            int j = i + 1, k = n - 1;
            while(j < k) {
                int b = nums[j];
                int c = nums[k];
                if(a + b + c == 0) {
                    res.push_back({a, b, c});
                    ++j;
                    --k;
                    while(j < k && nums[j] == nums[j - 1]) ++j;
                }
                else if(a + b + c > 0) k--;
                else j++;
            }
        }
        return res;
    }
};