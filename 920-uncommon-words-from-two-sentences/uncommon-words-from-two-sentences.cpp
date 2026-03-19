class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        string word;
        stringstream ss1(s1), ss2(s2);
        while(ss1 >> word) freq[word]++;
        while(ss2 >> word) freq[word]++;
        vector<string> ans;
        for(auto &p : freq) 
            if(p.second == 1) ans.push_back(p.first);
        return ans;
    }
};