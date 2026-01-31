class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int j = 0, ans = 0, sum = 0;
        for(int i = 0; i < fruits.size(); ++i) {
            mp[fruits[i]]++;
            sum++;
            while(mp.size() > 2) {
                mp[fruits[j]]--;
                sum--;
                if(mp[fruits[j]] == 0) mp.erase(mp.find(fruits[j]));
                j++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};