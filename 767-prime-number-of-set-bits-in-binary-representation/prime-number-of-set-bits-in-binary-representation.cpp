class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        bool isPrime[33] = {};
        int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
        for(int p : primes)
            isPrime[p] = true;
        int ans = 0;
        for(int i = left; i <= right; ++i)
            if(isPrime[__builtin_popcount(i)])
                ans++;
        return ans;
    }
};