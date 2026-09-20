class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; --i) ans += (i + 1) * (26 - (s[i] - 'a'));
        return ans;
    }
};