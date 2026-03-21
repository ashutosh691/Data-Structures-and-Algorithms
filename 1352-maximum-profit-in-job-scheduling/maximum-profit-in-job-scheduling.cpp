class Solution {
public:
    struct trio {
        int st, end, pro;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n);
        vector<trio> a(n);
        for(int i = 0; i < n; ++i) {
            a[i].st = startTime[i];
            a[i].end = endTime[i];
            a[i].pro = profit[i];
        }
        sort(a.begin(), a.end(), [](trio a, trio b) { return a.end < b.end; });
        dp[0] = a[0].pro;
        for(int i = 1; i < n; ++i) {
            int last = -1, j = i - 1;
            while(j >= 0) {
                if(a[j].end <= a[i].st) {
                    last = j;
                    break;
                }
                --j;
            }
            if(last != -1) a[i].pro += dp[last];
            dp[i] = max(dp[i - 1], a[i].pro);
        }
        return dp[n - 1];
    }
};