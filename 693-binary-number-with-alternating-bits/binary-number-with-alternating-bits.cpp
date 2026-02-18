class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool curr = n & 1;
        n = n >> 1;
        while(n) {
            if((n & 1) == curr) return false;
            curr = !curr;
            n = n >> 1;
        }
        return true;
    }
};