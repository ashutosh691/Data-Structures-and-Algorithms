class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long mx = 0, mn = LLONG_MIN;
        for(auto i : nums) mx += i, mn = max(i * 1LL, mn);
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