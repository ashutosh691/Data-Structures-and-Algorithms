class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int src, vector<bool>& visited, int& c) {
        c++;
        visited[src] = true;
        for(auto i : rooms[src])
            if(!visited[i])
                dfs(rooms, i, visited, c);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v = rooms.size(), c = 0;
        vector<bool> visited(v, false);
        dfs(rooms, 0, visited, c);
        return c == v;
    }
};