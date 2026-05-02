class Solution {
public:
    bool isGood(int n) {
        unordered_set<int> s;
        while(n) {
            s.insert(n % 10);
            n /= 10;
        }
        bool one = false, two = true;
        for(int i : s) {
            if(i == 2 || i == 5 || i == 6 || i == 9) one = true;
            if(i == 3 || i == 4 || i == 7) two = false;
        }
        return one && two;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) if(isGood(i)) ++ans;
        return ans;
    }
};