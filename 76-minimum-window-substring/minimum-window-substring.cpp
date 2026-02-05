class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        string ans = "";
        unordered_map<char, int> mp;
        for(auto i : t) mp[i]++;
        int left = 0, right = 0, counter = t.size(), dist = INT_MAX, start = 0;
        while(right < s.size()) {
            if(mp[s[right++]]-- > 0) counter--;
            while(counter == 0) {
                if(right - left < dist) {
                    start = left;
                    dist = right - left;
                }
                if(mp[s[left++]]++ == 0) counter++;
            }
        }
        return dist == INT_MAX ? "" : s.substr(start, dist);
    }
};