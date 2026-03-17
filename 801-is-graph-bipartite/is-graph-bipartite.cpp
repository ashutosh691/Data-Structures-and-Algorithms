class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if(xr == yr) return;
        if(rank[xr] < rank[yr]) swap(xr, yr);
        parent[yr] = xr;
        if(rank[xr] == rank[yr]) rank[xr]++;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        DSU dsu(n);
        for(int i = 0; i < n; ++i) {
            for(int j : graph[i]) {
                if(dsu.find(i) == dsu.find(j)) return false;
                dsu.unite(graph[i][0], j);
            }
        }
        return true;
    }
};