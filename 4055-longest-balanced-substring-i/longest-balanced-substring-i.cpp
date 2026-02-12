class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            unordered_map<char,int> mp;
            for(int j = i; j < n; ++j) {
                mp[s[j]]++;
                int freq = mp.begin()->second;
                bool balanced = true;
                for(auto &p : mp) {
                    if(p.second != freq) {
                        balanced = false;
                        break;
                    }
                }
                if(balanced)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
