class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int d = s.size();
        int ans = 0;
        int unique = 9;      
        int available = 9; 
        for (int len = 1; len < d; ++len) {
            if (len == 1) {
                ans += 9;
            } 
            else {
                unique *= available;  
                ans += unique;
                available--;
            }
        }
        vector<bool> used(10, false);

        for(int i = 0; i < d; ++i) {
            int digit = s[i] - '0';

            for(int j = (i == 0 ? 1 : 0); j < digit; ++j) {
                if(used[j]) continue;
                int avail = 10 - (i + 1);
                int perm = 1;
                for(int k = i + 1; k < d; ++k) {
                    perm *= avail;
                    avail--;
                }
                ans += perm;
            }
            if(used[digit]) break;
            used[digit] = true;
            if(i == d - 1) ans++;
        }

        return n - ans;
    }
};