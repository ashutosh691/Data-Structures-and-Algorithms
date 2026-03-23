class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& i : prerequisites) 
            adj[i[0]].emplace_back(i[1]);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> res;
        for(auto& i : adj)
            for(auto j : i)
                indegree[j]++;
        for(int i = 0; i < numCourses; ++i) if(indegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            res.emplace_back(u);
            for(int i : adj[u]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        reverse(res.begin(), res.end());
        if(res.size() == numCourses) return res;
        return {};
    }
};