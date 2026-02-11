class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                bool found = true;
                for(int a = i, b = j; a < b; ++a, --b) {
                    if(s[a] != s[b]) {
                        found = false;
                        break;
                    }
                }
                if(found && j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};