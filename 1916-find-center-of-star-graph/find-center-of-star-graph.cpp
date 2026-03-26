class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> freq(n + 1, 0);
        for(auto &i : edges) {
            freq[i[0]]++;
            freq[i[1]]++;
        }
        for(int i = 1; i <= n; ++i) if(freq[i] == n - 1) return i;
        return -1;
    }
};