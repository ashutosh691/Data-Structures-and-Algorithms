class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i : nums) {
            if(mp.count(i) && mp[i] == 1) {
                res.emplace_back(i);
            }
            mp[i]++;
        }
        return res;
    }
};