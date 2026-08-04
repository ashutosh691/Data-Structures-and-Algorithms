class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for(char c : s) mp[c]++;
        string half = "",  middle = "";
        for(auto &p : mp) {
            char ch = p.first;
            int freq = p.second;
            if(freq % 2 == 1) {
                if(middle != "") return ""; 
                middle += ch;
            }
            half += string(freq / 2, ch);
        }
        string rev = half;
        reverse(rev.begin(), rev.end());
        return half + middle + rev;
    }
};