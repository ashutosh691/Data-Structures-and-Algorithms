class Solution {
public:
    int bs(vector<int>& nums, int key) {
        int l = 0, h = nums.size() - 1, ans = -1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(nums[m] >= key) ans = m, l = m + 1;
            else h = m - 1;
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN, n = nums1.size();
        for(int i = 0; i < n; ++i) {
            int ni = bs(nums2, nums1[i]);
            if(ni != -1) ans = max(ans, ni - i);
        }
        return ans == INT_MIN || ans < 0 ? 0 : ans;
    }
};