class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = apples.size(), day = 0, ans = 0;
        while(day < n || !pq.empty()) {
            if(day < n && apples[day] != 0) pq.push({day + days[day], apples[day]});
            while(!pq.empty() && pq.top().first <= day) pq.pop();
            if(!pq.empty()) {
                auto pair = pq.top();
                pq.pop();
                ans++;
                pair.second--;
                if(pair.second > 0) pq.push(pair);
            }
            ++day;
        }
        return ans;
    }
};