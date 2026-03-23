class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& i : prerequisites) 
            adj[i[0]].emplace_back(i[1]);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int c = 0;
        for(auto& i : adj)
            for(auto j : i)
                indegree[j]++;
        for(int i = 0; i < numCourses; ++i) if(indegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ++c;
            for(int i : adj[u]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return c == numCourses;
    }
};