class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int l = 0, r = 0, count = t.size(), dis = INT_MAX, st = 0;
        unordered_map<char, int> mp;
        for(auto i : t) mp[i]++;
        while(r < s.size()) {
            if(mp[s[r++]]-- > 0) count--;
            while(count == 0) {
                if(r - l < dis) {
                    dis = r - l;
                    st = l;
                }
                if(mp[s[l++]]++ == 0) count++;
            }
        }
        return dis == INT_MAX ? "" : s.substr(st, dis);
    }
};