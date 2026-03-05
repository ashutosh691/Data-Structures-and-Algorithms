class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0, ans = 0;
        for(auto i : s) {
            if(i == 'L') balance--;
            else balance++;
            if(!balance) ans++;
        }
        return ans;
    }
};