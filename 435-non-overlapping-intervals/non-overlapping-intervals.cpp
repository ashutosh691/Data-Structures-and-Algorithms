class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1], n = intervals.size(), ans = 0;;
        for(int i = 1; i < n; ++i) {
            if(intervals[i][0] < end) {
                end = min(end, intervals[i][1]);
                ans++;
            }
            else end = intervals[i][1];
        }
        return ans;
    }
};