class Solution {
public:
    bool checkOnesSegment(string s) {
        return s[0] == '1' && s.find("01") == string::npos;
    }
};