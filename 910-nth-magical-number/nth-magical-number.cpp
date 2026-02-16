class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        if(a == b) return (1LL * n * a) % MOD; 
        if(a % b == 0 || b % a == 0) return (n * min(a, b)) % MOD;
        long long start = 1, end = 1LL * n * min(a, b);
        long long l = lcm(a, b);
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            long long c = mid / a + mid / b - mid / l;
            if(c < n) start = mid + 1;
            else end = mid - 1;
        }
        return start % MOD;
    }
};