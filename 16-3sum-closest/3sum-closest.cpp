class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        int diff = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            int a = nums[i];
            while(j < k) {
                int b = nums[j];
                int c = nums[k];
                int sum = a + b + c;
                if(abs(target - sum) < diff) {
                    ans = sum;
                    diff = abs(target - sum);
                }
                if(sum > target) --k;
                else ++j;
            }
        }
        return ans;
    }
};