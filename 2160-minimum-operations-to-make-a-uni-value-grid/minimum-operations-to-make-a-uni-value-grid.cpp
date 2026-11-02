class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto i : grid)
            for(auto j : i) nums.push_back(j);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = nums.size() / 2;
        if(n == 1) return 0;
        int ans = 0;
        for(int i : nums) {
            int diff = abs(nums[m] - i);
            if(diff % x) return -1;
            ans += (diff / x);
        }
        return ans;
    }
};