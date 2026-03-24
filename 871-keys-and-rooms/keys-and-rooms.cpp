class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int src, vector<bool>& visited) {
        visited[src] = true;
        for(auto i : rooms[src])
            if(!visited[i])
                dfs(rooms, i, visited);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v = rooms.size(), c = 0;
        vector<int> indegree(v, 0);
        vector<bool> visited(v, false);
        dfs(rooms, 0, visited);
        for(auto i : visited) if(!i) return false;
        return true;
    }
};