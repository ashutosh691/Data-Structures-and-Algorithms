class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size();
        vector<char> ss;
        int maxLen = 0;

        for (int i = 0; i < l; ++i) {
            bool isd = false;
            for (int j = 0; j < ss.size(); ++j) {
                if (s[i] == ss[j]) {
                    ss.erase(ss.begin(), ss.begin() + j + 1); 
                    isd = true;
                    break;
                }
            }
            ss.push_back(s[i]);
            if (!isd || ss.size() == 1)
                maxLen = max(maxLen, (int)ss.size());
        }

        return maxLen;
    }
};