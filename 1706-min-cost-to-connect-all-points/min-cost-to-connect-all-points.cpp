struct Edge {
    int weight, src, dest;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x) {
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return;

        if(rank[x]<rank[y]) swap(x,y);
        parent[y]=x;

        if(rank[x]==rank[y])
            rank[x]++;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }

        sort(edges.begin(), edges.end(),
            [](Edge a, Edge b){
                return a.weight < b.weight;
            });

        DSU dsu(n);
        int ans = 0;
        int count = 0;

        for(auto &e : edges){
            if(dsu.find(e.src) != dsu.find(e.dest)){
                ans += e.weight;
                dsu.unite(e.src,e.dest);
                count++;
                if(count == n-1) break;
            }
        }

        return ans;
    }
};