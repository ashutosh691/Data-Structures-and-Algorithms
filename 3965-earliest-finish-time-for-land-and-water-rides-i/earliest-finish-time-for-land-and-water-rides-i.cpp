class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landDuration.size(), m = waterDuration.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int t = landStartTime[i] + landDuration[i];
            for(int j = 0; j < m; ++j) {
                int x = t;
                if(waterStartTime[j] <= x) x += waterDuration[j];
                else x = waterStartTime[j] + waterDuration[j];
                ans = min(ans, x);
            }
        }
        for(int i = 0; i < m; ++i) {
            int t = waterStartTime[i] + waterDuration[i];
            for(int j = 0; j < n; ++j) {
                int x = t;
                if(landStartTime[j] <= t) x += landDuration[j];
                else x = landStartTime[j] + landDuration[j];
                ans = min(ans, x);
            }
        }
        return ans;
    }
};