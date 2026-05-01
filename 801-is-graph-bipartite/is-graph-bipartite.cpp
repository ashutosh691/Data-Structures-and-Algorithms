class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<int> color(n, -1);
        for(int st = 0; st < n; ++st) {
            if(color[st] != -1) continue;
            q.push(st);
            color[st] = 0;
            while(!q.empty()) {
                int i = q.front();
                q.pop();
                for(auto j : graph[i]) {
                    if(color[j] == -1) {
                        color[j] = !color[i];
                        q.push(j);
                    }
                    else if(color[i] == color[j]) return false;
                }
            }
        }
        return true;
    }
};