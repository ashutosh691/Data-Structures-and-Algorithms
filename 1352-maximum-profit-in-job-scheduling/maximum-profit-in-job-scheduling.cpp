class Solution {
public:
    struct trio {
        int st, end, pro;
    };
    int findLast(vector<trio>& a, int i) {
        int st = 0, end = i - 1, ans = -1;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(a[mid].end <= a[i].st) {
                ans = mid;
                st = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
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
            int last = findLast(a, i), j = i - 1;
            if(last != -1) a[i].pro += dp[last];
            dp[i] = max(dp[i - 1], a[i].pro);
        }
        return dp[n - 1];
    }
};