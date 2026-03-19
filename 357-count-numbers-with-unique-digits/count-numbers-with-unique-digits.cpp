class Solution {
public:
    int ans = 0;

    void count(int len, int n, vector<int>& used) {
        if(len > n) return;
        if(len > 0) ans++; 
        for(int i = 0; i <= 9; ++i) {
            if(used[i]) continue;
            if(len == 0 && i == 0) continue;
            used[i] = 1;
            count(len + 1, n, used);
            used[i] = 0;
        }
    }

    int countNumbersWithUniqueDigits(int n) {
        vector<int> used(10, 0);
        count(0, n, used);
        return ans + 1; 
    }
};