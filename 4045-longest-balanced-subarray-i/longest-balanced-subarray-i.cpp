class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int ne = 0, no = 0;
            unordered_set<int> mp;
            for(int j = i; j < n; ++j) {
                if(nums[j] % 2 == 0 && !mp.count(nums[j])) ne++;
                else if(!mp.count(nums[j])) no++;
                if(ne == no) ans = max(ans, j - i + 1);
                mp.insert(nums[j]);
            }
        }
        return ans;
    }
};