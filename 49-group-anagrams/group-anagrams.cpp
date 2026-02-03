class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        for (auto& s : strs) {
            string s_sort = s;
            sort(s_sort.begin(), s_sort.end());
            mp[s_sort].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& pairs : mp) {
            res.push_back(pairs.second);
        }
        return res;
    }
};