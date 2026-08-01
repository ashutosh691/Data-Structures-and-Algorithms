class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, l = n - 1;
                while(k < l) {
                    long long temp = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if(temp == target) { 
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k, --l;
                        while(k < l && nums[k] == nums[k - 1]) ++k;
                    }
                    else if(temp > target) --l;
                    else ++k;
                } 
            }
        }
        return res;
    }
};