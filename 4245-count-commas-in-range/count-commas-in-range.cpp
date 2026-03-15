class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i = 1000; i <= n; ++i) {
            if(i >= 1e9) ans += 3;
            else if(i >= 1e6) ans += 2;
            else ans++;
        }
        return ans;
    }
};