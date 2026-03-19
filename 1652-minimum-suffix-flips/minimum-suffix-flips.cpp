class Solution {
public:
    int minFlips(string target) {
        int c = 0, n = target.size();
        char curr = '0';
        for(int i = 0; i < n; ++i) {
            if(target[i] == curr) continue;
            ++c;
            if(curr == '1') curr = '0';
            else curr = '1';
        }
        return c;
    }
};