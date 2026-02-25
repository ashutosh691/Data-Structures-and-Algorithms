class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto i : arr) {
            int num = i;
            int c1 = 0;
            while(num) {
                if(num & 1) c1++;
                num = num >> 1;
            }
            pq.push({c1, i});
        }
        vector<int> res;
        while(!pq.empty()) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};