class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 0;
        for(auto &i : edges) n = max(n, max(i[0], i[1]));
        vector<vector<int>> adj(n + 1);
        for(auto &i : edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        for(int i = 1; i <= n; ++i) if(adj[i].size() == n - 1) return i;
        return -1;
    }
};