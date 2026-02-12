class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum = accumulate(weights.begin(), weights.end(), 0LL);
        int st = *max_element(weights.begin(), weights.end()), end = sum, ans = INT_MAX;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            int daysNeeded = 1, currentLoad = 0;

            for(int w : weights) {
                if(currentLoad + w > mid) {
                    daysNeeded++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }
            if(daysNeeded <= days) {
                ans = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        return ans;
    }
};