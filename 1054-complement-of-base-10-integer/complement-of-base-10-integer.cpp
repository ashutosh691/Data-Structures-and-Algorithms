class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0, p = 0;
        if(n == 0) return 1;
        while(n) {
            if((n & 1) == 0) ans += pow(2, p);
            n = n >> 1;
            p++;
        }
        return ans;
    }
};