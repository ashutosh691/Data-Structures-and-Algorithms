class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        vector<int> extra(60, 0);
        for(int i : time) {
            int r = i % 60;
            int c = (60 - r) % 60;
            ans += extra[c];
            extra[r]++;
        }
        return ans;
    }
};