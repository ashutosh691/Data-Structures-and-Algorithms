class Solution {
public:
    struct Edge {
        int wt, src, dest;
    };

    class DSU {
        vector<int> parent, rank;
        public:
        DSU(int n) {
            parent.resize(n);
            for(int i = 0; i < n; ++i) parent[i] = i;
            rank.resize(n, 0);
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

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> adj;
        int n = points.size();
        for(int i = 0; i < n - 1; ++i) 
            for(int j = i + 1; j < n; ++j) 
                adj.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});   
        int ans = 0, c = 0;
        DSU dsu(n);
        sort(adj.begin(), adj.end(), [](Edge& a, Edge& b) {
            return a.wt < b.wt;
        });
        for(auto& i : adj) {
            if(dsu.find(i.src) != dsu.find(i.dest)) {
                ans += i.wt;
                dsu.unite(i.src, i.dest);
                ++c;
            }
            if(c == n - 1) return ans;
        }
        return ans;
    }
};