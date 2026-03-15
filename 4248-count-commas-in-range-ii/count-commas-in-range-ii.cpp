class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, start = 1000, comm = 1;
        while(start <= n) {
            long long end = start * 1000 - 1, cnt = max(0LL, min(n, end) - start + 1);
            ans += cnt * comm;
            start *= 1000;
            comm++;
        }
        return ans;
    }
};