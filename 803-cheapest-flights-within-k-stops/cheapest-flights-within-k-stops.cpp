class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : flights) 
            adj[e[0]].push_back({e[1], e[2]});
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<int> stopsUsed(n, INT_MAX);
        pq.push({0, src, 0});
        while(!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();
            if(node == dst) return cost;
            if(stops > k || stops > stopsUsed[node]) continue;
            stopsUsed[node] = stops;
            for(auto &nbr : adj[node]) {
                int next = nbr.first;
                int price = nbr.second;
                pq.push({cost + price, next, stops + 1});
            }
        }
        return -1;
    }
};