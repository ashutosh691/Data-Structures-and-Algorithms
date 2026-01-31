class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int j = 0;
        double sum = 0.0;
        double ans = -DBL_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            if(i - j >= k) sum -= nums[j++];
            sum += nums[i];
            if(i - j == k - 1) ans = max(ans, sum / k);
        }
        return ans;
    }
};