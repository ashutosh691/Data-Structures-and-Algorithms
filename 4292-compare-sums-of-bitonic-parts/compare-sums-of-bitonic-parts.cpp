class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        long long asc = nums[0], desc = 0, i;
        for(i = 1; i < n; ++i) {
            if(nums[i] < nums[i - 1]) break;
            asc += nums[i];
        }
        desc = nums[i - 1];
        while(i < n) desc += nums[i++];
        return asc > desc ? 0 : asc < desc ? 1 : -1;
    }
};