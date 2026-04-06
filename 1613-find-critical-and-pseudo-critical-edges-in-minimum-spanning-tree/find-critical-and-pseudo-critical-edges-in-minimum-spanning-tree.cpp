class Solution {
public:
    struct Edge {
        int wt, src, dest, idx;
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

        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if(x == y) return false;
            if(rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
            return true;
        }
    };

    int kruskal(vector<Edge>& edg, int n, int skip = -1, int force = -1) {
        DSU dsu(n);
        int ans = 0, count = 0;

        if(force != -1) {
            auto &e = edg[force];
            if(dsu.unite(e.src, e.dest)) {
                ans += e.wt;
                count++;
            }
        }

        for(int i = 0; i < edg.size(); ++i) {
            if(i == skip) continue;

            auto &e = edg[i];
            if(dsu.unite(e.src, e.dest)) {
                ans += e.wt;
                count++;
                if(count == n - 1) break;
            }
        }

        if(count != n - 1) return INT_MAX; 
        return ans;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> edg;

        for(int i = 0; i < edges.size(); ++i) {
            edg.push_back({edges[i][2], edges[i][0], edges[i][1], i});
        }

        sort(edg.begin(), edg.end(), [](Edge &a, Edge &b){
            return a.wt < b.wt;
        });

        int base = kruskal(edg, n);

        vector<int> critical, pseudo;

        for(int i = 0; i < edg.size(); ++i) {

            if(kruskal(edg, n, i, -1) > base) 
                critical.push_back(edg[i].idx);
            
            else if(kruskal(edg, n, -1, i) == base) 
                pseudo.push_back(edg[i].idx);
            
        }

        return {critical, pseudo};
    }
};