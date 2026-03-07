class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long mx = accumulate(nums.begin(), nums.end(), 1LL), mn = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(mn <= mx) {
            long long mid = mn + (mx - mn) / 2, temp = 1, sum = 0;
            for(auto i : nums) {
                sum += i;
                if(sum > mid) {
                    sum = i;
                    temp++;
                }
            }
            if(temp <= k) {
                ans = mid;
                mx = mid - 1;
            }
            else mn = mid + 1;
        }
        return ans;
    }
};