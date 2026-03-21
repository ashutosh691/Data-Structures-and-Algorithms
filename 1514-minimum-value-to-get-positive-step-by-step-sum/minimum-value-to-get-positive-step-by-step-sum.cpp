class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minPsum = 0, pSum = 0;
        for(int i : nums)
            pSum += i, minPsum = min(minPsum, pSum);
        return 1 - minPsum;
    }
};