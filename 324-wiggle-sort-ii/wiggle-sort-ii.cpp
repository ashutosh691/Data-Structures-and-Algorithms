class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 1) return;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = 1, k = n - 1; vector<int> res(n);
        while(j < n) {
            res[j] = nums[k--];
            j += 2;
        }
        j = 0;
        while(j < n) {
            res[j] = nums[k--];
            j += 2;
        }
        nums = res;
    }
};