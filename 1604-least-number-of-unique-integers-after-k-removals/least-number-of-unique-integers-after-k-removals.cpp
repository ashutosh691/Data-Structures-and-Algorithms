class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<pair<int, int>> freq;
        unordered_map<int, int> mp;
        for(auto i : arr) mp[i]++;
        for(auto i : mp) freq.push_back(i);
        sort(freq.begin(), freq.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        int in = 0;
        for(auto i : freq) {
            if(i.second <= k) {
                k -= i.second;
                i.second = 0;
                in++;
            }
            else break;
        }
        return freq.size() - in;
    }
};