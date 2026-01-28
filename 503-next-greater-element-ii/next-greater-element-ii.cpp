class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            bool found = false;
            int j = i + 1;
            if(j == n) j = 0;
            while(j != i) {
                if(nums[j] > nums[i]) {
                    found = true;
                    res.push_back(nums[j]);
                    break;
                }
                j = (j + 1) % n;
            }
            if(!found) res.push_back(-1);
        }
        return res;
    }
};