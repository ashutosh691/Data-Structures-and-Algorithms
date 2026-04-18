class Solution {
public:
    int mirrorDistance(int n) {
        int t = n, r = 0;
        while(t) {
            r = r * 10 + (t % 10);
            t /= 10;
        }
        return abs(n - r);
    }
};