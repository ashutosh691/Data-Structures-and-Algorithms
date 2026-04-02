class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> mp;
            for(int j = i; j < i + k; ++j) {
                mp[nums[j]]++;
            }
            vector<pair<int, int>> freq;
            for(auto &[a, b] : mp) freq.emplace_back(b, a);
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());
            int xsum = 0;
            for (int j = 0; j < x && j < freq.size(); ++j) 
                xsum += freq[j].first * freq[j].second;
            ans.push_back(xsum);
        }
        return ans;
    }
};