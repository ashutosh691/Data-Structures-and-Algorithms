class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0;
        int maxl = 0;
        for(auto ch : s) {
            if(ch == '(') l ++;
            else r ++;
            if(l == r) maxl = max(maxl, 2 * l);
            else if(r > l) l = r = 0;
        }
        l = r = 0;
        for(int i = s.size() - 1; i >=0 ; --i) {
            if(s[i] == '(') l ++;
            else r ++;
            if(l == r) maxl = max(maxl, 2 * l);
            else if(r < l) l = r = 0;
        }
        return maxl;
    }
};