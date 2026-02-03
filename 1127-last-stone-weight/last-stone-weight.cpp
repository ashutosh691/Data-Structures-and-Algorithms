class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones) pq.push(i);
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            int y = pq.top();
            pq.pop();
            if(x == y) continue;
            pq.push(x - y);
        }
        return 0;
    }
};