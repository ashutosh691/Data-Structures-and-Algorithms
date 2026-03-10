class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> mp;
        set<pair<int,int>> res;
        for(int i : nums) {
            if(mp.count(i + k))
                res.insert({min(i, i+k), max(i, i+k)});
            if(mp.count(i - k))
                res.insert({min(i, i-k), max(i, i-k)});
            mp.insert(i);
        }
        return res.size();
    }
};