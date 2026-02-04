class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0, n = s.size();
        unordered_map<int, int> mp;
        for(auto i : p) mp[i]++;
        vector<int> ans;
        while(right < n) {
            mp[s[right]]--;
            while(mp[s[right]] < 0) {
                mp[s[left]]++;
                left++;
            }
            if(right - left + 1 == p.size()) ans.push_back(left);
            ++right;
        }
        return ans;
    }
};