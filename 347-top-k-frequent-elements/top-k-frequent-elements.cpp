class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        vector<int> res;
        while(k--) {
            int mx = INT_MIN, mxfreq = mx;
            for(auto i : mp) if(i.second > mxfreq) mx = i.first, mxfreq = i.second;
            res.push_back(mx);
            mp.erase(mp.find(mx));
        }
        return res;
    }
};