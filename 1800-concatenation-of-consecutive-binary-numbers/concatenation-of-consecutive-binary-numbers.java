class Solution {
    public int concatenatedBinary(int n) {
        int bl = 0;
        final int MOD = (int)1e9 + 7;
        long ans = 0;
        int i = 1;
        while(i <= n) {
            if((i & (i - 1)) == 0) bl++;
            ans = ((ans << bl) | i) % MOD;
            ++i;
        }
        return (int)ans;
    }
}