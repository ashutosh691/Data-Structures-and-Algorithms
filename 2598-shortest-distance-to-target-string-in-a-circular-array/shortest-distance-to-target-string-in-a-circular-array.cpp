class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = INT_MAX;
        for(int i = 0; i < n; ++i) 
            if(words[i] == target) {
                int temp = abs(i - startIndex);
                ans = min(ans, min(temp, n - temp));
            }
        return ans == INT_MAX ? -1 : ans;
    }
};