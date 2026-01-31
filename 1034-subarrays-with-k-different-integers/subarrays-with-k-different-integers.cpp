class Solution {
public:
    int atMax(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int j = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
            while(mp.size() > k) {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) mp.erase(mp.find(nums[j]));
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMax(nums, k) - atMax(nums, k - 1);
    }
};