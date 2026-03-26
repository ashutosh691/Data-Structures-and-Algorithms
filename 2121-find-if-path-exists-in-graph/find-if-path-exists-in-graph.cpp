class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &i : edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(destination == u) return true;
            if(visited[u]) continue;
            visited[u] = true;
            for(int i : adj[u])
                if(!visited[i]) 
                    q.push(i);
        }
        return false;
    }
};