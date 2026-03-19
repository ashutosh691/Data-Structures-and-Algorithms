class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1, mp2;
        stringstream ss1(s1), ss2(s2);
        string words;
        while(ss1 >> words) mp1[words]++;
        while(ss2 >> words) mp2[words]++;
        unordered_set<string> st;
        for(auto i : mp1) if(i.second == 1 && !mp2.count(i.first)) st.insert(i.first);
        for(auto i : mp2) if(i.second == 1 && !mp1.count(i.first)) st.insert(i.first);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};