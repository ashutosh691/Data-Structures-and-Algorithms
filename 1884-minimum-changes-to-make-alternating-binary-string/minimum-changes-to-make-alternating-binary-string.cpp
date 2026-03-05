class Solution {
public:
    int minOperations(string s) {
        int s0 = 0, n = s.size();
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0 && s[i] == '1') s0++;
            else if(i % 2 && s[i] == '0') s0++; 
        }
        return min(s0, (int) n - s0);
    }
};