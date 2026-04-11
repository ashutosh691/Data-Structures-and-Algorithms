class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(auto i : nums) {
            string temp = to_string(i);
            ans += count(temp.begin(), temp.end(), (char)(digit + '0'));
        }
        return ans;
    }
};