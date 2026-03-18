class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i) {
            minTillNow = min(prices[i], minTillNow);
            ans = max(ans, prices[i] - minTillNow);
        }
        return ans;
    }
};
