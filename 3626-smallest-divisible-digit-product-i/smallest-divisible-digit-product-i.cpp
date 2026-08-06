class Solution {
public:
    bool isP(int n, int t) {
        long long ans = 1;
        while(n) {
            ans *= (n % 10);
            n /= 10;
        }
        return (ans % t) == 0;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(i < 1e9) 
            if(isP(i++, t)) return i - 1;
        return -1;
    }
};