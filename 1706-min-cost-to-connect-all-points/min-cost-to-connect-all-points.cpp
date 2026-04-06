struct Edges {
    int wt, src, dest;
};

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int i) {
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edges> edges;

        for(int i = 0; i < n; ++i) 
            for(int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }

        sort(edges.begin(), edges.end(), [](Edges a, Edges b){ return a.wt < b.wt; });
        DSU dsu(n);
        int ans = 0, count = 0;
        for(auto& e : edges) 
            if(dsu.find(e.src) != dsu.find(e.dest)) {
                ans += e.wt;
                dsu.unite(e.src, e.dest);
                count++;
                if(count == n - 1) break;
            }
        return ans;
    }
};