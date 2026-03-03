class Solution {
public:
    string reverse(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) swap(s[i++], s[j--]);
        return s;
    }

    string invert(string s) {
        for(int i = 0; i < s.size(); ++i) s[i] = (s[i] == '0' ? '1' : '0');
        return s;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n--) 
            s = s + "1" + reverse(invert(s));
        return s[k - 1];
    }
};