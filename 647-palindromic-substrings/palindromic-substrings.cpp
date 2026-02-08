class Solution {
public:
    void sub(string &s, int start, int end, int &res) {
        if (start == s.size()) return;
        if (end == s.size()) {
            sub(s, start + 1, start + 1, res);
            return;
        }
        if(isPalindrome(s, start, end)) res++;
        sub(s, start, end + 1, res);
    }

    bool isPalindrome(string &s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        sub(s, 0, 0, res);
        return res;
    }
};