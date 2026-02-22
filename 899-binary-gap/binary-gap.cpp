class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while(n) {
            s = to_string(n & 1) + s;
            n = n >> 1;
        }
        int j = 0, ans = 0;
        while(j < s.size() && s[j] != '1') ++j;
        for(int i = j + 1; i < s.size(); ++i) {
            if(s[i] == '1') {
                ans = max(i - j, ans);
                j = i;
            }
        }
        return ans;
    }
};