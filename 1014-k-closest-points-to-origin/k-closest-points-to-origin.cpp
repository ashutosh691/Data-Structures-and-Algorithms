class Solution {
public:
    inline double distance(int x, int y) { return sqrt((double)x * x + (double)y * y); }  
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i = 0; i < points.size(); ++i) {
            pq.push({distance(points[i][0], points[i][1]), {points[i][0], points[i][1]}});
            if(pq.size() > k) pq.pop();
        }
        while(k--) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};