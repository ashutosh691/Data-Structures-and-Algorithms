class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ssum = 1, n = nums.size();
        while(true) {
            bool all = true;
            int temp = ssum;
            for(int i = 0; i < n; ++i) {
                temp += nums[i];
                if(temp <= 0) {
                    all = false;
                    break;
                }
            }
            if(all) return ssum;
            ssum++;
        }
        return -1;
    }
};