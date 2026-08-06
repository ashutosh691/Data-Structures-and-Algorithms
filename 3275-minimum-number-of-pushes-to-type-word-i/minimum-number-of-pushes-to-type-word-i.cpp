class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26, 0);
        for(auto i : word) arr[i - 'a']++;
        int c = 8, ans = 0;
        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i < 26; ++i) ans += (arr[i] * ((c++) / 8));
        return ans;
    }
};