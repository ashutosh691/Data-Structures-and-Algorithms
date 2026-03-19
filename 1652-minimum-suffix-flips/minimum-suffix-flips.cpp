class Solution {
public:
    int minFlips(string target) {
        int c = 0, n = target.size();
        string ans = string(n, '0');
        char curr = '0';
        for(int i = 0; i < n; ++i) {
            if(target[i] == curr) {
                ans[i] = curr;
                continue;
            }
            ++c;
            if(curr == '1') {
                ans[i] = '0';
                curr = '0';
            }
            else {
                ans[i] = '1';
                curr = '1';
            }
        }
        return c;
    }
};