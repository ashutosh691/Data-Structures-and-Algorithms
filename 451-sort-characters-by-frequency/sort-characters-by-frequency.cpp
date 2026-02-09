class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        string ans = "";
        for(auto ch : s) mp[ch]++;
        priority_queue<pair<int, char>> maxHeap;
        for(auto &it : mp)
            maxHeap.push({it.second, it.first});
        while(!maxHeap.empty())
        {
            auto[co, ch] = maxHeap.top();
            maxHeap.pop();
            ans+=string(co, ch);
        }

        return ans;
    }
};