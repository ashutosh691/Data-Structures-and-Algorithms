class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int shift = 5e4;
        int mx = 0;
        for(auto& i : nums) {
            i += shift;
            mx = max(mx, i);
        }
        vector<int> cf(mx + 1, 0);
        for(int i = 0; i < n; ++i) cf[nums[i]]++;
        for(int i = 1; i <= mx; ++i) cf[i] += cf[i - 1];
        vector<int> res(n);
        for(int i = n - 1; i >= 0; --i)
            res[--cf[nums[i]]] = nums[i] - shift;
        return res;
    }
};