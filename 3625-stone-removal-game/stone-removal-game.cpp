class Solution {
public:
    bool canAliceWin(int n) {
        int curr = 10;
        bool alice = false;
        while(n >= curr) {
            n -= curr;
            curr--;
            alice = !alice;
        }
        return alice;
    }
};