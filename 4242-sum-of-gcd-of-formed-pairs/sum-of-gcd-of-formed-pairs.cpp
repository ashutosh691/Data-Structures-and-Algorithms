class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n, INT_MIN), prefixGcd(n);
        mx[0] = nums[0];
        for(int i = 1; i < n; ++i) mx[i] = max(nums[i], mx[i - 1]);
        for(int i = 0; i < n; ++i) prefixGcd[i] = __gcd(nums[i], mx[i]);
        long long ans = 0;
        int i = 0, j = n - 1;
        sort(prefixGcd.rbegin(), prefixGcd.rend());
        while(i < j) ans += __gcd(prefixGcd[i++], prefixGcd[j--]);
        return ans;
    }
};