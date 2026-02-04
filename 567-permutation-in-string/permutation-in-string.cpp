class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int left = 0, right = 0, n = s2.size();
        unordered_map<int, int> mp;
        for(auto i : s1) mp[i]++;
        while(right < n) {
            mp[s2[right]]--;
            while(mp[s2[right]] < 0) {
                mp[s2[left]]++;
                left++;
            }
            if(right - left + 1 == s1.size()) return true;
            ++right;
        }
        return false;
    }
};