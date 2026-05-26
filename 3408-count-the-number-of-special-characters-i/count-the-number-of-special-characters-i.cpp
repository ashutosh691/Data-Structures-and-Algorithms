class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> s1, s2;
        int c = 0;
        for(auto i : word) if(i >= 'a' && i <= 'z') s1.insert({i}); else s2.insert({i});
        for(auto i : s1) if(s2.count(toupper(i))) c++;
        return c;
    }
};