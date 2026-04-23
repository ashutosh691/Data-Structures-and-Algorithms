class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; ++i) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());
        int ans = 1e9;
        int c = 1;
        for(int i = 1; i < n; ++i) {
            if(arr[i].first == arr[i - 1].first) {
                c++;
                if(c >= 3) {
                    ans = min(ans, abs(arr[i].second - arr[i - 1].second) + abs(arr[i].second - arr[i - 2].second) + abs(arr[i - 2].second - arr[i - 1].second));
                }
            }
            else c = 1;
        }
        return ans == 1e9 ? -1 : ans;
    }
};